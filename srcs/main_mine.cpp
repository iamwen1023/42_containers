#include "./map.hpp"
#include <iostream>
#include <map>
#include "./vector.hpp"
#include <utility>

template <class T, class Alloc>
void	cmp(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}

int main(){
//     ft::map<int, char> m1;

// 	// m1.insert(ft::make_pair(4, 'a'));
// 	// m1.insert(ft::make_pair(5, 'b'));
// 	// m1.insert(ft::make_pair(6, 'c'));

// 	//ft::map<int, char>::iterator		it = m1.begin();
// 	// ft::map<int, char>::const_iterator	cit = m1.begin();
    
//     // EXPECT_EQ(it->second.m(), "non const called");
// 	// EXPECT_EQ(cit->second.m(), "const called");
//     // m1[1] = 'a';
// 	// m1[2] = 'b';
// 	// m1[3] = 'c';

// 	// ft::map<int, char>::iterator	ite = m1.end();
// 	// std::cout << "heh:"<< (--ite)->first <<"\n";
    
// 	//EXPECT_EQ((--ite)->first, 3);

// 	// m1[1] = 'a';
// 	// m1[2] = 'b';
// 	// m1[3] = 'c';
// 	// m1[4] = 'd';
// 	// m1[5] = 'e';
// 	// m1[6] = 'f';

// 	// ft::map<int, char>::iterator	it = m1.begin();
// 	// ft::map<int, char>::iterator	ite = m1.end();

//     // std::cout <<it->second <<std::endl;
//     // std::cout << (++it)->second<<std::endl;
//     // std::cout << it++->second<<std::endl;
//     // std::cout << it->second<<std::endl;
// 	// EXPECT_EQ(it->second, 'a');
// 	// EXPECT_EQ((++it)->second, 'b');
// 	// EXPECT_EQ(it++->second, 'b');
// 	// EXPECT_EQ(it->second, 'c');
	
// 	// while (it != ite)
// 	// 	it++;
	
//     // std::cout << (it->second == '\0')<<std::endl;
// 	//EXPECT_EQ(it->second, '\0');

//    // MAP	m1;
// 	std::cout << "hello??\n";
// 	// m1[1] = 'a';
// 	// m1[2] = 'b';
// 	// m1[3] = 'c';
// 	// m1[4] = 'd';
// 	// m1[5] = 'e';
// 	// m1[6] = 'f';

// 	// ft::map<int, char>::iterator	it = m1.begin();
// 	// ft::map<int, char>::iterator	ite = m1.end();
	
//     // std::cout << ((ite->first) == '\0') <<std::endl;
//     // std::cout << (--ite)->second<<std::endl;
//     // std::cout << ite--->second<<std::endl;
//     // std::cout << ite->second<<std::endl;
// 	// EXPECT_EQ(ite->second, '\0');
// 	// EXPECT_EQ((--ite)->second, 'f');
// 	// EXPECT_EQ(ite--->second, 'f');
// 	// EXPECT_EQ(ite->second, 'e');

// 	// while (ite != it)
// 	// 	ite--;

//     // std::cout << ite->second<<std::endl;
// 	//EXPECT_EQ(ite->second, 'a');

// 	m1[1] = 'a';
// 	m1[2] = 'b';
// 	m1[3] = 'c';
// 	m1[4] = 'd';
// 	m1[5] = 'e';
// 	m1[6] = 'f';

// 	ft::map<int, char>::reverse_iterator	rit = m1.rbegin();
// 	ft::map<int, char>::reverse_iterator	rite = m1.rend();

//     std::cout << "rit->second:" << rit->second <<"\n";
//     std::cout << "rit->second:" << (++rit)->second <<"\n";
//     std::cout << "rit->second:" << rit++->second <<"\n";
//     std::cout << "rit->second:" << rit->second <<"\n";
// 	// EXPECT_EQ(rit->second, 'f');
// 	// EXPECT_EQ((++rit)->second, 'e');
// 	// EXPECT_EQ(rit++->second, 'e');
// 	// EXPECT_EQ(rit->second, 'd');
	
// 	while (rit != rite)
// 		rit++;
	
// 	//EXPECT_EQ(rit->second, '\0');
//     std::cout << "rit->second:" << (int)(rit->second) <<"\n";
	

//     ft::map<int, char>::reverse_iterator	rit1 = m1.rbegin();
// 	ft::map<int, char>::reverse_iterator	rite1 = m1.rend();
	
//     std::cout << "rite1->second:" << (int)(rite1->second) <<"\n";
//     std::cout << "rite1->second:" << (--rite1)->second <<"\n";
//     std::cout << "rite1->second:" << rite1--->second <<"\n";
//     std::cout << "rite1->second:" << rite1->second <<"\n";
// 	// EXPECT_EQ(rite->second, '\0');
// 	// EXPECT_EQ((--rite)->second, 'a');
// 	// EXPECT_EQ(rite--->second, 'a');
// 	// EXPECT_EQ(rite->second, 'b');

// 	while (rite1 != rit1)
// 		rite1--;
	
//     std::cout << "rite1->second:" << rite1->second <<"\n";
// 	m1.printTreemap();
	// EXPECT_EQ(rite->second, 'f');

	// ft::vector<int>	v1(4);
	// ft::vector<int>	v2(4);
	
	// std::cout << (v1 == v2)<<"\n";
	// std::cout << (v1 == v1)<<"\n";
	// // // EXPECT_TRUE(v1 == v2);
	// // // EXPECT_TRUE(v1 == v1);

	// v1.resize(23);

	// std::cout << (v1 == v2)<<"\n";
	// std::cout << (v1 != v2)<<"\n";
	// // EXPECT_FALSE(v1 == v2);
	// // EXPECT_TRUE(v1 != v2);
	
	// v2.insert(v2.begin() + 2, 3, 12);
	
	// std::cout << (v1 <= v2)<<"\n";
	// std::cout << (v1 >= v2)<<"\n";
	// std::cout << (v1 < v2)<<"\n";
	// std::cout << (v1 > v2)<<"\n";
	// // EXPECT_TRUE(v1 <= v2);
	// // EXPECT_FALSE(v1 >= v2);
	// // EXPECT_TRUE(v1 < v2);
	// // EXPECT_FALSE(v1 > v2);
	// ft::vector<int>					v3(4);
	// ft::vector<int>				v4(4);

	// v3.insert(v3.begin(), 4, 1);
	// v4.insert(v4.begin(), 4, 2);

	// ft::vector<int>	::iterator	it1 = v3.begin();
	// ft::vector<int>	::iterator	it2 = v4.begin();

	// // EXPECT_EQ(*it1, 1);
	// // EXPECT_EQ(*it2, 2);
	// // EXPECT_EQ(*(v3.begin()), 1);
	// // EXPECT_EQ(*(v4.begin()), 2);	

	// ft::swap(v1, v2);
	
	// EXPECT_EQ(*it1, 1);
	// EXPECT_EQ(*it2, 2);
	// EXPECT_EQ(*(v1.begin()), 2);
	// EXPECT_EQ(*(v2.begin()), 1);
	// ft::vector<int>  vct(7);
	// ft::vector<int> vct_two(4);
	// ft::vector<int>  vct_three;
	// ft::vector<int>  vct_four;

	// for (unsigned long int i = 0; i < vct.size(); ++i)
	// 	vct[i] = (vct.size() - i) * 3;
	// for (unsigned long int i = 0; i < vct_two.size(); ++i)
	// 	vct_two[i] = (vct_two.size() - i) * 5;
	// const size_t size = vct.size();
	// const size_t capacity = vct.capacity();
	// const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// // Cannot limit capacity's max value because it's implementation dependent

	// std::cout << "size: " << size << std::endl;
	// std::cout << "capacity: " << isCapacityOk << std::endl;
	// std::cout << "max_size: " << vct.max_size() << std::endl;
	
	// ft::vector<int>::const_iterator it = vct.begin();
	// ft::vector<int>::const_iterator ite = vct.end();
	// 	std::cout << std::endl << "Content is:" << std::endl;
	// 	for (; it != ite; ++it)
	// 		std::cout << "- " << *it << std::endl;

	ft::vector<int> vct(4);
	ft::vector<int> vct2(4);

	cmp(vct, vct);  // 0
	cmp(vct, vct2); // 1

	vct2.resize(10);

	cmp(vct, vct2); // 2
	cmp(vct2, vct); // 3

	vct[2] = 42;

	cmp(vct, vct2); // 4
	cmp(vct2, vct); // 5

	swap(vct, vct2);

	cmp(vct, vct2); // 6
	cmp(vct2, vct); // 7
}