cmake_minimum_required(VERSION 3.15)
project(cp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER /usr/bin/g++)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g -O1")
#
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
include_directories(os)

add_executable(cp test.cpp)
add_executable(lca_binary_lifting cpp/Algorithms/Tree/lca_binary_lifting.cpp)
#add_executable(BIT "cpp/Data Structures/Fenwick Tree/BIT.cpp")
add_executable(tele tele.cpp)
add_executable(temp2 temp2.cpp)
