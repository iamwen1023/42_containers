#ifndef PARAMETERS_HPP
#define PARAMETERS_HPP
# include <vector>
# include <deque>
# include <list>
# include <utility>
# include <stack>
#include "../../srcs/stack.hpp"

// Macros
//# define STACK typename TestFixture::Types
# define STACKSTD typename TestFixture::Types::first_type
# define STACKFT typename TestFixture::Types::second_type

// Types to test
// Generic test set
using GenericTypes = testing::Types
<
    std::pair<std::stack<int>, ft::stack<int>>
    // std::pair<std::stack<int, std::deque<int>>, ft::stack<int, std::deque<int>>>,
    // std::pair<std::stack<int, std::vector<int>>, ft::stack<int, std::vector<int>>>,
    // std::pair<std::stack<int, std::list<int>>, ft::stack<int, std::list<int>>>
>;

template<typename T>
struct StackConstructors : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(StackConstructors, GenericTypes);


#endif