cmake_minimum_required(VERSION 3.5)
project(6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp merge_sort.cpp)
add_executable(6 ${SOURCE_FILES})