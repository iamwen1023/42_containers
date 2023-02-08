#include <gtest/gtest.h>
#include "parameters.hpp"

TYPED_TEST_SUITE_P(VectorReverseIterators);

TYPED_TEST(VectorReverseIterators, Increment){
	VECTOR						v1(5);
	VECTOR::reverse_iterator	rit = v1.rbegin();
	
	for (int i = 0; i < v1.size(); i++, rit++)
		*rit = i;
	EXPECT_EQ(v1.size(), 5);

	rit = v1.rbegin();

	EXPECT_EQ(*++rit, 1);
	EXPECT_EQ(*rit++, 1);
	EXPECT_EQ(*rit, 2);

	rit += 1;
	
	EXPECT_EQ(*rit, 3);
	
	rit = rit + 1;
	
	EXPECT_EQ(*rit, 4);
}

TYPED_TEST(VectorReverseIterators, Decrement){
	VECTOR						v1(5);
	VECTOR::reverse_iterator	rit = v1.rend();
	
	for (int i = v1.size(); i; i--, rit--)
		*(rit - 1) = i;
	EXPECT_EQ(v1.size(), 5);

	rit = v1.rend() - 1;

	EXPECT_EQ(*--rit, 4);
	EXPECT_EQ(*rit--, 4);
	EXPECT_EQ(*rit, 3);

	rit -= 1;
	
	EXPECT_EQ(*rit, 2);
	
	rit = rit - 1;
	
	EXPECT_EQ(*rit, 1);
}

TYPED_TEST(VectorReverseIterators, SquareBrackets){
	VECTOR						v1(15);
	VECTOR::reverse_iterator	rit;
	VECTOR::reverse_iterator	rit2;
	
	rit	= v1.rbegin();
	for (int i = 0; i < 15; i++, rit++)
		*rit = i;

	rit2 = v1.rbegin();
	rit2[2] = 109;
	
	EXPECT_EQ(v1[12], 109);
}

TYPED_TEST(VectorReverseIterators, NonMember){
	VECTOR						v1(5);
	VECTOR::reverse_iterator	rit = v1.rbegin();
	
	for (int i = 0; i < v1.size(); i++, rit++)
		*rit = i;
	EXPECT_EQ(v1.size(), 5);
	
	VECTOR::reverse_iterator	rit1 = v1.rbegin();
	VECTOR::reverse_iterator	rit2 = v1.rbegin() + 2;
	VECTOR::reverse_iterator	rit3 = v1.rend() - 1;

	EXPECT_TRUE((rit1 + 2) == rit2);
	EXPECT_FALSE((rit1 + 1) == rit2);
	EXPECT_TRUE(rit1 < rit3);
	EXPECT_FALSE(rit2 <= rit1);
	EXPECT_FALSE(rit1 > rit3);
	EXPECT_TRUE(rit2 >= (rit1 + 2));
	EXPECT_FALSE(rit2 != (rit1 + 2));
}

TYPED_TEST(VectorReverseIterators, NonMemberConst){
	VECTOR						v1(5);
	VECTOR::reverse_iterator	it = v1.rbegin();
	
	for (int i = 0; i < v1.size(); i++, it++)
		*it = i;
	EXPECT_EQ(v1.size(), 5);
	
	VECTOR::reverse_iterator		it1 = v1.rbegin();
	VECTOR::reverse_iterator const 	it2 = v1.rbegin() + 2;
	VECTOR::reverse_iterator		it3 = v1.rend() - 1;

	EXPECT_TRUE((it1 + 2) == it2);
	EXPECT_FALSE((it1 + 1) == it2);
	EXPECT_TRUE(it1 < it3);
	EXPECT_FALSE(it2 <= it1);
	EXPECT_FALSE(it1 > it3);
	EXPECT_TRUE(it2 >= (it1 + 2));
	EXPECT_FALSE(it2 != (it1 + 2));
}
