

#include <gtest/gtest.h>
#include "parameters.hpp"

TYPED_TEST_SUITE_P(MapIterators);

TYPED_TEST(MapIterators, Begin){
	MAP				m1;

	m1[1] = 'a';
	m1[2] = 'b';
	m1[3] = 'c';

	MAP::iterator	it = m1.begin();
	
	EXPECT_EQ(it->first, 1);
}

TYPED_TEST(MapIterators, End){
	MAP				m1;

	m1[1] = 'a';
	m1[2] = 'b';
	m1[3] = 'c';

	std::cout << "heh\n";
	MAP::iterator	ite = m1.end();
	std::cout << "heh\n";
	
	EXPECT_EQ((--ite)->first, 3);
	std::cout << "heh\n";
}

TYPED_TEST(MapIterators, Dereference){
	MAP		m1;

	m1[1] = 'a';
	m1[2] = 'b';
	m1[3] = 'c';

	MAP::iterator	it = m1.begin();
	
	EXPECT_EQ(it->first, 1);
	EXPECT_EQ(it->second, 'a');
	EXPECT_EQ((*it).first, 1);
}

TYPED_TEST(MapIterators, Increment){
	MAP	m1;

	m1[1] = 'a';
	m1[2] = 'b';
	m1[3] = 'c';
	m1[4] = 'd';
	m1[5] = 'e';
	m1[6] = 'f';

	MAP::iterator	it = m1.begin();
	MAP::iterator	ite = m1.end();

	EXPECT_EQ(it->second, 'a');
	EXPECT_EQ((++it)->second, 'b');
	EXPECT_EQ(it++->second, 'b');
	EXPECT_EQ(it->second, 'c');
	
	while (it != ite)
		it++;
	
	EXPECT_EQ(it->second, '\0');
}

TYPED_TEST(MapIterators, Decrement){
	MAP	m1;

	m1[1] = 'a';
	m1[2] = 'b';
	m1[3] = 'c';
	m1[4] = 'd';
	m1[5] = 'e';
	m1[6] = 'f';

	MAP::iterator	it = m1.begin();
	MAP::iterator	ite = m1.end();
	
	EXPECT_EQ(ite->second, '\0');
	EXPECT_EQ((--ite)->second, 'f');
	EXPECT_EQ(ite--->second, 'f');
	EXPECT_EQ(ite->second, 'e');

	while (ite != it)
		ite--;
		
	EXPECT_EQ(ite->second, 'a');
};

TYPED_TEST_SUITE_P(MapConstIterators);

TYPED_TEST(MapConstIterators, ConstReturn){
	MAP				m1;
	PAIR			p1;
	PAIR			p2;
	PAIR			p3;

	m1.insert(p1);
	m1.insert(p2);
	m1.insert(p3);

	MAP::iterator		it = m1.begin();
	MAP::const_iterator	cit = m1.begin();
	
	EXPECT_EQ(it->second.m(), "non const called");
	EXPECT_EQ(cit->second.m(), "const called");
};
