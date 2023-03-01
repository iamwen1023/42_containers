#ifndef RB_TREE_HPP
#define RB_TREE_HPP
#include <functional>
#include <memory>
#include <iostream>
#include "./rb_node.hpp"
#include "./rbtree_iterator.hpp"

template <class Value, class Compare, class allocator>
class rb_tree{
    //protected:
    public:

        //allocator
        typedef typename allocator::template rebind<rb_tree_node<Value> >::other node_allocator;
    
        typedef Value value_type;
        typedef Compare key_compare;
        typedef value_type& reference;
        // typedef const value_type& const_reference;
        typedef rb_tree_node<Value> node_type;
        typedef node_type           *node_ptr;
        typedef size_t size_type;
        // typedef ptrdiff_t difference_type;
        //Iterators
        typedef rb_tree_iterator<node_type>                       iterator;
        typedef const_rb_tree_iterator<node_type>                 const_iterator;
    //protected:
        node_ptr       root;
        node_ptr       header;
        node_ptr       tnull;
        size_type       node_count;
        key_compare     comp;
        node_allocator  node_alloc;
        
        void init(){
            tnull = node_alloc.allocate(1);
            tnull->color = BLACK;
            tnull->left = NULL;
            tnull->right = NULL;
            tnull->parent = NULL;
            tnull->value_field = Value();
            root = NULL;
            header = node_alloc.allocate(1);
            header->color = RED;
            header->left = header;
            header->right = header;
            header->parent = root;
        }
        node_type& leftmost() { return left(header); }
        node_type& leftmost() const { return left(header); }
        node_type& rightmost() { return right(header); }
        node_type& rightmost() const { return right(header); }
        //construct
        rb_tree(const key_compare & comp= Compare()):node_count(0),comp(comp), node_alloc(node_allocator()){
            init();
        }
        rb_tree(const value_type* first, const value_type* last, const Compare& comp = Compare())
          : node_count(0), comp(comp), node_alloc(node_allocator()){ 
            init();
            insert(first, last);
        }
        ~rb_tree(){
            clear_tree(root);
            node_alloc.destroy(tnull);
            node_alloc.deallocate(tnull, 1);

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
        iterator begin() { return iterator(leftmost()); }
        const_iterator begin() const { return const_iterator(leftmost()); }
        iterator end() { return iterator(header); }
        const_iterator end() const { return const_iterator(header); }
        iterator rbegin() { return reverse_iterator(end()); }
        const_iterator rbegin() const { return const_reverse_iterator(end()); }
        iterator rend() { return reverse_iterator(begin()); }
        const_iterator rend() const { return const_reverse_iterator(begin()); }
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

        void insert_range(const value_type* first, const value_type* last){

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

        void rbTransplant(node_ptr u, node_ptr v){
            if(u->parent == NULL){
                root = v;
            } else if(u == u->parent->left){
                u->parent->left = v;
            } else {
                u->parent->right = v;
            }
            v->parent = u->parent;
        }
        // void deleteNode(node_ptr node, value_type& to_delete){
        //     node_ptr z = tnull;
        //     node_ptr x, y;
        //     while (node != tnull){
        //         if(node->value_field)
        //     }
        // }


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
            if (subtree && subtree != tnull){
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


#endif