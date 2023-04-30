cmake_minimum_required(VERSION 3.25)
project(myContainers CXX)

set(CMAKE_CXX_STANDARD 20)


include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_subdirectory(include/my)
add_subdirectory(test)
