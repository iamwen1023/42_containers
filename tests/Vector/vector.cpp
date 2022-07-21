#include "gtest/gtest.h"

TEST(WenTest, IsOneEqualOne) {
    int i = 0;

    i++;
    i++;
    EXPECT_EQ(i, 1);
}