cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 11)

project(DesignPattern)

add_subdirectory(CreationalPatterns/AbstractFactory)

add_subdirectory(BehavioralPatterns/Command)
add_subdirectory(BehavioralPatterns/State)