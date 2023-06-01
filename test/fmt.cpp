#include "ytl_fmt.hpp"
#include <catch/catch_amalgamated.hpp>

#include <vector>
#include <string>

static std::vector<std::string> printed_text;

void sink(const char* msg)
{
	printed_text.push_back(msg);
}

TEST_CASE("custom fmt printer")
{
	printed_text.clear();

	ytl::fmt_sink testPrinter(sink);
	testPrinter("val={}", 42);

	REQUIRE(!printed_text.empty());
	REQUIRE(printed_text.back() == "val=42");
}