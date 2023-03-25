#include "../../includes/utils.hpp"
#include <gtest/gtest.h>

TEST(ft_lexicographical_compare, string){
	std::string		string1 = "Hello there";
	std::string		string2 = "Hello";
	std::string		string3 = "Hello you";
	std::string		string4 = "Hello there all";

	EXPECT_FALSE(ft::lexicographical_compare(string1.begin(), string1.end(),
		string1.begin(), string1.end()));
	EXPECT_FALSE(ft::lexicographical_compare(string1.begin(), string1.end(),
		string2.begin(), string2.end()));
	EXPECT_TRUE(ft::lexicographical_compare(string1.begin(), string1.end(),
		string3.begin(), string3.end()));
	EXPECT_TRUE(ft::lexicographical_compare(string1.begin(), string1.end(),
		string4.begin(), string4.end()));
}

TEST(ft_lexicographical_compare, vector){	
	std::vector<int>		vec1;
	std::vector<int>		vec2;
	std::vector<int>		vec3;
	std::vector<int>		vec4;
	int	i = 0;

	for( ; i < 10 ; i++){
		vec1.push_back(i);
		vec2.push_back(i);
		vec3.push_back(i);
		vec4.push_back(i);
	}

	vec1.push_back(i);
	vec3.push_back(i + 2);
	vec4.push_back(i - 1);

	EXPECT_FALSE(ft::lexicographical_compare(vec1.begin(), vec1.end(),
		vec1.begin(), vec1.end()));
	EXPECT_FALSE(ft::lexicographical_compare(vec1.begin(), vec1.end(),
		vec2.begin(), vec2.end()));
	EXPECT_TRUE(ft::lexicographical_compare(vec1.begin(), vec1.end(),
		vec3.begin(), vec3.end()));
	EXPECT_FALSE(ft::lexicographical_compare(vec1.begin(), vec1.end(),
		vec4.begin(), vec4.end()));
}

bool	compare(char &a, char &b){
	return a < b ? 1 : 0;
}

TEST(ft_lexicographical_compare, stringComp){
	std::string		string1 = "Hello there";
	std::string		string2 = "Hello";
	std::string		string3 = "Hello you";
	std::string		string4 = "Hello there all";

	EXPECT_FALSE(ft::lexicographical_compare(string1.begin(), string1.end(),
		string1.begin(), string1.end(), compare));
	EXPECT_FALSE(ft::lexicographical_compare(string1.begin(), string1.end(),
		string2.begin(), string2.end(), compare));
	EXPECT_TRUE(ft::lexicographical_compare(string1.begin(), string1.end(),
		string3.begin(), string3.end(), compare));
	EXPECT_TRUE(ft::lexicographical_compare(string1.begin(), string1.end(),
		string4.begin(), string4.end(), compare));
}
