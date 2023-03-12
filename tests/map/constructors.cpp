#include <gtest/gtest.h>
#include "parameters.hpp"

TYPED_TEST_SUITE_P(MapComplexConstruct);

TYPED_TEST(MapComplexConstruct, Default){
	MAP	m1;

	EXPECT_TRUE(m1.empty());
	EXPECT_EQ(m1.size(), 0);
};

TYPED_TEST_SUITE_P(MapSimpleConstruct);

TYPED_TEST(MapSimpleConstruct, CopyConstruct){
	MAP	m1;

	m1[1] = 'a';
	m1[2] = 'b';
	m1[3] = 'c';
	m1[4] = 'd';
	m1[5] = 'e';
	m1[6] = 'f';

	MAP m2(m1);

	EXPECT_EQ(m2.size(), 6);
	EXPECT_EQ(m2[4], 'd');
	EXPECT_EQ(m2[6], 'f');

	m1[4] = 'z';
	m2[6] = 'x';

	EXPECT_EQ(m1[4], 'z');
	EXPECT_EQ(m2[4], 'd');
	EXPECT_EQ(m1[6], 'f');
	EXPECT_EQ(m2[6], 'x');	
};

TYPED_TEST(MapSimpleConstruct, RangeConstruct){
	MAP	m1;

	m1[1] = 'a';
	m1[2] = 'b';
	m1[3] = 'c';
	m1[4] = 'd';
	m1[5] = 'e';
	m1[6] = 'f';

	MAP m2(m1.begin(), m1.end());

	EXPECT_EQ(m2.size(), 6);
	EXPECT_EQ(m2[4], 'd');
	EXPECT_EQ(m2[6], 'f');

	m1[4] = 'z';
	m2[6] = 'x';

	EXPECT_EQ(m1[4], 'z');
	EXPECT_EQ(m2[4], 'd');
	EXPECT_EQ(m1[6], 'f');
	EXPECT_EQ(m2[6], 'x');	
};

TYPED_TEST(MapSimpleConstruct, AssignmentOperator){
	MAP	m1;

	m1[1] = 'a';
	m1[2] = 'b';
	m1[3] = 'c';
	m1[4] = 'd';
	m1[5] = 'e';
	m1[6] = 'f';

	MAP m2;

	m2 = m1;

	EXPECT_EQ(m2.size(), 6);
	EXPECT_EQ(m2[4], 'd');
	EXPECT_EQ(m2[6], 'f');

	m1[4] = 'z';
	m2[6] = 'x';

	EXPECT_EQ(m1[4], 'z');
	EXPECT_EQ(m2[4], 'd');
	EXPECT_EQ(m1[6], 'f');
	EXPECT_EQ(m2[6], 'x');

	m2.erase(3);
	m2.erase(5);
	
	m1 = m2;

	EXPECT_EQ(m2.size(), 4);
	EXPECT_EQ(m1[4], 'd');
	EXPECT_EQ(m1[6], 'x');	
};