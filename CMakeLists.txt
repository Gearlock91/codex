cmake_minimum_required(VERSION 4.1)
project(codex)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
)
FetchContent_MakeAvailable(googletest)

add_library(codex INTERFACE)
target_include_directories(codex INTERFACE include)

add_executable(codex_tests tests/str_test.cpp)
target_link_libraries(codex_tests PRIVATE codex GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(codex_tests)