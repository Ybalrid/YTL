#include <ytl_memory.hpp>

#include <iostream>
#include <memory>
#include <catch/catch_amalgamated.hpp>

TEST_CASE("observer_ptr is null by default")
{
	ytl::observer_ptr<int> ptr;

	REQUIRE(ptr == nullptr);
}

TEST_CASE("create obsever_ptr from unique_ptr()")
{
	std::unique_ptr<int> my_int = std::make_unique<int>(42);
	ytl::observer_ptr int_ptr(my_int);

	REQUIRE(my_int.get() == int_ptr.get());
}

TEST_CASE("create observer_ptr from shared_ptr()")
{
	std::shared_ptr<int> my_int = std::make_shared<int>(42);
	ytl::observer_ptr int_ptr(my_int);

	REQUIRE(my_int.get() == int_ptr.get());
}

TEST_CASE("create observer_ptr from naked ptr()")
{
	int some_int = 42;
	int* my_int = &some_int;
	ytl::observer_ptr int_ptr(my_int);

	REQUIRE(my_int == int_ptr);
}

TEST_CASE("dereference operator of observer_ptr")
{
	auto my_int = 			std::make_unique<int>(42);
	ytl::observer_ptr int_ptr(my_int);

	REQUIRE(*int_ptr == *my_int);
}

int use_int_ptr(int* ptr)
{
	return *ptr/2;
}

TEST_CASE("implicit convertion to naked ptr")
{
	std::shared_ptr<int> my_int = std::make_shared<int>(42);
	REQUIRE(use_int_ptr(ytl::observer_ptr(my_int)) == 42 / 2);
}

