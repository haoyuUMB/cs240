//
// Created by haoyu on 3/1/2023.
//
#include <gtest/gtest.h>
#include <cs240/utils.h>

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
    // Expect two strings not to be equal.
    EXPECT_STRNE("hello", "world");
    // Expect equality.
    EXPECT_EQ(7 * 6, 42);
    EXPECT_EQ(2, max(2, 1));

}