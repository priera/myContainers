#include <gtest/gtest.h>

#include "my/unordered_map.h"

using SimpleMap = my::unordered_map<int, int>;

TEST(UnorderedMapTest, NewMapIsEmpty) {
    SimpleMap emptyMap {};

    EXPECT_TRUE(emptyMap.empty());
    EXPECT_EQ(emptyMap.size(), 0);
}

TEST(UnorderedMapTest, InsertSingleElementSuccessful) {
    SimpleMap emptyMap {};

    auto kvPair = SimpleMap::value_type {1, 2};
    const bool insertionResult = emptyMap.insert(kvPair);

    EXPECT_FALSE(emptyMap.empty());
    EXPECT_TRUE(insertionResult);
    EXPECT_EQ(emptyMap.size(), 1);
}
