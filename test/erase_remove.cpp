#include <iostream>
#include <vector>

#include <ytl_algorithm.hpp>
#include <catch/catch_amalgamated.hpp>


TEST_CASE("Removing elements from vector")
{
    //Create a container with some data
    std::vector<int> vect(10);
    std::generate(std::begin(vect), std::end(vect),
            [a = 9] () mutable { return a--; });

    std::cout << "starting values: ";
    for(auto i : vect)
    {
        std::cout << i << " ";
    }
    std::cout << '\n';
    const size_t original_size {vect.size()};
    REQUIRE(std::find(std::begin(vect), std::end(vect), 2) != std::end(vect));
    REQUIRE(std::find(std::begin(vect), std::end(vect), 4) != std::end(vect));
    REQUIRE(std::find(std::begin(vect), std::end(vect), 6) != std::end(vect));

    ytl::erase_remove(vect, 2);
    std::cout << "erase_remove(vect, 2): ";
    ytl::print_container(vect);
    REQUIRE(vect.size() == original_size -1);

    ytl::erase_remove(vect, 4);
    std::cout << "erase_remove(vect, 4): ";
    ytl::print_container(vect);
    REQUIRE(vect.size() == original_size -2);

    ytl::erase_remove(vect, 6);
    std::cout << "erase_remove(vect, 6): ";
    ytl::print_container(vect);
    REQUIRE(vect.size() == original_size -3);

    REQUIRE(std::find(std::begin(vect), std::end(vect), 2) == std::end(vect));
    REQUIRE(std::find(std::begin(vect), std::end(vect), 4) == std::end(vect));
    REQUIRE(std::find(std::begin(vect), std::end(vect), 6) == std::end(vect));
}

TEST_CASE("Remofibn elements from vector with predicate")
{
    //Create a container with some data
    std::vector<int> vect(10);
    std::generate(std::begin(vect), std::end(vect),
            [a = 9] () mutable { return a--; });

    std::cout << "starting values: ";
    ytl::print_container(vect);

    REQUIRE(std::find(std::begin(vect), std::end(vect), 0) != std::end(vect));
    REQUIRE(std::find(std::begin(vect), std::end(vect), 2) != std::end(vect));
    REQUIRE(std::find(std::begin(vect), std::end(vect), 4) != std::end(vect));
    REQUIRE(std::find(std::begin(vect), std::end(vect), 6) != std::end(vect));
    REQUIRE(std::find(std::begin(vect), std::end(vect), 8) != std::end(vect));

    ytl::erase_remove_if(vect, [](const int& i){return !bool(i % 2);});
    std::cout << "after calling erase_remove_if to remove even numbers: ";
    ytl::print_container(vect);

    REQUIRE(std::find(std::begin(vect), std::end(vect), 0) == std::end(vect));
    REQUIRE(std::find(std::begin(vect), std::end(vect), 2) == std::end(vect));
    REQUIRE(std::find(std::begin(vect), std::end(vect), 4) == std::end(vect));
    REQUIRE(std::find(std::begin(vect), std::end(vect), 6) == std::end(vect));
    REQUIRE(std::find(std::begin(vect), std::end(vect), 8) == std::end(vect));
}
