cmake_minimum_required(VERSION 3.25)
project(myContainers)

set(CMAKE_CXX_STANDARD 20)

add_executable(myContainers main.cpp my/unordered_map.h)
