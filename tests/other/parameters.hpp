

#ifndef PARAMETERS_HPP
# define PARAMETERS_HPP

# include "../../includes/pair.hpp"
# include <gtest/gtest.h>

// Macro for PAIR
# define PAIR typename TestFixture::Types

class A {};

// Types to use for test
using AllTypes = ::testing::Types
<
	ft::pair<int, char>,
	std::pair<int, char>,
	ft::pair<double, std::string>,
	std::pair<double, std::string>,
	ft::pair<float, A>,
	std::pair<float, A>
>;

using IntChar = ::testing::Types
<
	ft::pair<int, char>,
	std::pair<int, char>
>;

// Test suites
template<typename T>
struct PairInit : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(PairInit, AllTypes);

template<typename T>
struct PairTest : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(PairTest, IntChar);

#endif