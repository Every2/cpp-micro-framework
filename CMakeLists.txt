cmake_minimum_required(VERSION 3.12)
project(CPP_FRAMEWORK)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES
    src/http.cpp 
    src/main.cpp
    include/http.hpp
)

include_directories(include)

add_executable(CPP_FRAMEWORK ${SOURCES})