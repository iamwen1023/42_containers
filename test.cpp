// pair::pair example
//#include <utility>      // std::pair, std::make_pair
#include <iostream>     // std::cout
#include <string>       // std::string
#include "containers/utils/utils.hpp"
#include "containers/utils/pair.hpp"

#include <algorithm>
#include <iostream>
#include <vector>
#include <uchar.h>
#include <stdio.h>
//#include <bits/stdc++.h> 

int main(){

    //pair, make_pair;
    {
        ft::pair <std::string,double> product1;                     // default constructor
        ft::pair <std::string,double> product2 ("tomatoes",2.30);   // value init
        ft::pair <std::string,double> product3 (product2);          // copy constructor

        product1 = ft::make_pair(std::string("lightbulbs"),0.99);   // using make_pair (move)

        product2.first = "shoes";                  // the type of first is string
        product2.second = 39.90;                   // the type of second is double

        std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
        std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
        std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';
    }
    //equel
    {
        int v1[] = { 10, 20, 30, 40, 50 };
        std::vector<int> vector_1 (v1, v1 + sizeof(v1) / sizeof(int) );
 
        // Printing vector1
        std::cout << "Vector contains : ";
        for (unsigned int i = 0; i < vector_1.size(); i++)
            std::cout << " " << vector_1[i];
        std::cout << "\n";
 
        // using std::equal()
        // Comparison within default constructor
        if ( ft::equal (vector_1.begin(), vector_1.end(), v1) )
            std::cout << "The contents of both sequences are equal.\n";
        else
            std::cout << "The contents of both sequences differ.\n";

    }
    //lexicographical_compare
    {
         // initializing char arrays
        char one[] = "geeksforgeeks";
        char two[] = "gfg";
      
        // using lexicographical_compare for checking 
        // is "one" is less than "two"
        if( ft::lexicographical_compare(one, one+13, two, two+3)){
            std::cout << "geeksforgeeks is lexicographically less than gfg\n";
        }
        else{
            std::cout << "geeksforgeeks is not lexicographically less than gfg\n";
        }
    }
    
    return 0;

}