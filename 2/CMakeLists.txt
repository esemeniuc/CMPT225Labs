cmake_minimum_required(VERSION 3.5)
project(2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp sum_array.cpp sum_array.h)
add_executable(2 ${SOURCE_FILES})