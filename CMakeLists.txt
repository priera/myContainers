cmake_minimum_required(VERSION 3.25)
project(myContainers)

set(CMAKE_CXX_STANDARD 20)

file(GLOB myContainers_SRC CONFIGURE_DEPENDS "*.h" "*.cpp")

add_executable(myContainers ${myContainers_SRC})
