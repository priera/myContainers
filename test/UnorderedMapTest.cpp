#include <gtest/gtest.h>

#include "my/unordered_map.h"

TEST(UnorderedMapTest, NewMapIsEmpty) {
    my::unordered_map<int, int> emptyMap {};

    EXPECT_TRUE(emptyMap.empty());
    EXPECT_EQ(emptyMap.size(), 0);
}
