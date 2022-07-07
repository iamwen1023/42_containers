#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft {
    template <class T1, class T2> 
    struct pair{
        typedef T1 first_type;
        typedef T2 second_type;
        
        T1 first;
        T2 second;

        pair(): first(), second(){};


    }
}


#endif