cmake_minimum_required(VERSION 3.5)
project(5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES test_cout.cpp Fraction.cpp)
add_executable(5 ${SOURCE_FILES})