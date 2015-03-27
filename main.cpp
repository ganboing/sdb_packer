#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <memory>
#include <codecvt>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/tokenizer.hpp>
#include "apphelp.hpp"
#include "shell32.h"
#include "WinResMgr.h"
#include "ApiEHWrapper.h"

#pragma comment(lib, "apphelp.lib")
#pragma comment(lib, "shell32.lib")

GEN_WINAPI_EH_STATUS(TRUE, SdbEndWriteListTag);
GEN_WINAPI_EH_RESULT(TAGID_NULL, SdbBeginWriteListTag); 
GEN_WINAPI_EH_RESULT(NULL, SdbCreateDatabase);
GEN_WINAPI_EH_STATUS(TRUE, SdbWriteDWORDTag);
GEN_WINAPI_EH_STATUS(TRUE, SdbWriteWORDTag);
GEN_WINAPI_EH_STATUS(TRUE, SdbWriteQWORDTag);
GEN_WINAPI_EH_STATUS(TRUE, SdbWriteStringTag);
GEN_WINAPI_EH_STATUS(TRUE, SdbWriteBinaryTag);
GEN_WINAPI_EH_STATUS(TRUE, SdbWriteNULLTag);
GEN_WINAPI_EH_STATUS(TRUE, GUIDFromStringA); 
GEN_WINAPI_EH_STATUS(TRUE, SdbCommitIndexes);
GEN_WINAPI_EH_STATUS(TRUE, SdbDeclareIndex);
GEN_WINAPI_EH_STATUS(TRUE, SdbStartIndexing);
GEN_WINAPI_EH_STATUS(TRUE, SdbStopIndexing);
GEN_WINAPI_EH_RESULT(0, SystemTimeToFileTime);

typedef WINAPI_CALLABLE(SdbCloseDatabaseWrite) _SDB_WRITE_CLOSER;
typedef ::std::unique_ptr<void, _SDB_WRITE_CLOSER> ManagedPDB;

//GEN_WINAPI_EH_STATUS(TRUE, GUIDFromString);

struct TagNode{
	TagNode* const parent;
	TAG const tag;
	TAGID const tagid;
	std::vector<std::unique_ptr<TagNode>> children;
	TagNode(TagNode* _p, TAG _tag, TAGID _tid) :
		parent(_p), tag(_tag), tagid(_tid)
	{}
};

template<typename T>
T* follow_path(T* node, const std::string& path){
	boost::char_separator<char> sep("/");
	boost::tokenizer<decltype(sep)> dirs(path, sep);
	for (auto i = dirs.begin(), j = dirs.end(); i != j; ++i){
		if (*i == ".."){
			node = node->parent;
		}
		else{
			node = &*node->children[stoul(*i)];
		}
	}
	return node;
}

struct enter_tag_list{
	const PDB sdb;
	const TAGID tagid;
	enter_tag_list(PDB _sdb, TAG tag):
		sdb(_sdb),
		tagid(EH_SdbBeginWriteListTag(sdb, tag))
	{}
	~enter_tag_list(){
		EH_SdbEndWriteListTag(sdb, tagid);
	}
};

typedef boost::property_tree::ptree::iterator bppit;

void compile_sdb_internal(TagNode* dir, PDB sdb, bppit begin, bppit end){
	for (auto i = begin; i != end; ++i)
	{
		auto t_s = i->first;
		auto t = FindTagByStr(i->first);
		if (t == TAG_TYPE_INVALID){
			throw std::runtime_error("invalid tag");
		}
		switch (t & TAG_TYPE_MASK){
		case TAG_TYPE_LIST:{
			enter_tag_list l(sdb, t);
			dir->children.push_back(std::make_unique<TagNode>(dir, t, l.tagid));
			compile_sdb_internal(dir->children.back().get(), sdb, i->second.begin(), i->second.end());
			break;
		}
		case TAG_TYPE_WORD:{
			WORD w;
			w = (WORD)stoul(i->second.data());
			EH_SdbWriteWORDTag(sdb, t, w);
			break;
		}
		case TAG_TYPE_DWORD:{
			DWORD d;
			if (t == TAG_SHIM_TAGID || t == TAG_PATCH_TAGID || t == TAG_FLAG_TAGID || t == TAG_LAYER_TAGID){
				d = follow_path(dir, i->second.data())->tagid;
			}
			else{
				d = (DWORD)stoul(i->second.data());
			}
			EH_SdbWriteDWORDTag(sdb, t, d);
			break;
		}
		case TAG_TYPE_QWORD:{
			ULONGLONG q;
			if (t == TAG_TIME){
				SYSTEMTIME time{};
				FILETIME file_time;
				unsigned long nano100;
				if (sscanf(i->second.data().c_str(), "%hu-%hu-%hu-%hu:%hu:%hu:%lu",
					&time.wYear, &time.wMonth, &time.wDay, 
					&time.wHour, &time.wMinute, &time.wSecond, &nano100) != 7){
					throw std::runtime_error("tim format invalid");
				}
				EH_SystemTimeToFileTime(&time, &file_time);
				memcpy(&q, &file_time, sizeof(q));
				q += nano100;
			}
			else{
				q = (ULONGLONG)stoull(i->second.data());
			}
			EH_SdbWriteQWORDTag(sdb, t, q);
			break;
		}
		case TAG_TYPE_STRINGREF:{
			std::wstring_convert<std::codecvt<wchar_t, char, std::mbstate_t>> conv;
			std::wstring s = conv.from_bytes(i->second.data());
			EH_SdbWriteStringTag(sdb, t, s.c_str());
			break;
		}
		case TAG_TYPE_BINARY:{
			std::vector<BYTE> d;
			if (t == TAG_EXE_ID || t == TAG_MSI_PACKAGE_ID || t == TAG_DATABASE_ID || t == TAG_APP_ID){
				GUID id;
				EH_GUIDFromStringA(i->second.data().c_str(), &id);
				d.insert(d.end(), (PBYTE)&id, (PBYTE)(&id+1));
			}
			else{
				for (size_t p = 0, q = i->second.data().size(); p < q; p += 2){
					d.push_back((BYTE)stoul(i->second.data().substr(p, 2)));
				}
			}
			EH_SdbWriteBinaryTag(sdb, t, d.data(), d.size());
			break;
		}
		case TAG_TYPE_NULL:{
			EH_SdbWriteNULLTag(sdb, t);
			break;
		}
		default:
			std::cerr << "tag of type " << i->first << " not implemented\n";
			__debugbreak();
		}
	}
}

void create_db(boost::property_tree::ptree& ptree, char* dest){
	auto tag_tree(std::make_unique<TagNode>(nullptr, TAG_TYPE_LIST, 0));
	std::wstring_convert<std::codecvt<wchar_t, char, std::mbstate_t>> conv;
	std::wstring path = conv.from_bytes(dest);
	ManagedPDB sdb(EH_SdbCreateDatabase(path.c_str(), DOS_PATH));
	compile_sdb_internal(tag_tree.get(), sdb.get(), ptree.begin(), ptree.end());
}

int main(int, char** argv)
try{
	std::ifstream input(argv[1]);
	boost::property_tree::ptree ptree;
	boost::property_tree::xml_parser::read_xml(input, ptree);
	create_db(ptree, argv[2]);
}
catch (std::exception& e){
	std::cerr << e.what();
}