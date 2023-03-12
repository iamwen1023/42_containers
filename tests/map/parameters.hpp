#ifndef PARAMETERS_HPP
# define PARAMETERS_HPP

# include <iostream>
# include <map>
# include "../../srcs/map.hpp"
# include "../complex_types.hpp"

// Macro for MAP
# define MAP typename TestFixture::Types::first_type
# define PAIR typename TestFixture::Types::second_type

// Types to use for test
using SimpleType = ::testing::Types
<
    std::pair<ft::map<int, char>, ft::pair<int, char> >,
	std::pair<std::map<int, char>, std::pair<int, char> >
>;

using ComplexTypes = ::testing::Types
<
	std::pair<ft::map<int, std::string>, ft::pair<int, std::string> >,
	std::pair<std::map<int, std::string>, std::pair<int, std::string> >,
	std::pair<ft::map<float, B>, ft::pair<float, B> >,
	std::pair<std::map<float, B>, std::pair<float, B> >,
	std::pair<ft::map<A<int>, B>, ft::pair<A<int>, B> >,
	std::pair<std::map<A<int>, B>, std::pair<A<int>, B> >,
	std::pair<ft::map<ft::map<int, char>, A<ft::map<int, std::string> > >,
		ft::pair<ft::map<int, char>, A<ft::map<int, std::string> > > >,
	std::pair<std::map<std::map<int, char>, A<std::map<int, std::string> > >,
		std::pair<std::map<int, char>, A<std::map<int, std::string> > > >
>;

using ClassType = ::testing::Types
<
	std::pair<ft::map<int, B>, ft::pair<int, B> >,
	std::pair<std::map<int, B>, std::pair<int, B> >
>;

using ftPerfType = ::testing::Types
<
	std::pair<ft::map<int, char>, ft::pair<int, char> >
>;

using stdPerfType = ::testing::Types
<
	std::pair<std::map<int, char>, std::pair<int, char> >
>;

// Test suites
template<typename T>
struct MapComplexConstruct : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(MapComplexConstruct, ComplexTypes);

template<typename T>
struct MapSimpleConstruct : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(MapSimpleConstruct, SimpleType);

template<typename T>
struct MapIterators : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(MapIterators, SimpleType);

template<typename T>
struct MapConstIterators : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(MapConstIterators, ClassType);

template<typename T>
struct MapReverseIterators : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(MapReverseIterators, SimpleType);

template<typename T>
struct MapConstReverseIterators : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(MapConstReverseIterators, ClassType);

template<typename T>
struct MapCapacity : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(MapCapacity, SimpleType);

template<typename T>
struct MapElementAccess : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(MapElementAccess, SimpleType);

template<typename T>
struct MapModifiers : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(MapModifiers, SimpleType);

template<typename T>
struct MapOperators : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(MapOperators, SimpleType);

template<typename T>
struct MapOperations : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(MapOperations, SimpleType);

template<typename T>
struct MapObservers : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(MapObservers, SimpleType);

template<typename T>
struct MapPerformance_ft : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(MapPerformance_ft, ftPerfType);

template<typename T>
struct MapPerformance_std : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(MapPerformance_std, stdPerfType);

#endif