add_executable(UnorderedMapTest UnorderedMapTest.cpp)

include_directories("../include")
target_link_libraries(UnorderedMapTest PRIVATE my)

add_test(NAME UnorderedMapTest
        COMMAND UnorderedMapTest)