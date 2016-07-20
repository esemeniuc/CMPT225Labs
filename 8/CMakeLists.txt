cmake_minimum_required(VERSION 3.5)
project(8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES TestDriver.cpp ListADT.cpp Profile.cpp)
add_executable(8 ${SOURCE_FILES})