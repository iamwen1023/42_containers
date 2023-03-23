#ifndef MAP_HPP
#define MAP_HPP
#include <functional>
#include "./rb_tree.hpp"
#include "./rbtree_iterator.hpp"
#include "./pair.hpp"
#include "./reverse_iterator.hpp"
#include "./utils.hpp"

namespace ft {

    template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
    class map {
        public:
        // types:
            typedef std::size_t         size_type;
            typedef std::ptrdiff_t      difference_type;
            typedef Key                 key_type;
            typedef T                   mapped_type;
            typedef ft::pair<const key_type, mapped_type>  value_type;
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
                    bool operator()(const value_type& x, const value_type& y) const {
                        return comp(x.first, y.first);
                    }
            };
            typedef value_compare compare_type;
             // 23.3.1.1 construct/copy/destroy:
            explicit map(const value_compare& comp=value_compare(key_compare()), const Allocator& = Allocator()): tree(comp), compare(key_compare()), allo(Allocator){}
            template <class InputIterator>
            map(InputIterator first, InputIterator last, const value_compare& comp=value_compare(key_compare()), const Allocator& = Allocator()): tree(comp), compare(key_compare()):allo(Allocator){
                this->insert(first, last);
            }
            map(const map<Key,T,Compare,Allocator>& x): tree(x.tree),compare(x.compare),allo(x.allo)){}
            ~map(){}
            map<Key,T,Compare,Allocator>& operator=(const map<Key,T,Compare,Allocator>& x){
                tree = x.tree;
                compare = x.compare;
                allo = x.allo;
                return *this;
            }
            
            // iterators:
            iterator begin(){return tree.begin();}
            const_iterator begin() const {return tree.begin();}
            iterator    end(){return tree.end();}
            const_iterator end() const{return tree.end();}
            reverse_iterator rbegin(){return tree.rbegin();}
            const_reverse_iterator rbegin() const{return tree.rbegin();}
            reverse_iterator rend(){return tree.rend();}
            const_reverse_iterator rend() const{return tree.rend();}
            // capacity:
            bool empty() const{return (tree.size() == 0);}
            size_type size() const{return (tree.size());}
            size_type max_size() const {return tree.get_node_alloc().max_size();}
            // 23.3.1.2 element access:
            T& operator[](const key_type& x){
                return (*(tree.insert(ft::make_pair(x, mapped_type())).first)).second;
            }
            // modifiers:
            pair<iterator, bool> insert(const value_type& x){return tree.insert(x);}
            iterator insert(iterator position, const value_type& x){return tree.insert(position, x);}
            template <class InputIterator>
            void insert(InputIterator first, InputIterator last){
                // return tree.insert_range(first, last);
                 while (first != last)
                {
                    this->insert(*first);
                    ++first;
                }
            }
            void erase(iterator position){tree.erase(position);}
            size_type erase(const key_type& x){return tree.erase(ft::make_pair(x, mapped_type()));}
            void erase(iterator first, iterator last){tree.erase(first, last);}
            void swap(map<Key,T,Compare,Allocator>&x){tree.swap(x.tree);}
            void clear(){
                tree.clear();}
            // observers:
            allocator_type get_allocator() const{return allo;}
            key_compare key_comp() const{return this->compare;}
            value_compare value_comp() const{return value_compare(tree.get_comp());}
            // 23.3.1.3 map operations:
            iterator find(const key_type& x){ return tree.find(ft::make_pair(x, mapped_type()));}
            const_iterator find(const key_type& x) const{return tree.find(ft::make_pair(x, mapped_type()));}
            size_type count(const key_type& x) const{ return tree.count(ft::make_pair(x, mapped_type())); }
            iterator    lower_bound(const key_type& x){return tree.lower_bound(ft::make_pair(x, mapped_type()));}
            const_iterator lower_bound(const key_type& x) const{return tree.lower_bound(ft::make_pair(x, mapped_type()));}
            iterator upper_bound(const key_type& x){return tree.upper_bound(ft::make_pair(x, mapped_type()));}
            const_iterator upper_bound(const key_type& x) const{return tree.upper_bound(ft::make_pair(x, mapped_type()));}
            ft::pair<iterator,iterator> equal_range(const key_type& x){return (ft::pair<iterator, iterator>(this->lower_bound(x), this->upper_bound(x)));}
            ft::pair<const_iterator,const_iterator> equal_range(const key_type& x) const{return (ft::pair<const_iterator, const_iterator>(this->lower_bound(x), this->upper_bound(x)));}
            //void printTreemap(){tree.printTree();}
        private:
            rb_tree<value_type, compare_type, Allocator> tree;
            key_compare     compare;
            allocator_type  allo;
            //void printTreemap(){this->tree.printTree();}
        //template <class Key, class T, class Compare, class Allocator>
        friend bool operator==(const map<Key,T,Compare,Allocator>& x, \
        const map<Key,T,Compare,Allocator>& y){
            return x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin());
        }
        //template <class Key, class T, class Compare, class Allocator>
        friend bool operator< (const map<Key,T,Compare,Allocator>& x, \
        const map<Key,T,Compare,Allocator>& y){
            return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
        }
        //template <class Key, class T, class Compare, class Allocator>
        friend bool operator!=(const map<Key,T,Compare,Allocator>& x, \
        const map<Key,T,Compare,Allocator>& y){
            return !(x == y);
        }
        //template <class Key, class T, class Compare, class Allocator>
        friend bool operator> (const map<Key,T,Compare,Allocator>& x, \
        const map<Key,T,Compare,Allocator>& y){
            return (y < x);
        }
        //template <class Key, class T, class Compare, class Allocator>
        friend bool operator>=(const map<Key,T,Compare,Allocator>& x, \
        const map<Key,T,Compare,Allocator>& y){
            return !(x < y);
        }
        //template <class Key, class T, class Compare, class Allocator>
        friend bool operator<=(const map<Key,T,Compare,Allocator>& x, \
        const map<Key,T,Compare,Allocator>& y){
            return !(y < x);
        }

    };
    
    // specialized algorithms:
    template <class Key, class T, class Compare, class Allocator>
    void swap(map<Key,T,Compare,Allocator>& x, map<Key,T,Compare,Allocator>& y){x.swap(y);}

}

#endif