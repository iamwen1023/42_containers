#ifndef MAP_HPP
#define MAP_HPP
#include <functional>
#include <memory>
#include <iostream>
#include <map>
enum color_type {RED, BLACK};

template <class Value>
struct rb_tree_node{
    typedef rb_tree_node* base_ptr;
    color_type color;
    base_ptr parent;
    base_ptr left;
    base_ptr right;
    Value value_field;

    rb_tree_node(void): parent(NULL), left(NULL), right(NULL),color(BLACK){
        std::cout << "defalut node\n";// why not here for tnull?
    }
    rb_tree_node(Value value): parent(NULL), left(NULL), right(NULL),color(RED), value_field(value){
        std::cout << "Not defalut node\n";
    }

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

template <class Value, class Compare>
class rb_tree{
    //protected:
    public:

        typedef typename std::allocator<Value>::template rebind<rb_tree_node<Value> >::other node_allocator;
    
        typedef Value value_type;
        typedef Compare compare_type;
        typedef value_type& reference;
        // typedef const value_type& const_reference;
        typedef rb_tree_node<Value> node_type;
        typedef node_type           *node_ptr;
        typedef size_t size_type;
        // typedef ptrdiff_t difference_type;
    //protected:
        node_ptr       root;
        node_ptr       tnull;
        size_type       node_count;
        compare_type    comp;
        node_allocator  node_alloc;

        

        //construct
        rb_tree(const compare_type& comp= Compare()):node_count(0),comp(comp), node_alloc(node_allocator()){
            // tnull =  node_ptr();
            tnull = node_alloc.allocate(1);
            tnull->color = BLACK;
            tnull->left = NULL;
            tnull->right = NULL;
            tnull->parent = NULL;
            tnull->value_field = Value();
            root = tnull;
        }
        ~rb_tree(){
            //clear_tree(root);
            // node_alloc.destroy(tnull);
            // node_alloc.deallocate(tnull, 1);

        }
        node_type *creat_node(const value_type& x){
            node_type *new_node = node_alloc.allocate(1);
            node_alloc.construct(new_node, x);
            new_node->left = tnull;
            new_node->right = tnull;
            return new_node;
        }
        void put_node(node_ptr node){
            node_alloc.destroy(node);
            node_alloc.deallocate(node, 1);
        }

        void leftRotate(node_ptr x){
            node_ptr y = x->right;
            x->right = y->left;
            if( y->left != tnull)
                y->left->parent = x;
            y->parent = x->parent;
            if(x->parent == NULL)
                this->root = y;
            else if(x == x->parent->left)
                x->parent->left = y;
            else
                x->parent->right = y;
            y->left = x;
            x->parent = y;
        }
        void rightRotate(node_ptr x){
            node_ptr y = x->left;
            x->left = y->right;
            if(y->right != tnull)
                y->right->parent = x;
            y->parent = x->parent;
            if(x->parent == NULL)
                this->root = x;
            else if (x == x->parent->left)
                x->parent->left = y;
            else
                x->parent->right = y;
            y->right = x;
            x->parent = y;
        }
        void insert(const value_type& new_value){
            node_type *new_node = creat_node(new_value);
            node_type *y = NULL;
            node_type *x = root;
            while (x != tnull){
                y = x;
                if(comp(new_node->value_field, x->value_field) == true){
                    x = x->left;
                } else if (comp(new_node->value_field, x->value_field) == false && (comp(x->value_field ,new_node->value_field) == false)){
                    std::cout << "inside value is the same" << std::endl;
                    put_node(new_node);
                    return ;
                } else {
                    x = x->right;
                }
            }
            new_node->parent = y;
            if ( y == NULL){
                root = new_node;
            } else if (comp(new_node->value_field, y->value_field)){
                y->left = new_node;
            } else {
                y->right = new_node;
            }
            if (new_node->parent == NULL){
                new_node->color = BLACK;
                return ;
            }
            if (new_node->parent->parent == NULL)
                return;
            ++node_count;
            insertFIX(new_node);
        }

        void    insertFIX(node_ptr node){
            node_ptr u;

            while(node->parent->color == RED){
                if (node->parent == node->parent->parent->right){
                    u = node->parent->parent->left;
                    if(u->color == RED){
                        u->color = BLACK;
                        node->parent->color = RED;
                        node->parent->parent->color = BLACK;
                        node = node->parent->parent;
                    } else {
                        if (node == node->parent->left){
                            node = node->parent;
                            rightRotate(node);
                        }
                        node->parent->color = BLACK;
                        node->parent->parent->color = RED;
                        leftRotate(node->parent->parent);
                    }
                } else {
                    u = node->parent->parent->right;
                    if(u->color == RED){
                        u->color = BLACK;
                        node->parent->color = RED;
                        node->parent->parent->color = BLACK;
                        node =  node->parent->parent;
                    } else {
                        if (node == node->parent->right){
                            node = node->parent;
                            leftRotate(node);
                        }
                        node->parent->color = BLACK;
                        node->parent->parent->color = RED;
                        rightRotate(node->parent->parent);
                    }
                }
                if (node == root)
                    break ;
            }
            root->color = BLACK;
        }

        void    printTree() {
            if (root) 
                printHelper(this->root, "", true);
            else 
                std::cout << "not root!\n";
        }
        void printHelper(node_ptr root, std::string indent, bool last) {
            if (root != 0) {
                    std::cout << indent;
                if (last) {
                    std::cout << "R----";
                    indent += "   ";
                } else {
                    std::cout << "L----";
                    indent += "|  ";
                }

            std::string sColor = root->color ? "RED" : "BLACK";
            std::cout << root->value_field.first << "|"  << root->value_field.second <<  "(" << sColor << ")" << std::endl;
            printHelper(root->left, indent, false);
            printHelper(root->right, indent, true);
            }
        }
        void clear_tree(node_ptr subtree){
            if (subtree){
                node_ptr next_left = subtree->left;
                node_ptr next_right = subtree->right;
                node_alloc.destroy(subtree);
                node_alloc.deallocate(subtree, 1);
                node_count--;
                clear_tree(next_left);
                clear_tree(next_right);
            }
        }
};

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