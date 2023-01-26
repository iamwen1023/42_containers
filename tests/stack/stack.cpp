#include <gtest/gtest.h>
#include <iostream>
#include "parameters.hpp"

TYPED_TEST_SUITE_P(StackConstructors);

TYPED_TEST(StackConstructors, Default){
	STACKFT my_s1;
    STACKSTD std_s2;

    EXPECT_EQ(my_s1.size(), std_s2.size());
//     s1.push(21);
//     s1.push(22);

//     STACK s2(s1);
//     EXPECT_EQ(s2.size(), 2);


//     s2.pop();
//     STACK s3 = s2;
//     EXPECT_EQ(s3.size(), 1);
}

TYPED_TEST(StackConstructors, memeberFunctions){
	STACKFT s1;
    s1.push(21);
    s1.push(22);
    s1.push(24);
    s1.push(25);
    EXPECT_EQ(s1.top(), 25);

    s1.pop();
    EXPECT_EQ(s1.top(), 24);
}
