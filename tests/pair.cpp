// #include "../srcs/pair.hpp"
// #include <gtest/gtest.h>
// #include <iostream>
// #include <string>

// TEST(PairTest, ConstructInitialised){
// 	ft::pair<int, char>	p1(1, 'a');
// 	ft::pair<int, char>	p2(-4, 'x');

// 	EXPECT_EQ(p1.first, 1);
// 	EXPECT_EQ(p1.second, 'a');
// 	EXPECT_EQ(p2.first, -4);
// 	EXPECT_EQ(p2.second, 'x');		
// }

// TEST(PairTest, ConstructInitialised2){
// 	ft::pair<char, double>	p1(1000, 'a');
//     std::pair<char, double>	p3(1000, 'a');
// 	ft::pair<int, char>	p2(-4, 'x');

// 	EXPECT_EQ(p1.first, 1);
// 	EXPECT_EQ(p1.second, 'a');
// 	EXPECT_EQ(p2.first, -4);
// 	EXPECT_EQ(p2.second, 'x');		
// }


// TEST(PairTest, ConstuctCopy){
// 	ft::pair<int, char>	p1(100, '2');
// 	ft::pair<int, char>	p2(p1);

// 	p2.first = 101;
// 	p1.second = '3';

// 	EXPECT_EQ(p1.first, 100);
// 	EXPECT_EQ(p1.second, '3');
// 	EXPECT_EQ(p2.first, 101);
// 	EXPECT_EQ(p2.second, '2');		
// }

// TEST(PairTest, AssignOperator){
// 	ft::pair<int, char>	p1(1, 'a');
// 	ft::pair<int, char>	p2;

// 	p2 = p1;
// 	p1.second = 'd';
// 	p2.first = 100;
	
// 	EXPECT_EQ(p1.first, 1);
// 	EXPECT_EQ(p1.second, 'd');
// 	EXPECT_EQ(p2.first, 100);
// 	EXPECT_EQ(p2.second, 'a');
// }

// TEST(PairTest, OtherOperators){
// 	ft::pair<int, char>	p1(1, 'a');
// 	ft::pair<int, char>	p2(100, 'E');
// 	ft::pair<int, char>	p3(-2, '?');
	
// 	EXPECT_TRUE(p1 < p2);
// 	EXPECT_FALSE(p3 > p1);
// 	EXPECT_TRUE(p3 <= p2);
// 	EXPECT_FALSE(p3 >= p2);

// 	p1 = p3;
	
// 	EXPECT_FALSE(p1 != p3);

// 	p1.first = 10;
	
// 	EXPECT_FALSE(p1 == p3);		
// }

// TEST(MakePairTest, simpleTest){
//     ft::pair<std::string, double>	p1= ft::make_pair(std::string("lightbulbs"),0.99);
//     EXPECT_TRUE(p1.first == "lightbulbs");
// 	EXPECT_EQ(p1.second, 0.99);

// }