#pragma once
#include <Windows.h>

#if !defined(_SHELL32_API_)
#if !defined(_SHELL32_DLL_)
#define _SHELL32_API_ DECLSPEC_IMPORT
#else
#define _SHELL32_API_
#endif
#endif

extern "C"{
	_SHELL32_API_ BOOL WINAPI GUIDFromStringA(
		_In_   LPCSTR psz,
		_Out_  LPGUID pguid
		);
	_SHELL32_API_ BOOL WINAPI GUIDFromStringW(
		_In_   LPCWSTR psz,
		_Out_  LPGUID pguid
		);
}