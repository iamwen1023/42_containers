#include "../../includes/utils.hpp"
#include <gtest/gtest.h>

class A {};
 
template <typename T>
bool isintegral(T a){
	(void)a;
	return ft::is_integral<T>::value;
}

TEST(ft_is_integral, general){
	bool		t1 = false;
	char		t2 = 14;
	wchar_t		t3 = 73;
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

	EXPECT_TRUE(isintegral(t1));
	EXPECT_TRUE(isintegral(t2));
	EXPECT_TRUE(isintegral(t3));
	EXPECT_TRUE(isintegral(t4));
	EXPECT_TRUE(isintegral(t5));
	EXPECT_TRUE(isintegral(t6));
	EXPECT_TRUE(isintegral(t7));
	EXPECT_FALSE(isintegral(t8));
	EXPECT_FALSE(isintegral(t9));
	EXPECT_FALSE(isintegral(t10));
	EXPECT_FALSE(isintegral(t11));
	EXPECT_FALSE(isintegral(t12));
	EXPECT_FALSE(isintegral(t13));
	EXPECT_TRUE(isintegral(t14));
	EXPECT_TRUE(isintegral(t15));
}
