cmake_minimum_required(VERSION 3.29)
project(circle_point_casestudy)

set(CMAKE_CXX_STANDARD 20)

add_executable(circle_point_casestudy main.cpp
        Point.h
        Point.cpp
        Circle.h
        Circle.cpp
        Rectangle.h
        Rectangle.cpp)
