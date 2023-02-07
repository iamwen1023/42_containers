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

using ftPerfType = ::testing::Types
<
	ft::vector<int>
>;

using stdPerfType = ::testing::Types
<
	std::vector<int>
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

template<typename T>
struct VectorCapacity : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(VectorCapacity, SimpleType);

template<typename T>
struct VectorCapacityString : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(VectorCapacityString, StringType);

template<typename T>
struct VectorAccess : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(VectorAccess, SimpleType);

template<typename T>
struct VectorModifiers : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(VectorModifiers, SimpleType);

template<typename T>
struct VectorModifiersString : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(VectorModifiersString, StringType);

template<typename T>
struct VectorOperators : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(VectorOperators, SimpleType);

template<typename T>
struct VectorIterators : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(VectorIterators, SimpleType);

template<typename T>
struct VectorReverseIterators : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(VectorReverseIterators, SimpleType);

template<typename T>
struct VectorPerformance_ft : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(VectorPerformance_ft, ftPerfType);

template<typename T>
struct VectorPerformance_std : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(VectorPerformance_std, stdPerfType);
#endif