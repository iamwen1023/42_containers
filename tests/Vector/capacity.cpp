#include "gtest/gtest.h"
#include "parameters.hpp"

TYPED_TEST_SUITE_P(VectorCapacity);

TYPED_TEST(VectorCapacity, Size){
	VECTOR	v1;
	VECTOR	v2(5);

	EXPECT_EQ(v1.size(), 0);
	EXPECT_EQ(v2.size(), 5);

	VECTOR vct(7);
	VECTOR vct_two(4);

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 3;
	for (unsigned long int i = 0; i < vct_two.size(); ++i)
		vct_two[i] = (vct_two.size() - i) * 5;
	std::cout << "vct_two " << vct.size() << "\n";
	std::cout << "vct_two" << vct_two.size() << "\n";
}

TYPED_TEST(VectorCapacity, MaxSize){
	VECTOR				v1;
	std::allocator<int>	alloc;
	
	EXPECT_EQ(v1.max_size(), alloc.max_size());
}

TYPED_TEST(VectorCapacity, Empty){
	VECTOR				v1;
	
	EXPECT_TRUE(v1.empty());

	v1.push_back(20);

	EXPECT_FALSE(v1.empty());
}

TYPED_TEST(VectorCapacity, Resize){
	VECTOR	v1;
	VECTOR	v2;

	// adding 100 * 23:
	for (size_t i = 0; i < 100; i++){
		v1.push_back(23);
	}

	// resizing to a smaller size,
	// this doesn't change capacity:

	v1.resize(25);

	EXPECT_EQ(v1.size(), 25);
	EXPECT_EQ(v1.capacity(), 128);
	EXPECT_EQ(v1[0], 23);
	EXPECT_EQ(v1[24], 23);

	v1.resize(75);

	// resizing to a bigger size
	// will add default int's: 

	EXPECT_EQ(v1.size(), 75);
	EXPECT_EQ(v1.capacity(), 128);
	EXPECT_EQ(v1[0], 23);
	EXPECT_EQ(v1[74], 0);
}

TYPED_TEST(VectorCapacity, Reserve){
	VECTOR	v1;
	VECTOR	v2;

	for (size_t i = 0; i < 100; i++){
		v1.push_back(23);
	}

	v2.reserve(100);

	EXPECT_EQ(v1.size(), 100);
	EXPECT_EQ(v1.capacity(), 128);
	EXPECT_EQ(v2.size(), 0);
	EXPECT_EQ(v2.capacity(), 100);
}

TYPED_TEST_SUITE_P(VectorCapacityString);

TYPED_TEST(VectorCapacityString, Empty){
	VECTOR				v1;
	
	EXPECT_TRUE(v1.empty());

	v1.push_back("Hi there");

	EXPECT_FALSE(v1.empty());
}

TYPED_TEST(VectorCapacityString, Resize){
	VECTOR	v1;
	VECTOR	v2;

	for (size_t i = 0; i < 100; i++){
		v1.push_back("Why are you reading this?");
	}

	v1.resize(25);

	EXPECT_EQ(v1.size(), 25);
	EXPECT_EQ(v1.capacity(), 128);
	EXPECT_EQ(v1[0], "Why are you reading this?");
	EXPECT_EQ(v1[24], "Why are you reading this?");

	v1.resize(75);

	EXPECT_EQ(v1.size(), 75);
	EXPECT_EQ(v1.capacity(), 128);
	EXPECT_EQ(v1[0], "Why are you reading this?");
	EXPECT_EQ(v1[74], "\0");

	v1.resize(130);
	EXPECT_EQ(v1.size(), 130);
	EXPECT_EQ(v1.capacity(), 150);
	EXPECT_EQ(v1[0], "Why are you reading this?");
	EXPECT_EQ(v1[129], "\0");
}

TYPED_TEST(VectorCapacityString, Reserve){
	VECTOR	v1;
	VECTOR	v2;

	for (size_t i = 0; i < 100; i++){
		v1.push_back("Lalalala");
	}

	v2.reserve(100);

	EXPECT_EQ(v1.size(), 100);
	EXPECT_EQ(v1.capacity(), 128);
	EXPECT_EQ(v2.size(), 0);
	EXPECT_EQ(v2.capacity(), 100);
}