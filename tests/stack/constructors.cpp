

#include <gtest/gtest.h>
#include "parameters.hpp"

TYPED_TEST_SUITE_P(StackComplexConstruct);

TYPED_TEST(StackComplexConstruct, Default){
	STACK	s1;
	
	EXPECT_EQ(s1.size(), 0);
}

TYPED_TEST(StackSimpleConstruct, CopyConstruct){
	STACK	s1;

	s1.push(2);
	s1.push(34);

	STACK	s2(s1);

	EXPECT_EQ(s2.size(), 2);
	EXPECT_EQ(s2.top(), 34);
	
	s1.push(-76);
	
	EXPECT_EQ(s1.top(), -76);
	EXPECT_EQ(s2.top(), 34);	
}
