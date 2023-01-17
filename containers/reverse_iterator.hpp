#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP
namespace ft {
    template< class Iter >
    class reverse_iterator{
        public:
            typedef Iter iterator_type	;
            typedef ft::iterator_traits<Iter>::iterator_category iterator_category;
            typedef ft::iterator_traits<Iter>::value_type value_type;
            typedef ft::iterator_traits<Iter>::difference_type difference_type;
            typedef ft::iterator_traits<Iter>::pointer pointer;
            typedef ft::iterator_traits<Iter>::reference reference;
            reverse_iterator():current(){}
            explicit reverse_iterator(iterator_type x ):current(x){}
            template< class U >
            reverse_iterator( const reverse_iterator<U>& other );

    };
}
#endif