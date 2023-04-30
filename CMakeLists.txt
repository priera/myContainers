cmake_minimum_required(VERSION 3.25)
project(myContainers CXX)

set(CMAKE_CXX_STANDARD 20)

enable_testing()

add_subdirectory(include/my)
add_subdirectory(test)
