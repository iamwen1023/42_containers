

#include <gtest/gtest.h>
#include "parameters.hpp"

TYPED_TEST_SUITE_P(StackMemberFunctions);

TYPED_TEST(StackMemberFunctions, PushTop){
	STACK	s1;

	s1.push(5);
	
	EXPECT_EQ(s1.top(), 5);
}

TYPED_TEST(StackMemberFunctions, PushNSize){
	STACK	s1;

	for (int i = 0; i < 100; i++)
		s1.push(23);

	EXPECT_EQ(s1.size(), 100);
}

TYPED_TEST(StackMemberFunctions, Empty){
	STACK	s1;
	
	EXPECT_TRUE(s1.empty());

	s1.push(5);
	
	EXPECT_FALSE(s1.empty());
}

TYPED_TEST(StackMemberFunctions, Pop){
	STACK	s1;

	for (int i = 0; i < 100; i++)
		s1.push(23);

	for (int i = 0; i < 50; i++)
		s1.pop();

	EXPECT_EQ(s1.size(), 50);
}
