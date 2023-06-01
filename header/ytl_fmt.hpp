#pragma once
#include <cassert>
#include <format>

namespace ytl
{
	using print_function = void(*)(const char*);

	//Alias the template string type for compatibility bodges
#if _MSC_VER >= 1930 //TODO FIXFIX after visual studio actually expose format_string properly
#define __YTL_FORMAT_STRING  std::_Fmt_string
#else
#define __YTL_FORMAT_STRING  std::format_string<T>; 
#endif

	class fmt_sink
	{
		print_function print = nullptr;

	public:
		fmt_sink(print_function pfn): print(pfn)
		{
		}

		template <typename ... Args>
		void operator()(__YTL_FORMAT_STRING<Args...> fmt, Args ... args)
		{
			assert(nullptr != print);
			print(std::format(fmt, std::forward<Args>(args) ...).c_str());
		}
	};

#undef __YTL_FORMAT_STRING
}