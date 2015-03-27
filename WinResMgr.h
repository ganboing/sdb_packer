#pragma once
#include "ApiWrapper.h"
#include "ApiEHWrapper.h"
#include <memory>

typedef WINAPI_CALLABLE(CloseHandle) _HANDLE_Deleter;
typedef WINAPI_CALLABLE(UnmapViewOfFile) _SECTION_Unmapper;

typedef ::std::unique_ptr<FILE, _HANDLE_Deleter> ManagedFile;
typedef ::std::unique_ptr<void, _HANDLE_Deleter> ManagedHANDLE;
typedef ::std::unique_ptr<void, _SECTION_Unmapper> ManagedView;
