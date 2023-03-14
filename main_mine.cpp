#include "./map.hpp"
#include <iostream>
#include <map>
#include <utility>

int main(){
    ft::map<int, char> m1;

	// m1.insert(ft::make_pair(4, 'a'));
	// m1.insert(ft::make_pair(5, 'b'));
	// m1.insert(ft::make_pair(6, 'c'));

	//ft::map<int, char>::iterator		it = m1.begin();
	// ft::map<int, char>::const_iterator	cit = m1.begin();
    
    // EXPECT_EQ(it->second.m(), "non const called");
	// EXPECT_EQ(cit->second.m(), "const called");
    // m1[1] = 'a';
	// m1[2] = 'b';
	// m1[3] = 'c';

	// ft::map<int, char>::iterator	ite = m1.end();
	// std::cout << "heh:"<< (--ite)->first <<"\n";
    
	//EXPECT_EQ((--ite)->first, 3);

	// m1[1] = 'a';
	// m1[2] = 'b';
	// m1[3] = 'c';
	// m1[4] = 'd';
	// m1[5] = 'e';
	// m1[6] = 'f';

	// ft::map<int, char>::iterator	it = m1.begin();
	// ft::map<int, char>::iterator	ite = m1.end();

    // std::cout <<it->second <<std::endl;
    // std::cout << (++it)->second<<std::endl;
    // std::cout << it++->second<<std::endl;
    // std::cout << it->second<<std::endl;
	// EXPECT_EQ(it->second, 'a');
	// EXPECT_EQ((++it)->second, 'b');
	// EXPECT_EQ(it++->second, 'b');
	// EXPECT_EQ(it->second, 'c');
	
	// while (it != ite)
	// 	it++;
	
    // std::cout << (it->second == '\0')<<std::endl;
	//EXPECT_EQ(it->second, '\0');

   // MAP	m1;

	// m1[1] = 'a';
	// m1[2] = 'b';
	// m1[3] = 'c';
	// m1[4] = 'd';
	// m1[5] = 'e';
	// m1[6] = 'f';

	// ft::map<int, char>::iterator	it = m1.begin();
	// ft::map<int, char>::iterator	ite = m1.end();
	
    // std::cout << ((ite->first) == '\0') <<std::endl;
    // std::cout << (--ite)->second<<std::endl;
    // std::cout << ite--->second<<std::endl;
    // std::cout << ite->second<<std::endl;
	// EXPECT_EQ(ite->second, '\0');
	// EXPECT_EQ((--ite)->second, 'f');
	// EXPECT_EQ(ite--->second, 'f');
	// EXPECT_EQ(ite->second, 'e');

	// while (ite != it)
	// 	ite--;

    // std::cout << ite->second<<std::endl;
	//EXPECT_EQ(ite->second, 'a');

	m1[1] = 'a';
	m1[2] = 'b';
	m1[3] = 'c';
	m1[4] = 'd';
	m1[5] = 'e';
	m1[6] = 'f';

	ft::map<int, char>::reverse_iterator	rit = m1.rbegin();
	ft::map<int, char>::reverse_iterator	rite = m1.rend();

    std::cout << "rit->second:" << rit->second <<"\n";
    std::cout << "rit->second:" << (++rit)->second <<"\n";
    std::cout << "rit->second:" << rit++->second <<"\n";
    std::cout << "rit->second:" << rit->second <<"\n";
	// EXPECT_EQ(rit->second, 'f');
	// EXPECT_EQ((++rit)->second, 'e');
	// EXPECT_EQ(rit++->second, 'e');
	// EXPECT_EQ(rit->second, 'd');
	
	while (rit != rite)
		rit++;
	
	//EXPECT_EQ(rit->second, '\0');
    std::cout << "rit->second:" << (int)(rit->second) <<"\n";
	

    ft::map<int, char>::reverse_iterator	rit1 = m1.rbegin();
	ft::map<int, char>::reverse_iterator	rite1 = m1.rend();
	
    std::cout << "rite1->second:" << (int)(rite1->second) <<"\n";
    std::cout << "rite1->second:" << (--rite1)->second <<"\n";
    std::cout << "rite1->second:" << rite1--->second <<"\n";
    std::cout << "rite1->second:" << rite1->second <<"\n";
	// EXPECT_EQ(rite->second, '\0');
	// EXPECT_EQ((--rite)->second, 'a');
	// EXPECT_EQ(rite--->second, 'a');
	// EXPECT_EQ(rite->second, 'b');

	while (rite1 != rit1)
		rite1--;
	
    std::cout << "rite1->second:" << rite1->second <<"\n";
	// EXPECT_EQ(rite->second, 'f');
}