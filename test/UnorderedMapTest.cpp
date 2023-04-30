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

TEST(UnorderedMapTest, CannotInsertSameElementTwice) {
    SimpleMap simpleMap{};

    auto kvPair = SimpleMap::value_type {1, 2};
    bool insertionResult = simpleMap.insert(kvPair);

    EXPECT_FALSE(simpleMap.empty());
    EXPECT_TRUE(insertionResult);
    EXPECT_EQ(simpleMap.size(), 1);

    auto kvPair2 = SimpleMap::value_type {1, 45};
    insertionResult = simpleMap.insert(kvPair2);

    EXPECT_FALSE(simpleMap.empty());
    EXPECT_FALSE(insertionResult);
    EXPECT_EQ(simpleMap.size(), 1);
}

TEST(UnorderedMapTest, FindOnEmptyMapReturnsEnd) {
    SimpleMap map{};

    auto it = map.find(1);
    EXPECT_TRUE(map.empty());
    // it == endit; This still does not work
    EXPECT_TRUE(it.equalTo(map.end()));
}

/*TEST(UnorderedMapTest, FindReturnsExpectedData) {
    SimpleMap map {};

    auto it = emptyMap.find(1);
    EXPECT_TRUE(emptyMap.empty());
    EXPECT_EQ(emptyMap.size(), 0);
} */