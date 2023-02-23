#ifndef MAP_HPP
#define MAP_HPP
#include <functional>
#include <memory>

template <class Value>
struct rb_tree_node{
    typedef rb_tree_node* base_ptr;
    enum color_type {RED, BLACK};
    color_type color;
    base_ptr parent;
    base_ptr left;
    base_ptr right;
    Value value_field;

    static base_ptr minimum(base_ptr x){
        while(x->left != 0)
            x = x->left;
        return x;
    }
    static base_ptr maximum(base_ptr x){
        while(x->right != 0)
            x =  x->right;
        return x;
    } 
};

template <class Key, class Value, class KeyOfValue, class Compare = std::less<Value>>
class rb_tree{
    protected:

        typedef rb_tree_node<Value> rb_tree_node;
        typedef typename std::allocator::template rebind<rb_tree_node<Value>>::other node_allocator;
    public:
        typedef Value value_type;
        typedef Key key_type;
        typedef value_type* pointer;
        typedef const value_type const_pointer;
        typedef value_type& reference;
        typedef const value_type& const_reference;
        typedef rb_tree_node* link_type;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
    protected:
        link_type       root;
        link_type       tnull;
        size_type       node_count;
        Compare         comp;
        node_allocator  node_alloc;

        void init(){

        }

        //construct
        rb_tree(const Compare& comp= Compare): root(NULL), node_count(0),comp(comp), node_alloc(node_allocator()){}
        link_type creat_node(const value_type& x){
            link_type new = node_alloc.allocator(1);
            node_alloc.construct(&new->value_field, x)
            return new;
        }
        void insert(const value_type& x){
            link_type y = 0;
            link_type x = root;
            if(root != NULL){
                y =x;
                if()
            }
        }

        void printTree() {
            if (root) 
                printHelper(this->root, "", true);
        }
        void printHelper(NodePtr root, string indent, bool last) {
            if (root != 0) {
                    cout << indent;
                if (last) {
                    cout << "R----";
                    indent += "   ";
                } else {
                    cout << "L----";
                    indent += "|  ";
                }

            string sColor = root->color ? "RED" : "BLACK";
            cout << root->value_field << "(" << sColor << ")" << endl;
            printHelper(root->left, indent, false);
            printHelper(root->right, indent, true);
            }
        }
}

// namespace ft {

//     template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<pair<const Key, T> >>
//     class map {
//         public:
//         // types:
//             typedef std::size_t         size_type;
//             typedef std::ptrdiff_t      difference_type;
//             typedef Key                 key_type;
//             typedef T                   mapped_type;
//             typedef st::pair<const Key, T>  value_type;
//             typedef Compare             key_compare;
//             typedef Allocator           allocator_type;
//             typedef typename Allocator::reference   reference;
//             typedef typename Allocator::const_reference const_reference;
//             typedef typename Allocator::pointer pointer;
//             typedef typename Allocator::const_pointer   const_pointer;
//             // typedef implementation defined  iterator; // See 23.1
//             // typedef implementation defined  const_iterator; // See 23.1
//             typedef ft::reverse_iterator<iterator> reverse_iterator;
//             typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
//             class value_compare : public binary_function<value_type,value_type,bool> {
//                 friend class map;
//                 protected:
//                     ompare comp;
//                     value_compare(Compare c) : comp(c) {}
//                 public:
//                     bool operator()(const value_type& x, const value_type& y) const {
//                         return comp(x.first, y.first);
//                     }
//             };
//             // 23.3.1.1 construct/copy/destroy:
//             explicit map(const Compare& comp = Compare(), const Allocator& = Allocator());
//             template <class InputIterator>
//             map(InputIterator first, InputIterator last, const Compare& comp = Compare(), const Allocator& = Allocator());
//             map(const map<Key,T,Compare,Allocator>& x);
//             ~map();
//             map<Key,T,Compare,Allocator>& operator=(const map<Key,T,Compare,Allocator>& x);
//             // iterators:
//             iterator begin();
//             const_iterator begin() const;
//             iterator    end();
//             const_iterator end() const;
//             reverse_iterator rbegin();
//             const_reverse_iterator rbegin() const;
//             reverse_iterator rend();
//             const_reverse_iterator rend() const;
//             // capacity:
//             bool empty() const;
//             size_type size() const;
//             size_type max_size() const;
//             // 23.3.1.2 element access:
//             T& operator[](const key_type& x);
//             // modifiers:
//             pair<iterator, bool> insert(const value_type& x);
//             iterator insert(iterator position, const value_type& x);
//             template <class InputIterator>
//             void insert(InputIterator first, InputIterator last);
//             void erase(iterator position);
//             size_type erase(const key_type& x);
//             void erase(iterator first, iterator last);
//             void swap(map<Key,T,Compare,Allocator>&);
//             void clear();
//             // observers:
//             key_compare key_comp() const;
//             value_compare value_comp() const;
//             // 23.3.1.3 map operations:
//             iterator find(const key_type& x);
//             const_iterator find(const key_type& x) const;
//             size_type count(const key_type& x) const;
//             iterator    lower_bound(const key_type& x);
//             const_iterator lower_bound(const key_type& x) const;
//             iterator upper_bound(const key_type& x);
//             const_iterator upper_bound(const key_type& x) const;
//             pair<iterator,iterator> equal_range(const key_type& x);
//             pair<const_iterator,const_iterator> equal_range(const key_type& x) const;
//         private:
//             typedef typename Allocator::value_type alloc_value_type
//             struct tree;

//     };
//     template <class Key, class T, class Compare, class Allocator>
//     bool operator==(const map<Key,T,Compare,Allocator>& x, \
//     const map<Key,T,Compare,Allocator>& y);
//     template <class Key, class T, class Compare, class Allocator>
//     bool operator< (const map<Key,T,Compare,Allocator>& x, \
//     const map<Key,T,Compare,Allocator>& y);
//     template <class Key, class T, class Compare, class Allocator>
//     bool operator!=(const map<Key,T,Compare,Allocator>& x, \
//     const map<Key,T,Compare,Allocator>& y);
//     template <class Key, class T, class Compare, class Allocator>
//     bool operator> (const map<Key,T,Compare,Allocator>& x, \
//     const map<Key,T,Compare,Allocator>& y);
//     template <class Key, class T, class Compare, class Allocator>
//     bool operator>=(const map<Key,T,Compare,Allocator>& x, \
//     const map<Key,T,Compare,Allocator>& y);
//     template <class Key, class T, class Compare, class Allocator>
//     bool operator<=(const map<Key,T,Compare,Allocator>& x, \
//     const map<Key,T,Compare,Allocator>& y);
//     // specialized algorithms:
//     template <class Key, class T, class Compare, class Allocator>
//     void swap(map<Key,T,Compare,Allocator>& x, map<Key,T,Compare,Allocator>& y);

// }

#endif