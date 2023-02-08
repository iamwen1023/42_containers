#include "../srcs/utils.hpp"
#include <gtest/gtest.h>
#include <iostream>

//ft_is_integral
class A {};

template <class T>
bool f(T i)
{
    (void) i;
    return ft::is_integral<T>::value;
}
 

TEST(ft_is_integral, general){
	bool		t1 = false;
	char		t2 = 14;
	char32_t	t3 = 73;
	short		t4 = -389;
	int			t5 = 3423235;
	long		t6 = 23749237492374;
	long long	t7 = 1468764983276498763;
	float		t8 = 1.25;
	double		t9 = 5.25;
	long double	t10 = 856487356387465893.2;
	A			t11;
	std::string	t12 = "Hello";
	int			t13[3];
	const bool	t14 = false;
	const int	t15 = 8349;

    //std::cout << ft::is_integral(t1) << std::endl;
	EXPECT_TRUE(f(t1));
	EXPECT_TRUE(f(t2));
	EXPECT_TRUE(f(t3));
	EXPECT_TRUE(f(t4));
	EXPECT_TRUE(f(t5));
	EXPECT_TRUE(f(t6));
	EXPECT_TRUE(f(t7));
	EXPECT_FALSE(f(t8));
	EXPECT_FALSE(f(t9));
	EXPECT_FALSE(f(t10));
	EXPECT_FALSE(f(t11));
	EXPECT_FALSE(f(t12));
	EXPECT_FALSE(f(t13));
	EXPECT_TRUE(f(t14));
	EXPECT_TRUE(f(t15));
}

//equall
bool is_palindrome(const std::string& s){
    return ft::equal(s.begin(), s.begin() + s.size()/2, s.rbegin());
}

TEST(ft_equal, palindrome){
	EXPECT_TRUE(is_palindrome("radar"));
	EXPECT_TRUE(is_palindrome("rotator"));
	EXPECT_TRUE(is_palindrome("racecar"));
	EXPECT_FALSE(is_palindrome("hello"));
	EXPECT_FALSE(is_palindrome("bullocks"));
	EXPECT_FALSE(is_palindrome("amsterdam"));
}

bool is_reverse(const std::string& s1, const std::string& s2){
	return ft::equal(s1.begin(), s1.end(), s2.rbegin());
}

TEST(ft_equal, reverse){
	EXPECT_TRUE(is_reverse("parc", "crap"));
	EXPECT_TRUE(is_reverse("live", "evil"));
	EXPECT_TRUE(is_reverse("boobytrap", "partyboob"));
	EXPECT_FALSE(is_reverse("batman", "nambat"));
	EXPECT_FALSE(is_reverse("yellow", "wollei"));
	EXPECT_FALSE(is_reverse("spongebob", "bobengops"));
}

TEST(ft_equal, vector){
    int v1[] = { 10, 20, 30, 40, 50 };
    std::vector<int> vector_1 (v1, v1 + sizeof(v1) / sizeof(int) );
    EXPECT_TRUE(ft::equal (vector_1.begin(), vector_1.end(), v1));
}


//lexicographical_compare
TEST(ft_lexicographical_compare, simple){

}


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
