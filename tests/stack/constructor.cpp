#include "../../containers/stack.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include "parameters.hpp"

TYPED_TEST_SUITE_P(StackConstructors);

TYPED_TEST(StackConstructors, Default){
	STACK s1;

    EXPECT_EQ(s1.size(), 0);
	
	//EXPECT_EQ(s1.size(), 0);
}
