

#include <gtest/gtest.h>
#include "parameters.hpp"

TYPED_TEST_SUITE_P(MapModifiers);

TYPED_TEST(MapModifiers, InsertSimple){
	MAP		m1;
	PAIR	p1(1, 'a');
	PAIR	p2(1, 'b');
	PAIR	p3(2, 'c');


	EXPECT_TRUE(m1.insert(p1).second);
	EXPECT_FALSE(m1.insert(p1).second);
	EXPECT_FALSE(m1.insert(p2).second);
	EXPECT_TRUE(m1.insert(p3).second);

	EXPECT_EQ(m1.insert(p2).first->second, 'a');
};

TYPED_TEST(MapModifiers, InsertHint){
	MAP				m1;
	PAIR			p1(1, 'b');
	PAIR			p2(2, 'c');

	m1[1] = 'a';
	m1[6] = 'b';
	m1[8] = 'c';

	MAP::iterator	it = m1.begin();
	MAP::iterator	ite = m1.end();

	EXPECT_EQ(m1.insert(ite, p1)->second, 'a');  
	EXPECT_EQ(m1.insert(ite, p2)->second, 'c');  
};

TYPED_TEST(MapModifiers, InsertRange){
	MAP		m1;
	MAP		m2;

	m1[1] = 'a';
	m1[2] = 'b';
	m1[3] = 'c';

	m2[4] = 'd';
	m2[2] = 'e';
	m2[6] = 'f';

	m2.insert(m1.begin(), m1.end());

	MAP::iterator	it = m2.begin();
	MAP::iterator	ite = m2.end();

	EXPECT_EQ(m2.size(), 5);
	EXPECT_EQ(it->first, 1);
	EXPECT_EQ((--ite)->first, 6);	
};

TYPED_TEST(MapModifiers, EraseIterator){
	MAP		m1;
	
	m1[1] = 'a';
	m1[2] = 'b';
	m1[3] = 'c';
	m1[4] = 'd';
	m1[5] = 'e';
	m1[6] = 'f';

	MAP::iterator	it = m1.begin();
	MAP::iterator	ite = m1.end();
	
	it++; it++; it++;
	ite--;
	
	m1.erase(it);
	m1.erase(ite);
	
	EXPECT_EQ(m1.size(), 4);

	it = m1.begin();

	EXPECT_EQ(it++->first, 1);
	EXPECT_EQ(it++->first, 2);
	EXPECT_EQ(it++->first, 3);
	EXPECT_EQ(it++->first, 5);
};

TYPED_TEST(MapModifiers, EraseValidityIterators){
	MAP	m1;

	m1[1] = 'a';
	m1[2] = 'b';
	m1[3] = 'c';
	m1[4] = 'd';
	m1[5] = 'e';
	m1[6] = 'f';

	MAP::iterator	it = m1.begin();
	MAP::iterator	ite = m1.end();

	it++; it++;
	
	m1.erase(4);
	
	EXPECT_EQ(it->first, 3);
	EXPECT_EQ((--ite)->first, 6);
	EXPECT_EQ((--ite)->first, 5);
	EXPECT_EQ((--ite)->first, 3);
	EXPECT_EQ((--ite)->first, 2);
	EXPECT_EQ((--ite)->first, 1);
};

TYPED_TEST(MapModifiers, EraseKey){
	MAP		m1;
	
	m1[1] = 'a';
	m1[2] = 'b';
	m1[3] = 'c';
	m1[4] = 'd';
	m1[5] = 'e';
	m1[6] = 'f';

	m1.erase(1);
	m1.erase(6);

	MAP::iterator	it = m1.begin();

	for (int i = 2; i < 6; i++, it++)
		EXPECT_EQ(it->first, i);
};

TYPED_TEST(MapModifiers, EraseRange){
	MAP		m1;
	
	m1[1] = 'a';
	m1[2] = 'b';
	m1[3] = 'c';
	m1[4] = 'd';
	m1[5] = 'e';
	m1[6] = 'f';

	MAP::iterator	it = m1.begin();
	MAP::iterator	ite = m1.end();

	ite--; ite--; ite--;
	m1.erase(it, ite);
	it = m1.begin();

	EXPECT_EQ(m1.size(), 3);
	for (int i = 4; i < 7; i++, it++)
		EXPECT_EQ(it->first, i);

	it = m1.begin();
	ite = m1.end();
	m1.erase(it, ite);

	EXPECT_EQ(m1.size(), 0);
};

TYPED_TEST(MapModifiers, Swap){
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

	m1.swap(m2);
	
	EXPECT_EQ(m1.size(), 4);
	EXPECT_EQ(m1.begin()->first, 4);
	EXPECT_EQ(m1.rbegin()->first, 7);
	EXPECT_EQ(m2.size(), 3);
	EXPECT_EQ(m2.begin()->first, 1);
	EXPECT_EQ(m2.rbegin()->first, 3);
};

TYPED_TEST(MapModifiers, Clear){
	MAP		m1;
	
	m1[1] = 'a';
	m1[2] = 'b';
	m1[3] = 'c';
	m1[4] = 'd';
	m1[5] = 'e';
	m1[6] = 'f';
	
	EXPECT_EQ(m1.size(), 6);
	m1.clear();
	EXPECT_EQ(m1.size(), 0);
	EXPECT_TRUE(m1.empty());
};
