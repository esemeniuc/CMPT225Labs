cmake_minimum_required(VERSION 3.5)
project(1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES testcirc2.cpp circle.cpp circle.h)
add_executable(1 ${SOURCE_FILES})