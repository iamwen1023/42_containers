#include "../containers/iterator_traits.hpp"
#include "../containers/reverse_iterator.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <typeinfo>

TEST(Iterator, traits) {
    vector<char> vc( 10,'a' );
    ft_iterator_traits<char>::iterator_category my;
    std::iterator_traits<char>::iterator_category st;
    std::cout << typeid(my).name( ) << std::endl;
    std::cout << typeid(st).name( ) << std::endl;
    EXPECT_EQ(typeid(my).name(), typeid(st).name());
}