
#ifndef PARAMETERS_HPP
# define PARAMETERS_HPP

# include <stack>
# include "../../includes/stack.hpp"
# include "../complex_types.hpp"

// Macro for VECTOR
# define STACK typename TestFixture::Types

// Types to use for test
using SimpleTypes = ::testing::Types
<
	ft::stack<int>,
	std::stack<int>,
	ft::stack<char>,
	std::stack<char>
>;

using ComplexTypes = ::testing::Types
<
	ft::stack<int>,
	std::stack<int>,
	ft::stack<char>,
	std::stack<char>,
	ft::stack<std::string>,
	std::stack<std::string>
>;

using ftPerfType = ::testing::Types
<
	ft::stack<int>
>;

using stdPerfType = ::testing::Types
<
	std::stack<int>
>;

// Test suites
template<typename T>
struct StackComplexConstruct : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(StackComplexConstruct, ComplexTypes);

template<typename T>
struct StackSimpleConstruct : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(StackSimpleConstruct, SimpleTypes);

template<typename T>
struct StackMemberFunctions : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(StackMemberFunctions, SimpleTypes);

template<typename T>
struct StackOperators : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(StackOperators, SimpleTypes);

template<typename T>
struct StackPerformance_ft : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(StackPerformance_ft, ftPerfType);

template<typename T>
struct StackPerformance_std : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(StackPerformance_std, stdPerfType);

#endif