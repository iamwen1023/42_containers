

// #include <gtest/gtest.h>
// #include "parameters.hpp"

// TYPED_TEST_SUITE_P(MapPerformance_ft);

// TYPED_TEST(MapPerformance_ft, Insert){
// 	MAP		m1;

// 	for (int i = 0; i < 1000000; i++){
// 		PAIR	p1(i, 'x');
// 		m1.insert(p1);	
// 	}
// };

// TYPED_TEST(MapPerformance_ft, InsertBrackets){
// 	MAP		m1;

// 	for (int i = 0; i < 1000000; i++)
// 		m1[i] = 'x';
// };

// TYPED_TEST(MapPerformance_ft, Erase){
// 	MAP		m1;

// 	for (int i = 0; i < 1000000; i++)
// 		m1[i] = 'x';

// 	m1.clear();
// };

// TYPED_TEST_SUITE_P(MapPerformance_std);

// TYPED_TEST(MapPerformance_std, Insert){
// 	MAP		m1;

// 	for (int i = 0; i < 1000000; i++){
// 		PAIR	p1(i, 'x');
// 		m1.insert(p1);	
// 	}
// };

// TYPED_TEST(MapPerformance_std, InsertBrackets){
// 	MAP		m1;

// 	for (int i = 0; i < 1000000; i++)
// 		m1[i] = 'x';
// };

// TYPED_TEST(MapPerformance_std, Erase){
// 	MAP		m1;

// 	for (int i = 0; i < 1000000; i++)
// 		m1[i] = 'x';

// 	m1.clear();
// };