#ifndef SET_HPP
# define SET_HPP
#include <functional>
#include <memory>
#include "./rb_tree.hpp"
#include "./rbtree_iterator.hpp"
#include "./pair.hpp"
#include "./reverse_iterator.hpp"
#include "./utils.hpp"

namespace ft {
    template <class Key, class Compare = std::less<Key>,
    class Allocator = std::allocator<Key> >
    class set {
        public:
        // types:
        typedef Key key_type;
        typedef Key value_type;
        typedef Compare key_compare;
        typedef Compare value_compare;
        typedef Allocator allocator_type;
        typedef typename Allocator::reference reference;
        typedef typename Allocator::const_reference const_reference;
        typedef rb_tree_iterator<value_type> iterator;
        typedef const_rb_tree_iterator<value_type> const_iterator;
        typedef std::size_t size_type; // See 23.1
        typedef std::ptrdiff_t difference_type;// See 23.1
        typedef typename Allocator::pointer pointer;
        typedef typename Allocator::const_pointer const_pointer;
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
        // 23.3.3.1 construct/copy/destroy:
        explicit set(const Compare& comp = Compare(), const Allocator& alloc= Allocator()):
        tree(comp),comp(comp),allo(alloc){}
        template <class InputIterator>
        set(InputIterator first, InputIterator last,
        const Compare& comp = Compare(), const Allocator& alloc= Allocator()):tree(comp),comp(comp),allo(alloc){
            insert(first,last);
        }
        set(const set<Key,Compare,Allocator>& x):tree(x.tree),comp(x.comp),allo(x.allo){
        }
        ~set(){}
        set<Key,Compare,Allocator>& operator=
        (const set<Key,Compare,Allocator>& x){
            tree = x.tree;
            comp= x.comp;
            allo = x.allo;
            return *this;
        }
        allocator_type get_allocator() const{return allo;}
        // iterators:
        iterator begin(){return tree.begin();}
        const_iterator begin() const{return tree.begin();}
        iterator end(){return tree.end();}
        const_iterator end() const{return tree.end();}
        reverse_iterator rbegin(){return tree.rbegin();}
        const_reverse_iterator rbegin() const{return tree.rbegin();}
        reverse_iterator rend(){return tree.rend();}
        const_reverse_iterator rend() const{return tree.rend();}
        // capacity:
        bool empty() const{return (tree.size() == 0);}
        size_type size() const{return (tree.size());}
        size_type max_size() const{return tree.get_node_alloc().max_size();}
        // modifiers:
        pair<iterator,bool> insert(const value_type& x){return tree.insert(x);}
        iterator insert(iterator position, const value_type& x){return tree.insert(position,x);}
        template <class InputIterator>
        void insert(InputIterator first, InputIterator last){
            while (first != last)
            {
                this->insert(*first);
                ++first;
            }
        }
        void erase(iterator position){tree.erase(position);}
        size_type erase(const key_type& x){return tree.erase(x);}
        void erase(iterator first, iterator last){tree.erase(first, last);}
        void swap(set<Key,Compare,Allocator>&x){tree.swap(x.tree);}
        void clear(){tree.clear();};
        // observers:
        key_compare key_comp() const{return comp;}
        value_compare value_comp() const{return comp;}
        // set operations:
        iterator find(const key_type& x) {return tree.find(x);}
        const_iterator find( const key_type& x ) const{return tree.find(x);}
        size_type count(const key_type& x) const{return tree.count(x);}
        iterator lower_bound(const key_type& x) {return tree.lower_bound(x);}
        iterator upper_bound(const key_type& x) {return tree.upper_bound(x);}
        const_iterator lower_bound(const key_type& x) const{return tree.lower_bound(x);}
        const_iterator upper_bound(const key_type& x) const{return tree.upper_bound(x);}
        pair<iterator,iterator> equal_range(const key_type& x){return ft::make_pair(lower_bound(x), upper_bound(x));}
        pair<const_iterator,const_iterator> equal_range(const key_type& x) const{return ft::make_pair(lower_bound(x), upper_bound(x));}
        private:
            rb_tree<value_type, key_compare, Allocator>	tree;
            key_compare comp; 
            allocator_type allo;       
        

        friend bool operator==(const set<Key,Compare,Allocator>& x, const set<Key,Compare,Allocator>& y){
            return x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin());
        }

        friend bool operator< (const set<Key,Compare,Allocator>& x, const set<Key,Compare,Allocator>& y){
            return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
        }

        friend bool operator!=(const set<Key,Compare,Allocator>& x, const set<Key,Compare,Allocator>& y){
            return !(x == y);
        }

        friend bool operator> (const set<Key,Compare,Allocator>& x, const set<Key,Compare,Allocator>& y){
            return (y < x);
        }

        friend bool operator>=(const set<Key,Compare,Allocator>& x, const set<Key,Compare,Allocator>& y){
            return !(x < y);
        }

        friend bool operator<=(const set<Key,Compare,Allocator>& x, const set<Key,Compare,Allocator>& y){
            return !(y < x);
        }
    };
        // specialized algorithms:
    template <class Key, class Compare, class Allocator>
    void swap(set<Key,Compare,Allocator>& x, set<Key,Compare,Allocator>& y){x.swap(y);}
}
#endif