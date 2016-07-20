cmake_minimum_required(VERSION 3.5)
project(7)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Lab7App.cpp Event.cpp Queue.cpp EmptyDataCollectionException.cpp)
add_executable(7 ${SOURCE_FILES})