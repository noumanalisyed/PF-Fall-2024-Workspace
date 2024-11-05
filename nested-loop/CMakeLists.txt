cmake_minimum_required(VERSION 3.29)
project(nested_loop)

set(CMAKE_CXX_STANDARD 20)

add_executable(nested_loop main.cpp
        triangle.cpp
        triangle2.cpp)
