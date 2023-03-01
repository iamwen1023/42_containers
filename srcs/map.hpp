#ifndef MAP_HPP
#define MAP_HPP
#include <functional>
#include "./rb_tree.hpp"
#include "./rbtree_iterator.hpp"
#include "./pair.hpp"
#include "./reverse_iterator.hpp"

namespace ft {

    template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
    class map {
        public:
        // types:
            typedef std::size_t         size_type;
            typedef std::ptrdiff_t      difference_type;
            typedef Key                 key_type;
            typedef T                   mapped_type;
            typedef ft::pair<const Key, T>  value_type;
            typedef Compare             key_compare;
            typedef Allocator           allocator_type;
            typedef typename Allocator::reference   reference;
            typedef typename Allocator::const_reference const_reference;
            typedef typename Allocator::pointer pointer;
            typedef typename Allocator::const_pointer   const_pointer;
            typedef rb_tree_iterator<value_type> iterator;
            typedef const_rb_tree_iterator<value_type> const_iterator;
            typedef ft::reverse_iterator<iterator> reverse_iterator;
            typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
            class value_compare : public std::binary_function<value_type,value_type,bool> {
                friend class map;
                protected:
                    Compare comp;
                    value_compare(Compare c) : comp(c) {}
                public:
                    // This so the RBTree can construct the class
                    //value_compare(void) : comp(Compare()) {}
                    bool operator()(const value_type& x, const value_type& y) const {
                        return comp(x.first, y.first);
                    }
            };
            typedef value_compare compare_type;
            typedef rb_tree<value_type, compare_type, Allocator> tree_type;
             // 23.3.1.1 construct/copy/destroy:
            explicit map(const Compare& comp = Compare(), const Allocator& = Allocator()): tree(comp){
                
            }
            template <class InputIterator>
            map(InputIterator first, InputIterator last, const Compare& comp = Compare(), const Allocator& = Allocator()){
                
            }
            map(const map<Key,T,Compare,Allocator>& x){

            }
            ~map(){

            }
            map<Key,T,Compare,Allocator>& operator=(const map<Key,T,Compare,Allocator>& x){

            }
            // iterators:
            iterator begin(){tree->begin();}
            const_iterator begin() const {tree->begin();}
            iterator    end(){tree->end();}
            const_iterator end() const{tree->end();}
            reverse_iterator rbegin(){tree->rbegin();}
            const_reverse_iterator rbegin() const{tree->rbegin();}
            reverse_iterator rend(){tree->rend();}
            const_reverse_iterator rend() const{tree->rend();}
            // capacity:
            bool empty() const{return (tree->node_count == 0);}
            size_type size() const{return tree->node_count;}
            size_type max_size() const {return tree->node_alloc.max_size();}
            // 23.3.1.2 element access:
            T& operator[](const key_type& x){

            }
            // modifiers:
            pair<iterator, bool> insert(const value_type& x);
            iterator insert(iterator position, const value_type& x);
            template <class InputIterator>
            void insert(InputIterator first, InputIterator last);
            void erase(iterator position);
            size_type erase(const key_type& x);
            void erase(iterator first, iterator last);
            void swap(map<Key,T,Compare,Allocator>&);
            void clear();
            // observers:
            key_compare key_comp() const{return tree->comp;}
            value_compare value_comp() const{return value_compare(tree->comp);}
            // 23.3.1.3 map operations:
            iterator find(const key_type& x){ return tree->find(x, mapped_type());}
            const_iterator find(const key_type& x) const;
            size_type count(const key_type& x) const;
            iterator    lower_bound(const key_type& x);
            const_iterator lower_bound(const key_type& x) const;
            iterator upper_bound(const key_type& x);
            const_iterator upper_bound(const key_type& x) const;
            pair<iterator,iterator> equal_range(const key_type& x);
            pair<const_iterator,const_iterator> equal_range(const key_type& x) const;
        private:
            tree_type tree;

    };
    template <class Key, class T, class Compare, class Allocator>
    bool operator==(const map<Key,T,Compare,Allocator>& x, \
    const map<Key,T,Compare,Allocator>& y);
    template <class Key, class T, class Compare, class Allocator>
    bool operator< (const map<Key,T,Compare,Allocator>& x, \
    const map<Key,T,Compare,Allocator>& y);
    template <class Key, class T, class Compare, class Allocator>
    bool operator!=(const map<Key,T,Compare,Allocator>& x, \
    const map<Key,T,Compare,Allocator>& y);
    template <class Key, class T, class Compare, class Allocator>
    bool operator> (const map<Key,T,Compare,Allocator>& x, \
    const map<Key,T,Compare,Allocator>& y);
    template <class Key, class T, class Compare, class Allocator>
    bool operator>=(const map<Key,T,Compare,Allocator>& x, \
    const map<Key,T,Compare,Allocator>& y);
    template <class Key, class T, class Compare, class Allocator>
    bool operator<=(const map<Key,T,Compare,Allocator>& x, \
    const map<Key,T,Compare,Allocator>& y);
    // specialized algorithms:
    template <class Key, class T, class Compare, class Allocator>
    void swap(map<Key,T,Compare,Allocator>& x, map<Key,T,Compare,Allocator>& y);

}

#endif