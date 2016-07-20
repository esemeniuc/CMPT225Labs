cmake_minimum_required(VERSION 3.5)
project(9)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES BankSimApp.cpp Event.cpp Node.cpp PQueue.cpp Queue.cpp)
add_executable(9 ${SOURCE_FILES})