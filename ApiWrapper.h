#pragma once
#include <windows.h>

template<typename Fty>
struct WinApiCallable;

template<typename Ret, typename ...Args>
struct WinApiCallable < Ret WINAPI(Args...) >
{
	typedef Ret WINAPI Fty(Args...);
	template<Fty F>
	struct Callable
	{
		Ret operator()(Args... args)
		{
			return F(args...);
		}
	};
};

#define WINAPI_CALLABLE(api) WinApiCallable<decltype(api)>::Callable<api>
