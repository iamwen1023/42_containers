

#include <gtest/gtest.h>
#include "parameters.hpp"

TYPED_TEST_SUITE_P(MapOperators);

TYPED_TEST(MapOperators, NonMember){
	MAP		m1;
	MAP		m2;

	m1[1] = 'a';
	m1[2] = 'b';
	m1[3] = 'c';
	m2[1] = 'a';
	m2[2] = 'b';
	m2[3] = 'c';

	EXPECT_TRUE(m1 == m2);
	EXPECT_FALSE(m1 != m2);
	EXPECT_TRUE(m1 <= m2);
	EXPECT_TRUE(m1 >= m2);
	EXPECT_FALSE(m1 < m2);
	EXPECT_FALSE(m1 > m2);
	
	m1[4] = 'c';
	
	EXPECT_TRUE(m1 != m2);
	EXPECT_FALSE(m1 == m2);
	EXPECT_FALSE(m1 <= m2);
	EXPECT_TRUE(m1 >= m2);
	EXPECT_FALSE(m1 < m2);
	EXPECT_TRUE(m1 > m2);

	m2[4] = 'd';

	EXPECT_TRUE(m1 != m2);
	EXPECT_FALSE(m1 == m2);
	EXPECT_TRUE(m1 <= m2);
	EXPECT_FALSE(m1 >= m2);
	EXPECT_TRUE(m1 < m2);
	EXPECT_FALSE(m1 > m2);	
};

TYPED_TEST(MapOperators, NonMemberSwap){
	MAP		m1;
	MAP		m2;

	m1[1] = 'a';
	m1[2] = 'b';
	m1[3] = 'c';
	
	m2[4] = 'd';
	m2[5] = 'e';
	m2[6] = 'f';
	m2[7] = 'g';

	EXPECT_EQ(m1.size(), 3);
	EXPECT_EQ(m1.begin()->first, 1);
	EXPECT_EQ(m1.rbegin()->first, 3);
	EXPECT_EQ(m2.size(), 4);
	EXPECT_EQ(m2.begin()->first, 4);
	EXPECT_EQ(m2.rbegin()->first, 7);

	swap(m1, m2);
	
	EXPECT_EQ(m1.size(), 4);
	EXPECT_EQ(m1.begin()->first, 4);
	EXPECT_EQ(m1.rbegin()->first, 7);
	EXPECT_EQ(m2.size(), 3);
	EXPECT_EQ(m2.begin()->first, 1);
	EXPECT_EQ(m2.rbegin()->first, 3);		
};
