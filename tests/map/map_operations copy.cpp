

#include <gtest/gtest.h>
#include "parameters.hpp"

TYPED_TEST_SUITE_P(MapOperations);

TYPED_TEST(MapOperations, Find){
	MAP	m1;
	
	m1[1] = 'a';
	m1[2] = 'b';
	m1[3] = 'c';
	m1[4] = 'd';
	
	EXPECT_EQ(m1.find(2)->second, 'b');
	EXPECT_EQ(m1.find(4)->second, 'd');
	EXPECT_EQ(m1.find(5), m1.end());
};

TYPED_TEST(MapOperations, Count){
	MAP	m1;
	
	m1[1] = 'a';
	m1[2] = 'b';
	m1[3] = 'c';
	m1[4] = 'd';
	
	EXPECT_EQ(m1.count(2), 1);
	EXPECT_EQ(m1.count(4), 1);
	EXPECT_EQ(m1.count(5), 0);
};

TYPED_TEST(MapOperations, LowerBound){
	MAP	m1;
	
	m1[1] = 'a';
	m1[2] = 'b';
	m1[3] = 'c';
	m1[4] = 'd';
	
	EXPECT_EQ(m1.lower_bound(2)->first, 2);
	EXPECT_EQ(m1.lower_bound(4)->first, 4);
	EXPECT_EQ(m1.lower_bound(5), m1.end());
};

TYPED_TEST(MapOperations, UpperBound){
	MAP	m1;
	
	m1[1] = 'a';
	m1[2] = 'b';
	m1[3] = 'c';
	m1[4] = 'd';
	
	EXPECT_EQ(m1.upper_bound(2)->first, 3);
	EXPECT_EQ(m1.upper_bound(4), m1.end());
	EXPECT_EQ(m1.upper_bound(5), m1.end());
};

TYPED_TEST(MapOperations, EqualRange){
	MAP	m1;
	
	m1[1] = 'a';
	m1[2] = 'b';
	m1[3] = 'c';
	m1[4] = 'd';
	
	EXPECT_EQ(m1.equal_range(2).first->first, 2);
	EXPECT_EQ(m1.equal_range(2).second->first, 3);
	EXPECT_EQ(m1.equal_range(3).first->first, 3);
	EXPECT_EQ(m1.equal_range(3).second->first, 4);
	EXPECT_EQ(m1.equal_range(5).first, m1.end());
	EXPECT_EQ(m1.equal_range(5).second, m1.end());
};
