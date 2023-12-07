#include <ytl_types.hpp>
#include <catch/catch_amalgamated.hpp>


TEST_CASE("result good")
{
	const ytl::result<int, ytl::whatever> some_value = 42;
	REQUIRE(some_value.is_ok());
	REQUIRE(some_value.ok() == 42);
}

TEST_CASE("result error")
{
	const ytl::result<int, ytl::whatever> some_value = ytl::whatever("this is not good");
	REQUIRE(some_value.is_err());
	REQUIRE(0 == strcmp("this is not good", some_value.err().get()));
}

