

#include "../../includes/utils.hpp"
#include <gtest/gtest.h>
#include <iostream>

template<class T, class = typename ft::enable_if<std::is_integral<T>::value>::type>
std::string foo(T){
	return "T is integral";
}

std::string foo(float){
	return "T is float";
}

std::string foo(bool){
	return "T is bool";
}

TEST(ft_enable_if, general){
	int x = 5;
	float y = 5.5;
	bool z = true;
	
	EXPECT_EQ(foo(x), "T is integral");
	EXPECT_EQ(foo(y), "T is float");
	EXPECT_EQ(foo(z), "T is bool");
}

template <class X, class = typename ft::enable_if<std::is_signed<X>::value>::type>
std::string bar(X){
	return "T is signed";
}

std::string bar(unsigned int){
	return "T is unsigned";
}

TEST(std_enable_if, signedTest){
	signed int x = -5;
	unsigned int y = 5;
	
	EXPECT_EQ(bar(x), "T is signed");
	EXPECT_EQ(bar(y), "T is unsigned");
}
