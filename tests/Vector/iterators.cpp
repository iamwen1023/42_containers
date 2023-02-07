#include <gtest/gtest.h>
#include "parameters.hpp"

TYPED_TEST_SUITE_P(VectorIterators);

TYPED_TEST(VectorIterators, Increment){
	VECTOR				v1(5);
	VECTOR::iterator	it = v1.begin();
	
	for (int i = 0; i < v1.size(); i++, it++)
		*it = i;
	EXPECT_EQ(v1.size(), 5);

	it = v1.begin();

	EXPECT_EQ(*++it, 1);
	EXPECT_EQ(*it++, 1);
	EXPECT_EQ(*it, 2);

	it += 1;
	
	EXPECT_EQ(*it, 3);
	
	it = it + 1;
	
	EXPECT_EQ(*it, 4);
}

TYPED_TEST(VectorIterators, Decrement){
	VECTOR				v1(5);
	VECTOR::iterator	it = v1.end() - 1;

	for (int i = v1.size(); i; i--, it--)
		*it = i;
	EXPECT_EQ(v1.size(), 5);

	it = v1.end() - 1;

	EXPECT_EQ(*--it, 4);
	EXPECT_EQ(*it--, 4);
	EXPECT_EQ(*it, 3);

	it -= 1;
	
	EXPECT_EQ(*it, 2);
	
	it = it - 1;
	
	EXPECT_EQ(*it, 1);
}

TYPED_TEST(VectorIterators, SquareBrackets){
	VECTOR				v1(15);
	VECTOR::iterator	it;
	VECTOR::iterator	it2;
	
	it	= v1.begin();
	for (int i = 0; i < 15; i++, it++)
		*it = i;

	it2 = v1.begin();
	it2[2] = 109;
	
	EXPECT_EQ(v1[2], 109);
}

TYPED_TEST(VectorIterators, NonMember){
	VECTOR				v1(5);
	VECTOR::iterator	it = v1.begin();
	
	for (int i = 0; i < v1.size(); i++, it++)
		*it = i;
	EXPECT_EQ(v1.size(), 5);
	
	VECTOR::iterator	it1 = v1.begin();
	VECTOR::iterator	it2 = v1.begin() + 2;
	VECTOR::iterator	it3 = v1.end() - 1;

	EXPECT_TRUE((it1 + 2) == it2);
	EXPECT_FALSE((it1 + 1) == it2);
	EXPECT_TRUE(it1 < it3);
	EXPECT_FALSE(it2 <= it1);
	EXPECT_FALSE(it1 > it3);
	EXPECT_TRUE(it2 >= (it1 + 2));
	EXPECT_FALSE(it2 != (it1 + 2));
}

TYPED_TEST(VectorIterators, NonMemberConst){
	VECTOR				v1(5);
	VECTOR::iterator	it = v1.begin();
	
	for (int i = 0; i < v1.size(); i++, it++)
		*it = i;
	EXPECT_EQ(v1.size(), 5);
	
	VECTOR::iterator		it1 = v1.begin();
	VECTOR::iterator const 	it2 = v1.begin() + 2;
	VECTOR::iterator		it3 = v1.end() - 1;

	EXPECT_TRUE((it1 + 2) == it2);
	EXPECT_FALSE((it1 + 1) == it2);
	EXPECT_TRUE(it1 < it3);
	EXPECT_FALSE(it2 <= it1);
	EXPECT_FALSE(it1 > it3);
	EXPECT_TRUE(it2 >= (it1 + 2));
	EXPECT_FALSE(it2 != (it1 + 2));
}