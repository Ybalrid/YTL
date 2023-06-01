#pragma once
#include <cassert>
#include <format>

namespace ytl
{
	using print_function = void(*)(const char*);

	class fmt_sink
	{
		print_function print = nullptr;

	public:
		fmt_sink(print_function pfn): print(pfn)
		{
		}

		template <typename ... Args>
		void operator()(std::format_string<Args...> fmt, Args ... args)
		{
			assert(nullptr != print);
			print(std::format(fmt, std::forward<Args>(args) ...).c_str());
		}
	};
}