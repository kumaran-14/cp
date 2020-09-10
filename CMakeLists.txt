cmake_minimum_required(VERSION 3.15)
project(cp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_COMPILER /usr/bin/g++)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g -O1")
#
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

add_executable(cp test.cpp)