#include "../srcs/iterator_traits.hpp"
#include "../srcs/reverse_iterator.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <map>
#include <typeinfo>

TEST(Iterator, traits) {
    std::vector<int> vc( 10, 55 );
    auto it = std::begin(vc);
    ft::iterator_traits<decltype(it)>::iterator_category my;
    std::iterator_traits<decltype(it)>::iterator_category st;
    std::cout << "type: " << typeid(my).name( ) << std::endl;
    std::cout << "type: " << typeid(st).name( ) << std::endl;
    std::cout << "type: " << typeid(decltype(it)).name() << std::endl;
    EXPECT_EQ(typeid(my).name(), typeid(st).name());
    std::map<char, int> first;
    first['a']=10;
    first['b']=20;
    first['c']=30;
    first['d']=40;
    auto it1 = std::begin(first);
    ft::iterator_traits<decltype(it1)>::iterator_category my1;
    std::iterator_traits<decltype(it1)>::iterator_category st1;
    std::cout << "type: " << typeid(my1).name( ) << std::endl;
    std::cout << "type: " << typeid(st1).name( ) << std::endl;
    std::cout << "type: " << typeid(decltype(it1)).name() << std::endl;
    std::cout << "type: " << typeid(decltype(first)).name() << std::endl;
    std::cout << "type: " << typeid(ft::iterator_traits<decltype(it1)>::value_type).name( ) << std::endl;
    std::cout << "type: " << typeid(std::iterator_traits<decltype(it1)>::value_type).name( ) << std::endl;
    std::cout << "type: " << typeid(ft::iterator_traits<decltype(it1)>::difference_type).name( ) << std::endl;
    std::cout << "type: " << typeid(std::iterator_traits<decltype(it1)>::difference_type).name( ) << std::endl;
    std::cout << "pointer: " << typeid(ft::iterator_traits<decltype(it1)>::pointer).name() << std::endl;
    std::cout << "pointer: " << typeid(std::iterator_traits<decltype(it1)>::pointer).name()  << std::endl;
    std::cout << "pointer: " << typeid(ft::iterator_traits<decltype(it1)>::reference).name() << std::endl;
    std::cout << "pointer: " << typeid(std::iterator_traits<decltype(it1)>::reference ).name()<< std::endl;
    std::cout << "type: " << typeid(st1).name( ) << std::endl;
    std::cout << "type: " << typeid(st1).name( ) << std::endl;
}

TEST(Iterator, reverse) {
    std::cout << "REVERSE!" << std::endl;
    std::vector<int> v{1, 2, 3, 4, 5};
    auto it2 = std::reverse_iterator<std::vector<int>::iterator>((v.end()));
    auto it3 = ft::reverse_iterator<std::vector<int>::iterator>((v.end()));
  
    std::cout << *(it3 +2) << std::endl;

    //operator*()
    EXPECT_EQ(*(it2 +1), *(it3 +1));
    //operator->()
    struct foo { int x; };
    std::vector<foo> v1{{1}, {2}, {3}};
    ft::reverse_iterator<std::vector<foo>::iterator> fo1(v1.end());
    std::reverse_iterator<std::vector<foo>::iterator> fo2(v1.end());
    EXPECT_EQ(fo1->x, fo2->x);
    //operator++()


}

TEST(Iterator, operator_index) {
    std::vector<int> v{1, 2, 3, 4, 5};
    ft::reverse_iterator<std::vector<int>::iterator> it1(v.end());
    it1 += 2;
    std::cout <<*(it1) << std::endl;
    std::reverse_iterator<std::vector<int>::iterator> it2(v.end());
    it2 += 2;
    std::cout << *(it2) << std::endl;// Outputs 3
    EXPECT_EQ(*(it1+1), *(it2+1));

}

TEST(Iterator, base) {
    std::vector<int> v{1, 2, 3, 4, 5};
    std::reverse_iterator<std::vector<int>::iterator> it(v.end());
    ft::reverse_iterator<std::vector<int>::iterator> it2(v.end());
    std::vector<int>::iterator base_it = it.base();
    std::vector<int>::iterator base_it2 = it2.base();
    //std::cout << *base_it << std::endl; // Outputs 3
    EXPECT_EQ(*base_it, *base_it2);

}