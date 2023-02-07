#include <gtest/gtest.h>
#include "parameters.hpp"

TYPED_TEST_SUITE_P(VectorModifiers);

TYPED_TEST(VectorModifiers, PushBackNPopBack){
	VECTOR				v1;
	
	v1.push_back(23);
	v1.push_back(-5);

	EXPECT_EQ(v1.size(), 2);
	EXPECT_EQ(v1[0], 23);
	EXPECT_EQ(v1[1], -5);

	v1.pop_back();

	EXPECT_EQ(v1.size(), 1);
	EXPECT_EQ(*(v1.end() - 1), 23);
}

TYPED_TEST(VectorModifiers, Insert){
	VECTOR				v1;
	VECTOR				v2;
	VECTOR::iterator	it;
	
	v2.insert(v2.end(), 5, 11);
	it = v2.insert(v2.begin() + 2, 5);
	
	EXPECT_EQ(*it, *(v2.begin() + 2));
	EXPECT_EQ(v2.size(), 6);
	EXPECT_EQ(v2[0], 11);
	EXPECT_EQ(v2[2], 5);
	EXPECT_EQ(v2[5], 11);
	
	for (size_t i = 0; i < 15; i++)
		v1.push_back(i + 2);
	// v2.insert(v2.begin() + 2, v1.begin() + 3, v1.end());

	// EXPECT_EQ(v2.size(), 18);
	// EXPECT_EQ(v2[0], 11);
	// EXPECT_EQ(v2[2], 5);
	// EXPECT_EQ(v2[14], 5);
	// EXPECT_EQ(v2[17], 11);	
}

/*	Note: if relocation is necessary
	all iterators and references after 
	the point of insert are invalidated.
	insert(iterator position, size_t n)
	returns an iterator to the inserted
	element.
*/

TYPED_TEST(VectorModifiers, Erase){
	VECTOR				v1;
	VECTOR::iterator	it;
	
	for (size_t i = 0; i < 15; i++)
		v1.push_back(i + 2);

	EXPECT_EQ(v1[3], 5);
	
	it = v1.erase(v1.begin() + 3);

	EXPECT_EQ(v1[3], 6);
	EXPECT_EQ(*it, *(v1.begin() + 3));
	
	it = v1.erase(v1.begin() + 5, v1.end());

	EXPECT_EQ(it, v1.begin() + 5);
	EXPECT_EQ(v1.size(), 5);
	EXPECT_EQ(*v1.end(), 8);
}

/*	Note: erase invalidates all iterators 
	and references after the point of the erase.
	It returns a new iterator to the element
	after the erased element or range.
*/

TYPED_TEST(VectorModifiers, Clear){
	VECTOR				v1;
	
	for (size_t i = 0; i < 15; i++)
		v1.push_back(i + 2);

	EXPECT_EQ(v1.size(), 15);
	EXPECT_EQ(*(v1.end() - 1), 16);
	EXPECT_EQ(*v1.begin(), 2);

	v1.clear();

	EXPECT_EQ(v1.size(), 0);
	EXPECT_EQ(v1.capacity(), 16);
}

/*	Note: Clear destroys all elements in
	a vector, but the reserved memory,
	and thus the capacity, is not modified.
*/

TYPED_TEST(VectorModifiers, SwapMember){
	VECTOR				v1;
	VECTOR::iterator	it1;
	VECTOR				v2(1);
	VECTOR::iterator	it2;

	for (size_t i = 0; i < 15; i++)
		v1.push_back(i + 2);
	v2.insert(v2.end(), 5, 11);

	it1 = v1.begin();
	it2 = v2.begin();

	v1.swap(v2);

	EXPECT_EQ(*it1, 2);
	EXPECT_EQ(*(it1 + 3), 5);
	EXPECT_EQ(*it2, 0);
	EXPECT_EQ(*(it2 + 3), 11);
}


TYPED_TEST_SUITE_P(VectorModifiersString);

TYPED_TEST(VectorModifiersString, PushBackNPopBack){
	VECTOR				v1;
	
	v1.push_back("hello");
	v1.push_back("goodbye");

	EXPECT_EQ(v1.size(), 2);
	EXPECT_EQ(v1[0], "hello");
	EXPECT_EQ(v1[1], "goodbye");

	v1.pop_back();

	EXPECT_EQ(v1.size(), 1);
	EXPECT_EQ(*(v1.end() - 1), "hello");
}

TYPED_TEST(VectorModifiersString, Insert){
	VECTOR				v1;
	VECTOR				v2;
	VECTOR::iterator	it;
	
	v2.insert(v2.begin(), 5, "chicken sandwich");
	it = v2.insert(v2.begin() + 2, "watermelon salad");
	
	EXPECT_EQ(*it, *(v2.begin() + 2));
	EXPECT_EQ(v2.size(), 6);
	EXPECT_EQ(v2[0], "chicken sandwich");
	EXPECT_EQ(v2[2], "watermelon salad");
	EXPECT_EQ(v2[5], "chicken sandwich");	
	
	v1.push_back("just");
	v1.push_back("some");
	v1.push_back("words");
	v1.push_back("to");
	v1.push_back("test");
	v1.push_back("the");
	v1.push_back("code");

	v2.insert(v2.begin() + 2, v1.begin() + 3, v1.end());

	EXPECT_EQ(v2.size(), 10);
	EXPECT_EQ(v2[0], "chicken sandwich");
	EXPECT_EQ(v2[2], "to");
	EXPECT_EQ(v2[6], "watermelon salad");
	EXPECT_EQ(v2[9], "chicken sandwich");	
}

TYPED_TEST(VectorModifiersString, Erase){
	VECTOR				v1;
	VECTOR::iterator	it;
	
	v1.push_back("Braaaziiiilll");
	v1.push_back("Lalalalalala");
	v1.push_back("Lalalalalalaaaaa");
	v1.push_back("Brazil");
	v1.push_back("Sometimes");
	v1.push_back("it's");
	v1.push_back("hard");
	v1.push_back("to think of");
	v1.push_back("new");
	v1.push_back("strings");

	EXPECT_EQ(v1[2], "Lalalalalalaaaaa");
	
	it = v1.erase(v1.begin() + 2);

	EXPECT_EQ(v1[2], "Brazil");
	EXPECT_EQ(*it, *(v1.begin() + 2));
	
	it = v1.erase(v1.begin() + 5, v1.end());

	EXPECT_EQ(*it, *(v1.begin() + 5));
	EXPECT_EQ(v1.size(), 5);
	EXPECT_EQ(*v1.end(), "hard");
}

TYPED_TEST(VectorModifiersString, Clear){
	VECTOR				v1;
	
	v1.push_back("Braaaziiiilll");
	v1.push_back("Lalalalalala");
	v1.push_back("Lalalalalalaaaaa");
	v1.push_back("Brazil");
	v1.push_back("Sometimes");
	v1.push_back("it's");
	v1.push_back("hard");
	v1.push_back("to think of");
	v1.push_back("new");
	v1.push_back("strings");


	EXPECT_EQ(v1.size(), 10);

	v1.clear();

	EXPECT_EQ(v1.size(), 0);
	EXPECT_EQ(v1.capacity(), 16);
}