#include <gtest/gtest.h>
#include "parameters.hpp"

TYPED_TEST_SUITE_P(VectorAccess);

TYPED_TEST(VectorAccess, SquareBrackets){
	VECTOR				v1;
	
	for (size_t i = 0; i < 100; i++)
		v1.push_back(i % 5 + 3);

	EXPECT_EQ(v1[0], 3);
	EXPECT_EQ(v1[1], 4);
	EXPECT_EQ(v1[5], 3);
	EXPECT_EQ(v1[15 - 2], 6);
	EXPECT_EQ(v1[31], 4);
	EXPECT_EQ(v1[50 + 3], 6);
	EXPECT_EQ(v1[67], 5);
	EXPECT_EQ(v1[89], 7);
	EXPECT_EQ(v1[97], 5);
}

TYPED_TEST(VectorAccess, At){
	VECTOR				v1;
	
	for (size_t i = 0; i < 100; i++)
		v1.push_back(i % 6 + 38);

	EXPECT_EQ(v1.at(6), 38);
	EXPECT_EQ(v1.at(11), 43);
	EXPECT_EQ(v1.at(14), 40);
	EXPECT_EQ(v1.at(18 + 12), 38);
	EXPECT_EQ(v1.at(51), 41);
	EXPECT_EQ(v1.at(56 - 1), 39);
	EXPECT_EQ(v1.at(73), 39);
	EXPECT_EQ(v1.at(88), 42);
	EXPECT_EQ(v1.at(98), 40);
}

TYPED_TEST(VectorAccess, Front){
	VECTOR				v1;
	
	for (size_t i = 0; i < 3; i++)
		v1.push_back(i + 15 * 30 / 22);

	EXPECT_EQ(v1.front(), 20);
}

TYPED_TEST(VectorAccess, Back){
	VECTOR				v1;
	
	for (size_t i = 0; i < 3; i++)
		v1.push_back(i + 13 * 30 / 22);

	EXPECT_EQ(v1.back(), 19);
}
