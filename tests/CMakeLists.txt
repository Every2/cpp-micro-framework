cmake_minimum_required(VERSION 3.12)
project(CPP_FRAMEWORK_TESTS)

set(CMAKE_CXX_STANDARD 20)


include(GoogleTest)

set(SOURCES
    test.cpp
    ../include/http.hpp
    ../src/http.cpp
)

add_executable(CPP_FRAMEWORK_TESTS ${SOURCES})

target_link_libraries(CPP_FRAMEWORK_TESTS gtest gtest_main)

gtest_discover_tests(CPP_FRAMEWORK_TESTS)