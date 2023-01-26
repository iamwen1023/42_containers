#ifndef PARAMETERS_HPP
#define PARAMETERS_HPP
#include <vector>
#include "../../containers/vector.hpp"
#include "../compplex_types.hpp"

// Macros
# define VECTOR typename TestFixture::Types

// Types to test
// Generic test set
using SimpleType = ::testing::Types
<
	ft::vector<int>,
	std::vector<int>
>;

using StringType = ::testing::Types
<
	ft::vector<std::string>,
	std::vector<std::string>
>;

using ComplexTypes = ::testing::Types
<
	ft::vector<int>,
	std::vector<int>,
	ft::vector<char>,
	std::vector<char>,
	ft::vector<A<int> >,
	std::vector<A<int> >,
	ft::vector<A<float> >,
	std::vector<A<float> >,
	ft::vector<B>,
	std::vector<B>
>;

template<typename T>
struct VectorComplexConstruct : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(VectorComplexConstruct, ComplexTypes);

template<typename T>
struct VectorSimpleConstruct : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(VectorSimpleConstruct, SimpleType);

template<typename T>
struct VectorStringConstruct : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(VectorStringConstruct, StringType);

#endif