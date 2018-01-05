cmake_minimum_required(VERSION 3.6.3)

project(YTL)

set(CMAKE_CXX_STANDARD 14)

include_directories(
    ./header
    ./test
    )

file(GLOB TestCode ./test/*.cpp)

add_executable(YTL_test ${TestCode})

enable_testing()
add_test(NAME YTL_test COMMAND YTL_test)


