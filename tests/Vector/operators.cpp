#include <gtest/gtest.h>
#include "parameters.hpp"

TYPED_TEST_SUITE_P(VectorOperators);

TYPED_TEST(VectorOperators, NonMember){
	VECTOR	v1(4);
	VECTOR	v2(4);
	
	EXPECT_TRUE(v1 == v2);
	EXPECT_TRUE(v1 == v1);

	v1.resize(23);

	EXPECT_FALSE(v1 == v2);
	EXPECT_TRUE(v1 != v2);
	
	v2.insert(v2.begin() + 2, 3, 12);
	
	EXPECT_TRUE(v1 <= v2);
	EXPECT_FALSE(v1 >= v2);
	EXPECT_TRUE(v1 < v2);
	EXPECT_FALSE(v1 > v2);
}

TYPED_TEST(VectorOperators, NonMemberSwap){
	VECTOR				v1(4);
	VECTOR				v2(4);

	v1.insert(v1.begin(), 4, 1);
	v2.insert(v2.begin(), 4, 2);

	VECTOR::iterator	it1 = v1.begin();
	VECTOR::iterator	it2 = v2.begin();

	EXPECT_EQ(*it1, 1);
	EXPECT_EQ(*it2, 2);
	EXPECT_EQ(*(v1.begin()), 1);
	EXPECT_EQ(*(v2.begin()), 2);	

	swap(v1, v2);
	
	EXPECT_EQ(*it1, 1);
	EXPECT_EQ(*it2, 2);
	EXPECT_EQ(*(v1.begin()), 2);
	EXPECT_EQ(*(v2.begin()), 1);	
}