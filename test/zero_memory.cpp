#include <ytl_memory.hpp>
#include <catch/catch_amalgamated.hpp>

TEST_CASE("zero a region of memory")
{
	int v = 42;
	ytl::zero_memory(&v);
	REQUIRE(v == 0);
	struct obj
	{
		int a = 1, b = 2, c = 3;
	};

	obj o;
	REQUIRE_FALSE((o.a == 0 && o.b == 0 && o.c == 0));
	ytl::zero_memory(&o);
	REQUIRE((o.a == 0 && o.b == 0 && o.c == 0));
}