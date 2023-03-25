#include <gtest/gtest.h>
#include "parameters.hpp"
#include "../../includes/rb_node.hpp"

TYPED_TEST_SUITE_P(MapCapacity);

TYPED_TEST(MapCapacity, Empty){
	MAP				m1;

	EXPECT_TRUE(m1.empty());

	m1[1] = 'a';
	m1[2] = 'b';
	m1[3] = 'c';

	EXPECT_FALSE(m1.empty());

	m1.clear();

	EXPECT_TRUE(m1.empty());
};


TYPED_TEST(MapCapacity, Size){
	MAP				m1;

	EXPECT_EQ(m1.size(), 0);

	m1[1] = 'a';
	m1[2] = 'b';
	m1[3] = 'c';

	EXPECT_EQ(m1.size(), 3);

	m1.clear();

	EXPECT_EQ(m1.size(), 0);
};
