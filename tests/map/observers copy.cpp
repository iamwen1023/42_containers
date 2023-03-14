

#include <gtest/gtest.h>
#include "parameters.hpp"

TYPED_TEST_SUITE_P(MapObservers);

TYPED_TEST(MapObservers, KeyComp){
	MAP		m1;
	PAIR	p1(2, 'a');

	m1[1] = 'a';
	m1[2] = 'b';
	m1[3] = 'c';

	MAP::key_compare	comp = m1.key_comp();
	MAP::iterator		it = m1.begin();

	EXPECT_TRUE(comp((it)->first, p1.first));
	EXPECT_FALSE(comp((++it)->first, p1.first));
};

TYPED_TEST(MapObservers, ValueComp){
	MAP		m1;
	PAIR	p1(2, 'a');

	m1[1] = 'a';
	m1[2] = 'b';
	m1[3] = 'c';

	MAP::value_compare	comp = m1.value_comp();
	MAP::iterator		it = m1.begin();

	EXPECT_TRUE(comp(*it, p1));
	EXPECT_FALSE(comp(*(++it), p1));
};
