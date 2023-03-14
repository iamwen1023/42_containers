

#include <gtest/gtest.h>
#include "parameters.hpp"
// #include <iostream>
// #include <utility>

TYPED_TEST_SUITE_P(PairInit);

// constructing a pair with simple and complex types:
TYPED_TEST(PairInit, MakePair){
	PAIR	p1;
}

TYPED_TEST_SUITE_P(PairTest);

// testing with simple types:
TYPED_TEST(PairTest, ConstructInitialised){
	PAIR	p1(1, 'a');
	PAIR	p2(-4, 'x');

	EXPECT_EQ(p1.first, 1);
	EXPECT_EQ(p1.second, 'a');
	EXPECT_EQ(p2.first, -4);
	EXPECT_EQ(p2.second, 'x');		
}

TYPED_TEST(PairTest, ConstuctCopy){
	PAIR	p1(100, '2');
	PAIR	p2(p1);

	p2.first = 101;
	p1.second = '3';

	EXPECT_EQ(p1.first, 100);
	EXPECT_EQ(p1.second, '3');
	EXPECT_EQ(p2.first, 101);
	EXPECT_EQ(p2.second, '2');		
}

TYPED_TEST(PairTest, AssignOperator){
	PAIR	p1(1, 'a');
	PAIR	p2;
	PAIR	p3 = PAIR(25, 'A');

	p2 = p1;
	p1.second = 'd';
	p2.first = 100;
	
	EXPECT_EQ(p1.first, 1);
	EXPECT_EQ(p1.second, 'd');
	EXPECT_EQ(p2.first, 100);
	EXPECT_EQ(p2.second, 'a');
	EXPECT_EQ(p3.first, 25);
	EXPECT_EQ(p3.second, 'A');
}

TYPED_TEST(PairTest, OtherOperators){
	PAIR	p1(1, 'a');
	PAIR	p2(100, 'E');
	PAIR	p3(-2, '?');
	
	EXPECT_TRUE(p1 < p2);
	EXPECT_FALSE(p3 > p1);
	EXPECT_TRUE(p3 <= p2);
	EXPECT_FALSE(p3 >= p2);

	p1 = p3;
	
	EXPECT_FALSE(p1 != p3);

	p1.first = 10;
	
	EXPECT_FALSE(p1 == p3);		
}

// TODO --------->> find a way to test make_pair
