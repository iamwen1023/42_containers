#include "gtest/gtest.h"
#include "parameters.hpp"

#include <list>

TYPED_TEST_SUITE_P(Vector_ComplexConstruct);

TYPED_TEST(VectorComplexConstruct, DefaultConstruct){
	VECTOR	v1;
	
	EXPECT_TRUE(v1.empty());
}

TYPED_TEST(VectorComplexConstruct, SizedConstruct){
	VECTOR	v1(5);

	EXPECT_EQ(v1.size(), 5);
	EXPECT_EQ(v1.capacity(), 5);
}

TYPED_TEST_SUITE_P(VectorSimpleConstruct);

TYPED_TEST(VectorSimpleConstruct, CopyConstruct){
	VECTOR	v1(5);

	v1.push_back(2);
	v1.push_back(34);

	VECTOR	v2(v1);

	EXPECT_EQ(v2.size(), 7);
	EXPECT_EQ(v2.capacity(), 7);
	EXPECT_EQ(v2[0], 0);
	EXPECT_EQ(v2[6], 34);

	v1[2] = 3;
	v2[3] = 2;

	EXPECT_EQ(v1[2], 3);
	EXPECT_EQ(v1[3], 0);
	EXPECT_EQ(v2[2], 0);
	EXPECT_EQ(v2[3], 2);
}

TYPED_TEST(VectorSimpleConstruct, RangeConstruct){
	VECTOR	v1(5);

	v1.push_back(2);
	v1.push_back(34);
	v1.push_back(28);
	v1.push_back(75);
	
	VECTOR	v2(v1.begin() + 4, v1.end());

	EXPECT_EQ(v2.size(), 5);
	EXPECT_EQ(v2.capacity(), 5);
	EXPECT_EQ(v2[0], 0);
	EXPECT_EQ(v2[4], 75);

	VECTOR	v3(v2.begin(), v2.begin() + 3);

	EXPECT_EQ(v3.size(), 3);
	EXPECT_EQ(v3.capacity(), 3);
	EXPECT_EQ(v3[0], 0);
	EXPECT_EQ(v3[2], 34);
}

TYPED_TEST(VectorSimpleConstruct, Assign){
	VECTOR	v1;

	v1.assign(20, 5);

	EXPECT_EQ(v1.size(), 20);
	EXPECT_EQ(v1.capacity(), 20);
	EXPECT_EQ(v1[0], 5);
	EXPECT_EQ(v1[19], 5);	
	
	VECTOR	v2;

	v2.assign(v1.begin(), v1.begin() + 4);

	EXPECT_EQ(v2.size(), 4);
	EXPECT_EQ(v2.capacity(), 4);
	EXPECT_EQ(v2[0], 5);
	EXPECT_EQ(v2[3], 5);

	std::list<int>				list;

	list.push_back(56);
	list.push_back(34);
	list.push_back(104);
	list.push_back(-1);

	VECTOR	v3;

	v3.assign(list.begin(), list.end());

	EXPECT_EQ(v3.size(), 4);
	EXPECT_EQ(v3.capacity(), 4);
	EXPECT_EQ(v3[0], 56);
	EXPECT_EQ(v3[3], -1);
}

TYPED_TEST_SUITE_P(VectorStringConstruct);

TYPED_TEST(VectorStringConstruct, StringConstruct){
	VECTOR	v1;
	
	EXPECT_TRUE(v1.empty());
	
	v1.push_back("Hello");
	v1.push_back("Wazzaaa");
	v1.push_back("All good?");

	VECTOR	v2(5);

	EXPECT_FALSE(v2.empty());
	EXPECT_EQ(v2.size(), 5);
	EXPECT_EQ(v2.capacity(), 5);
	EXPECT_EQ(v2[0], "\0");
	EXPECT_EQ(v2[2], "\0");	

	VECTOR	v3(v1);
	
	v1[0] = "Later bro.";
	v3[0] = "We are independant now.";

	EXPECT_EQ(v1.size(), 3);
	EXPECT_EQ(v1.capacity(), 4);
	EXPECT_EQ(v1[0], "Later bro.");
	EXPECT_EQ(v1[2], "All good?");
	EXPECT_EQ(v3.size(), 3);
	EXPECT_EQ(v3.capacity(), 3);
	EXPECT_EQ(v3[0], "We are independant now.");
	EXPECT_EQ(v3[2], "All good?");	
}