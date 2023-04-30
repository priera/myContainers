add_executable(UnorderedMapTest UnorderedMapTest.cpp)

include_directories("../include")
target_link_libraries(UnorderedMapTest
        PRIVATE my GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(UnorderedMapTest)