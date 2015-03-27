#pragma once
#include <Windows.h>

enum TAG : DWORD{
	TAG_TYPE_LIST = (0x7000),
	TAG_DATABASE = (0x1 | TAG_TYPE_LIST),//Database entry
	TAG_LIBRARY = (0x2 | TAG_TYPE_LIST),//Library entry
	TAG_INEXCLUDE = (0x3 | TAG_TYPE_LIST),//Include and exclude entry
	TAG_SHIM = (0x4 | TAG_TYPE_LIST),//Shim entry that contains the name and purpose information
	TAG_PATCH = (0x5 | TAG_TYPE_LIST),//Patch entry that contains the in-memory patching information
	TAG_APP = (0x6 | TAG_TYPE_LIST),//Application entry
	TAG_EXE = (0x7 | TAG_TYPE_LIST),//Executable entry
	TAG_MATCHING_FILE = (0x8 | TAG_TYPE_LIST),//Matching file entry
	TAG_SHIM_REF = (0x9 | TAG_TYPE_LIST),//Shim definition entry
	TAG_PATCH_REF = (0xA | TAG_TYPE_LIST),//Patch definition entry
	TAG_LAYER = (0xB | TAG_TYPE_LIST),//Layer shim entry
	TAG_FILE = (0xC | TAG_TYPE_LIST),//File attribute used in a shim entry
	TAG_APPHELP = (0xD | TAG_TYPE_LIST),//Apphelp information entry
	TAG_LINK = (0xE | TAG_TYPE_LIST),//Apphelp online link information entry
	TAG_DATA = (0xF | TAG_TYPE_LIST),//Name-value mapping entry
	TAG_MSI_TRANSFORM = (0x10 | TAG_TYPE_LIST),//MSI transformation entry
	TAG_MSI_TRANSFORM_REF = (0x11 | TAG_TYPE_LIST),//MSI transformation definition entry
	TAG_MSI_PACKAGE = (0x12 | TAG_TYPE_LIST),//MSI package entry
	TAG_FLAG = (0x13 | TAG_TYPE_LIST),//Flag entry
	TAG_MSI_CUSTOM_ACTION = (0x14 | TAG_TYPE_LIST),//MSI custom action entry
	TAG_FLAG_REF = (0x15 | TAG_TYPE_LIST),//Flag definition entry
	TAG_ACTION = (0x16 | TAG_TYPE_LIST),//Unused
	TAG_LOOKUP = (0x17 | TAG_TYPE_LIST),//Lookup entry used for lookup in a driver database
	TAG_STRINGTABLE = (0x801 | TAG_TYPE_LIST),//String table entry
	TAG_INDEXES = (0x802 | TAG_TYPE_LIST),//Indexes entry that defines all the indexes in a shim database
	TAG_INDEX = (0x803 | TAG_TYPE_LIST),//Index entry that defines an index in a shim database

	TAG_TYPE_STRINGREF = (0x6000),
	TAG_NAME = (0x1 | TAG_TYPE_STRINGREF),//Name attribute
	TAG_DESCRIPTION = (0x2 | TAG_TYPE_STRINGREF),//Description entry
	TAG_MODULE = (0x3 | TAG_TYPE_STRINGREF),//Module attribute
	TAG_API = (0x4 | TAG_TYPE_STRINGREF),//API entry
	TAG_VENDOR = (0x5 | TAG_TYPE_STRINGREF),//Vendor name attribute
	TAG_APP_NAME = (0x6 | TAG_TYPE_STRINGREF),//Application name attribute that describes an application entry in a shim database
	TAG_COMMAND_LINE = (0x8 | TAG_TYPE_STRINGREF),//Command line attribute that is used when passing arguments to a shim, for example
	TAG_COMPANY_NAME = (0x9 | TAG_TYPE_STRINGREF),//Company name attribute
	TAG_DLLFILE = (0xA | TAG_TYPE_STRINGREF),//DLL file attribute for a shim entry
	TAG_WILDCARD_NAME = (0xB | TAG_TYPE_STRINGREF),//Wildcard name attribute for an executable entry with a wildcard as the file name
	TAG_PRODUCT_NAME = (0x10 | TAG_TYPE_STRINGREF),//Product name attribute
	TAG_PRODUCT_VERSION = (0x11 | TAG_TYPE_STRINGREF),//Product version attribute
	TAG_FILE_DESCRIPTION = (0x12 | TAG_TYPE_STRINGREF),//File description attribute
	TAG_FILE_VERSION = (0x13 | TAG_TYPE_STRINGREF),//File version attribute
	TAG_ORIGINAL_FILENAME = (0x14 | TAG_TYPE_STRINGREF),//Original file name attribute
	TAG_INTERNAL_NAME = (0x15 | TAG_TYPE_STRINGREF),//Internal file name attribute
	TAG_LEGAL_COPYRIGHT = (0x16 | TAG_TYPE_STRINGREF),//Copyright attribute
	TAG_16BIT_DESCRIPTION = (0x17 | TAG_TYPE_STRINGREF),//16-bit description attribute
	TAG_APPHELP_DETAILS = (0x18 | TAG_TYPE_STRINGREF),//Apphelp details message information attribute
	TAG_LINK_URL = (0x19 | TAG_TYPE_STRINGREF),//Apphelp online link URL attribute
	TAG_LINK_TEXT = (0x1A | TAG_TYPE_STRINGREF),//Apphelp online link text attribute
	TAG_APPHELP_TITLE = (0x1B | TAG_TYPE_STRINGREF),//Apphelp title attribute
	TAG_APPHELP_CONTACT = (0x1C | TAG_TYPE_STRINGREF),//Apphelp vendor contact attribute
	TAG_SXS_MANIFEST = (0x1D | TAG_TYPE_STRINGREF),//Side-by-side manifest entry
	TAG_DATA_STRING = (0x1E | TAG_TYPE_STRINGREF),//String attribute for a data entry
	TAG_MSI_TRANSFORM_FILE = (0x1F | TAG_TYPE_STRINGREF),//File name attribute of an MSI transformation entry
	TAG_16BIT_MODULE_NAME = (0x20 | TAG_TYPE_STRINGREF),//16-bit module name attribute
	TAG_LAYER_DISPLAYNAME = (0x21 | TAG_TYPE_STRINGREF),//Unused
	TAG_COMPILER_VERSION = (0x22 | TAG_TYPE_STRINGREF),//Shim database compiler version
	TAG_ACTION_TYPE = (0x23 | TAG_TYPE_STRINGREF),//Unused
	TAG_EXPORT_NAME = (0x24 | TAG_TYPE_STRINGREF),//Export file name attribute

	TAG_TYPE_DWORD = (0x4000),
	TAG_SIZE = (0x1 | TAG_TYPE_DWORD),//File size attribute
	TAG_OFFSET = (0x2 | TAG_TYPE_DWORD),//Unused
	TAG_CHECKSUM = (0x3 | TAG_TYPE_DWORD),//File checksum attribute
	TAG_SHIM_TAGID = (0x4 | TAG_TYPE_DWORD),//Shim TAGID attribute
	TAG_PATCH_TAGID = (0x5 | TAG_TYPE_DWORD),//Patch TAGID attribute
	TAG_MODULE_TYPE = (0x6 | TAG_TYPE_DWORD),//Module type attribute
	TAG_VERDATEHI = (0x7 | TAG_TYPE_DWORD),//High-order portion of the file version date attribute
	TAG_VERDATELO = (0x8 | TAG_TYPE_DWORD),//Low-order portion of the file version date attribute
	TAG_VERFILEOS = (0x9 | TAG_TYPE_DWORD),//Operating system file version attribute
	TAG_VERFILETYPE = (0xA | TAG_TYPE_DWORD),//File type attribute
	TAG_PE_CHECKSUM = (0xB | TAG_TYPE_DWORD),//PE file checksum attribute
	TAG_PREVOSMAJORVER = (0xC | TAG_TYPE_DWORD),//Major operating system version attribute
	TAG_PREVOSMINORVER = (0xD | TAG_TYPE_DWORD),//Minor operating system version attribute
	TAG_PREVOSPLATFORMID = (0xE | TAG_TYPE_DWORD),//Operating system platform identifier attribute
	TAG_PREVOSBUILDNO = (0xF | TAG_TYPE_DWORD),//Operating system build number attribute
	TAG_PROBLEMSEVERITY = (0x10 | TAG_TYPE_DWORD),//Block attribute of an Apphelp entry This determines whether the application is hard or soft blocked
	TAG_LANGID = (0x11 | TAG_TYPE_DWORD),//Language identifier of an Apphelp entry
	TAG_VER_LANGUAGE = (0x12 | TAG_TYPE_DWORD),//Language version attribute of a file
	TAG_ENGINE = (0x14 | TAG_TYPE_DWORD),//Unused
	TAG_HTMLHELPID = (0x15 | TAG_TYPE_DWORD),//Help identifier attribute for an Apphelp entry
	TAG_INDEX_FLAGS = (0x16 | TAG_TYPE_DWORD),//Flags attribute for an index entry
	TAG_FLAGS = (0x17 | TAG_TYPE_DWORD),//Flags attribute for an Apphelp entry
	TAG_DATA_VALUETYPE = (0x18 | TAG_TYPE_DWORD),//Data type attribute for a data entry
	TAG_DATA_DWORD = (0x19 | TAG_TYPE_DWORD),//DWORD value attribute for a data entry
	TAG_LAYER_TAGID = (0x1A | TAG_TYPE_DWORD),//Layer shim TAGID attribute
	TAG_MSI_TRANSFORM_TAGID = (0x1B | TAG_TYPE_DWORD),//MSI transform TAGID attribute
	TAG_LINKER_VERSION = (0x1C | TAG_TYPE_DWORD),//Linker version attribute of a file
	TAG_LINK_DATE = (0x1D | TAG_TYPE_DWORD),//Link date attribute of a file
	TAG_UPTO_LINK_DATE = (0x1E | TAG_TYPE_DWORD),//Link date attribute of a file Matching is done up to and including this link date
	TAG_OS_SERVICE_PACK = (0x1F | TAG_TYPE_DWORD),//Operating system service pack attribute for an executable entry
	TAG_FLAG_TAGID = (0x20 | TAG_TYPE_DWORD),//Flags TAGID attribute
	TAG_RUNTIME_PLATFORM = (0x21 | TAG_TYPE_DWORD),//Run-time platform attribute of a file
	TAG_OS_SKU = (0x22 | TAG_TYPE_DWORD),//Operating system SKU attribute for an executable entry
	TAG_OS_PLATFORM = (0x23 | TAG_TYPE_DWORD),//Operating system platform attribute
	TAG_APP_NAME_RC_ID = (0x24 | TAG_TYPE_DWORD),//Application name resource identifier attribute for Apphelp entries
	TAG_VENDOR_NAME_RC_ID = (0x25 | TAG_TYPE_DWORD),//Vendor name resource identifier attribute for Apphelp entries
	TAG_SUMMARY_MSG_RC_ID = (0x26 | TAG_TYPE_DWORD),//Summary message resource identifier attribute for Apphelp entries
	TAG_VISTA_SKU = (0x27 | TAG_TYPE_DWORD),//Windows Vista SKU attribute
	TAG_DESCRIPTION_RC_ID = (0x28 | TAG_TYPE_DWORD),//Description resource identifier attribute for Apphelp entries
	TAG_PARAMETER1_RC_ID = (0x29 | TAG_TYPE_DWORD),//Parameter1 resource identifier attribute for Apphelp entries
	TAG_TAGID = (0x801 | TAG_TYPE_DWORD),//TAGID attribute

	TAG_TYPE_STRING = (0x8000),
	TAG_STRINGTABLE_ITEM = (0x801 | TAG_TYPE_STRING),//String table item entry

	TAG_TYPE_NULL = (0x1000),
	TAG_INCLUDE = (0x1 | TAG_TYPE_NULL),//Include list entry
	TAG_GENERAL = (0x2 | TAG_TYPE_NULL),//General purpose shim entry
	TAG_MATCH_LOGIC_NOT = (0x3 | TAG_TYPE_NULL),//NOT of matching logic entry
	TAG_APPLY_ALL_SHIMS = (0x4 | TAG_TYPE_NULL),//Unused
	TAG_USE_SERVICE_PACK_FILES = (0x5 | TAG_TYPE_NULL),//Service pack information for Apphelp entries
	TAG_MITIGATION_OS = (0x6 | TAG_TYPE_NULL),//Mitigation at operating system scope entry
	TAG_BLOCK_UPGRADE = (0x7 | TAG_TYPE_NULL),//Upgrade block entry
	TAG_INCLUDEEXCLUDEDLL = (0x8 | TAG_TYPE_NULL),//DLL include/exclude entry

	TAG_TYPE_QWORD = (0x5000),
	TAG_TIME = (0x1 | TAG_TYPE_QWORD),//Time attribute
	TAG_BIN_FILE_VERSION = (0x2 | TAG_TYPE_QWORD),//Bin file version attribute for file entries
	TAG_BIN_PRODUCT_VERSION = (0x3 | TAG_TYPE_QWORD),//Bin product version attribute for file entries
	TAG_MODTIME = (0x4 | TAG_TYPE_QWORD),//Unused
	TAG_FLAG_MASK_KERNEL = (0x5 | TAG_TYPE_QWORD),//Kernel flag mask attribute
	TAG_UPTO_BIN_PRODUCT_VERSION = (0x6 | TAG_TYPE_QWORD),//Bin product version attribute of a file Matching is done up to and including this product version
	TAG_DATA_QWORD = (0x7 | TAG_TYPE_QWORD),//ULONGLONG value attribute for a data entry
	TAG_FLAG_MASK_USER = (0x8 | TAG_TYPE_QWORD),//User flag mask attribute
	TAG_FLAGS_NTVDM1 = (0x9 | TAG_TYPE_QWORD),//NTVDM1 flag mask attribute
	TAG_FLAGS_NTVDM2 = (0xA | TAG_TYPE_QWORD),//NTVDM2 flag mask attribute
	TAG_FLAGS_NTVDM3 = (0xB | TAG_TYPE_QWORD),//NTVDM3 flag mask attribute
	TAG_FLAG_MASK_SHELL = (0xC | TAG_TYPE_QWORD),//Shell flag mask attribute
	TAG_UPTO_BIN_FILE_VERSION = (0xD | TAG_TYPE_QWORD),//Bin file version attribute of a file Matching is done up to and including this file version
	TAG_FLAG_MASK_FUSION = (0xE | TAG_TYPE_QWORD),//Fusion flag mask attribute
	TAG_FLAG_PROCESSPARAM = (0xF | TAG_TYPE_QWORD),//Process param flag attribute
	TAG_FLAG_LUA = (0x10 | TAG_TYPE_QWORD),//LUA flag attribute
	TAG_FLAG_INSTALL = (0x11 | TAG_TYPE_QWORD),//Install flag attribute

	TAG_TYPE_BINARY = (0x9000),
	TAG_PATCH_BITS = (0x2 | TAG_TYPE_BINARY),//Patch file bits attribute
	TAG_FILE_BITS = (0x3 | TAG_TYPE_BINARY),//File bits attribute
	TAG_EXE_ID = (0x4 | TAG_TYPE_BINARY),//GUID attribute of an executable entry
	TAG_DATA_BITS = (0x5 | TAG_TYPE_BINARY),//Data bits attribute
	TAG_MSI_PACKAGE_ID = (0x6 | TAG_TYPE_BINARY),//MSI package identifier attribute of an MSI package
	TAG_DATABASE_ID = (0x7 | TAG_TYPE_BINARY),//GUID attribute of a database
	TAG_APP_ID = (0x11 | TAG_TYPE_BINARY),//APP_ID
	TAG_INDEX_BITS = (0x801 | TAG_TYPE_BINARY),//Index bits attribute

	TAG_TYPE_WORD = (0x3000),
	TAG_MATCH_MODE = (0x1 | TAG_TYPE_WORD),//Match mode attribute
	TAG_TAG = (0x801 | TAG_TYPE_WORD),//TAG entry
	TAG_INDEX_TAG = (0x802 | TAG_TYPE_WORD),//Index TAG attribute for an index entry
	TAG_INDEX_KEY = (0x803 | TAG_TYPE_WORD),//Index key attribute for an index entry

	TAG_TYPE_MASK = 0 - DWORD(0x1000U),
	TAG_TYPE_INVALID = 0 - DWORD(1)
};

typedef DWORD TAGID;
typedef DWORD TAGREF;
typedef PVOID PDB; 
typedef DWORD INDEXID; 
#define INDEXID_NULL ((INDEXID)-1)
#define TAGID_NULL (0)
#define TAGID_ROOT (0)

typedef enum _PATH_TYPE { 
DOS_PATH,
NT_PATH
} PATH_TYPE;

#if !defined(APP_HELP_API)
#if !defined(_APP_HELP_)
#define APP_HELP_API DECLSPEC_IMPORT
#else
#define APP_HELP_API
#endif
#endif

extern "C"{
	APP_HELP_API BOOL WINAPI SdbStartIndexing(
		_In_  PDB pdb,
		_In_  INDEXID iiWhich
		);
	APP_HELP_API BOOL WINAPI SdbStopIndexing(
		_In_  PDB pdb,
		_In_  INDEXID iiWhich
		);
	APP_HELP_API BOOL WINAPI SdbCommitIndexes(
		_Inout_  PDB pdb
		); 
	APP_HELP_API BOOL WINAPI SdbDeclareIndex(
		_In_   PDB pdb,
		_In_   TAG tWhich,
		_In_   TAG tKey,
		_In_   DWORD dwEntries,
		_In_   BOOL bUniqueKey,
		_Out_  INDEXID *piiIndex
		);
	APP_HELP_API BOOL WINAPI SdbWriteBinaryTag(
		_In_  PDB pdb,
		_In_  TAG tTag,
		_In_  PBYTE pBuffer,
		_In_  DWORD dwSize
		);
	APP_HELP_API BOOL WINAPI SdbWriteDWORDTag(
		_In_  PDB pdb,
		_In_  TAG tTag,
		_In_  DWORD dwData
		); 
	APP_HELP_API BOOL WINAPI SdbWriteNULLTag(
		_In_  PDB pdb,
		_In_  TAG tTag
		); 
	APP_HELP_API BOOL WINAPI SdbWriteQWORDTag(
		_In_  PDB pdb,
		_In_  TAG tTag,
		_In_  ULONGLONG qwData
		); 
	APP_HELP_API BOOL WINAPI SdbWriteStringTag(
		_In_  PDB pdb,
		_In_  TAG tTag,
		_In_  LPCWSTR pwszData
		); 
	APP_HELP_API BOOL WINAPI SdbWriteWORDTag(
		_In_  PDB pdb,
		_In_  TAG tTag,
		_In_  WORD wData
		);
	APP_HELP_API BOOL WINAPI SdbReadBinaryTag(
		_In_   PDB pdb,
		_In_   TAGID tiWhich,
		_Out_  PBYTE pBuffer,
		_In_   DWORD dwBufferSize
		);
	APP_HELP_API DWORD WINAPI SdbReadDWORDTag(
		_In_  PDB pdb,
		_In_  TAGID tiWhich,
		_In_  DWORD dwDefault
		);
	APP_HELP_API WORD WINAPI SdbReadWORDTag(
		_In_  PDB pdb,
		_In_  TAGID tiWhich,
		_In_  WORD wDefault
		);
	APP_HELP_API ULONGLONG WINAPI SdbReadQWORDTag(
		_In_  PDB pdb,
		_In_  TAGID tiWhich,
		_In_  ULONGLONG qwDefault
		);
	APP_HELP_API BOOL WINAPI SdbReadStringTag(
		_In_   PDB pdb,
		_In_   TAGID tiWhich,
		_Out_  LPTSTR pwszBuffer,
		_In_   DWORD cchBufferSize
		);
	APP_HELP_API TAGID WINAPI SdbGetIndex(
		_In_       PDB pdb,
		_In_       TAG tWhich,
		_In_       TAG tKey,
		_Out_opt_  LPDWORD lpdwFlags
		);
	APP_HELP_API TAGID WINAPI SdbGetFirstChild(
		_In_  PDB pdb,
		_In_  TAGID tiParent
		);
	APP_HELP_API TAGID WINAPI SdbGetNextChild(
		_In_  PDB pdb,
		_In_  TAGID tiParent,
		_In_  TAGID tiPrev
		);
	APP_HELP_API TAGID WINAPI SdbFindFirstTag(
		_In_  PDB pdb,
		_In_  TAGID tiParent,
		_In_  TAG tTag
		);
	APP_HELP_API TAGID WINAPI SdbFindNextTag(
		_In_  PDB pdb,
		_In_  TAGID tiParent,
		_In_  TAGID tiPrev
		);
	APP_HELP_API PDB WINAPI SdbCreateDatabase(
		_In_  LPCWSTR pwszPath,
		_In_  PATH_TYPE eType
		);
	APP_HELP_API void WINAPI SdbCloseDatabase(
		_Inout_  PDB pdb
		); 
	APP_HELP_API TAGID WINAPI SdbBeginWriteListTag(
		_In_  PDB pdb,
		_In_  TAG tTag
		);
	APP_HELP_API BOOL WINAPI SdbEndWriteListTag(
		_Inout_  PDB pdb,
		_In_     TAGID tiList
		); 
	APP_HELP_API void WINAPI SdbCloseDatabaseWrite(
		_Inout_  PDB pdb
		);
}