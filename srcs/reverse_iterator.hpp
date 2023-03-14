#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP
#include "./iterator_traits.hpp"
#include <memory>
#include <iostream>
namespace ft {
    template< class Iter >
    class reverse_iterator{
        public:
            typedef Iter iterator_type	;
            typedef typename ft::iterator_traits<Iter>::iterator_category iterator_category;
            typedef typename ft::iterator_traits<Iter>::value_type value_type;
            typedef typename ft::iterator_traits<Iter>::difference_type difference_type;
            typedef typename ft::iterator_traits<Iter>::pointer pointer;
            typedef typename ft::iterator_traits<Iter>::reference reference;

            //contruct
            reverse_iterator():current(){}
            explicit reverse_iterator(iterator_type x ):current(x){
                //std::cout << "hello!" << std::endl;
            }
            template< class U >
            reverse_iterator( const reverse_iterator<U>& other ):current(other.base()){}
            //operator=
            template< class U >
            reverse_iterator& operator=( const reverse_iterator<U>& other ){
                this->current = other.base();
                return *this;
            }
            iterator_type base() const{
                return this->current;
            }
            reference operator*() const{
                Iter tmp = current; 
                return *--tmp;
            }
            pointer operator->() const{
                return std::addressof(operator*());
            }
            reference operator[]( difference_type n ) const{
                // if (n < 0 || n >= container.size()) {
                //     throw std::out_of_range("Index out of bounds");
                // }
                return base()[-n-1];//why always postive?
            }
            reverse_iterator& operator++(){
                --this->current;
                return (*this);
            }
            reverse_iterator& operator--(){
                ++this->current;
                return (*this);
            }
            reverse_iterator operator++(int){
                reverse_iterator tmp(*this);
                --this->current;
                return (tmp);
            }
            reverse_iterator operator--(int){
                reverse_iterator tmp(*this);
                ++this->current;
                return (tmp);
            }
            reverse_iterator operator+( difference_type n ) const{
                return reverse_iterator(base()-n);
            }
            reverse_iterator operator-( difference_type n ) const{
                return reverse_iterator(base()+n);
            }
            reverse_iterator& operator+=( difference_type n ){
                this->current = this->current - n;
                return (*this);
            }
            reverse_iterator& operator-=( difference_type n ){
                this->current = this->current + n;
                return (*this);
            }
        protected:
            iterator_type current;
    };
    template< class Iterator1, class Iterator2 >
    bool operator==( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs ){
        return (lhs.base() == rhs.base());}
    template< class Iterator1, class Iterator2 >
    bool operator!=( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs ){
        return (lhs.base() != rhs.base());}
    template< class Iterator1, class Iterator2 >
    bool operator<( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs ){
        return (lhs.base() > rhs.base());}
    template< class Iterator1, class Iterator2 >
    bool operator<=( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs ){
        return (lhs.base() >= rhs.base());}
    template< class Iterator1, class Iterator2 >
    bool operator>( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs ){
        return (lhs.base() < rhs.base());}
    template< class Iterator1, class Iterator2 >
    bool operator>=( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs ){
        return (lhs.base() <= rhs.base());}
    template< class Iter>
    reverse_iterator<Iter> operator+( typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it ){
        return reverse_iterator<Iter>(it.base() - n);
    }
    template< class Iterator1, class Iterator2 >
    typename reverse_iterator<Iterator1>::difference_type operator-( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs){
        return reverse_iterator<Iterator1>(lhs.base() - rhs.base());
    }

}
#endif