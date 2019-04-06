cmake_minimum_required(VERSION 3.12)

project(YTL)

set(CMAKE_CXX_STANDARD 17)

include_directories(
    ./header
    ./test
    )

file(GLOB TestCode CONFIGURE_DEPENDS ./test/*.cpp)

add_executable(YTL_test ${TestCode})

enable_testing()
add_test(NAME YTL_test COMMAND YTL_test)


