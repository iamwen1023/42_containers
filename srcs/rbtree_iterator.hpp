#ifndef RBTREE_ITERATOR_HPP
#define RBTREE_ITERATOR_HPP
#include "./rb_tree.hpp"
#include <iterator>
#include "./iterator_traits.hpp"

///predecessor()??? 
template<class Value>
struct rb_tree_iterator {
    typedef ft::bidirectional_iterator_tag iterator_category;
    typedef Value value_type;
    typedef value_type* pointer;
    typedef value_type& reference;
    typedef typename rb_tree_node<Value>::base_ptr base_ptr;
    typedef rb_tree_iterator<Value> iterator;

    base_ptr node;

    rb_tree_iterator(){}
    rb_tree_iterator(base_ptr x): node(x){}
    rb_tree_iterator(const iterator& it):node(it.node){}
    //bool operator==(const iterator& y) const { return node == y.node; }

    base_ptr minimum(base_ptr x){
        while(x->left->if_tnull != true){
            x = x->left;
        }       
        return x;
    }
    base_ptr maximum(base_ptr x){
        while(x->right->if_tnull != true)
            x =  x->right;
        return x;
    }
    void successor(){
        if(node->right->if_tnull != true){
            node =  minimum(node->right);
            return ;
        }
        base_ptr y = node->parent;
        while(node == y->right){
            node = y;
            y = y->parent;
        }
        if (node->right != y){ //y=header
            node = y;  
        }
    }
    void predecessor(){
        if (node->color == RED && node->parent->parent == node){// when node = header , when node = end()
            node = node->right;
        }else if(node->left->if_tnull != true){
            node = maximum(node->left);
        } else {
            base_ptr y = node->parent;
            while(node == y->left){
                node = y;
                y = y->parent;
            }
            node = y;
        }
    }
    reference operator*() const{return base_ptr(node)->value_field;}
    pointer operator->()const{return &(operator*());}

    iterator& operator++(){successor(); return *this;}
    iterator operator++(int){
        iterator tmp = *this;
        successor();
        return tmp;
    }
    iterator& operator--(){predecessor();return *this;}
    iterator operator--(int){
        iterator tmp = *this;
        predecessor();
        return tmp;
    }
    friend bool operator==(const iterator &x, const iterator &y){
        return x.node == y.node;
    }
    friend bool operator!=(const iterator &x, const iterator &y){
        return x.node != y.node;
    }
};

template<class Value>
struct const_rb_tree_iterator {
    typedef ft::bidirectional_iterator_tag iterator_category;
    typedef Value value_type;
    
    typedef const value_type& reference;
    typedef const value_type* pointer;
    typedef typename rb_tree_node<Value>::base_ptr base_ptr;
    typedef const_rb_tree_iterator<Value> const_iterator;

    base_ptr node;

    const_rb_tree_iterator():node(NULL){}
    const_rb_tree_iterator(const base_ptr x):node(x){}
    //const_rb_tree_iterator(const const_iterator& it):node(it.node){}
    const_rb_tree_iterator(const rb_tree_iterator<Value>& it):node(it.node){}
    bool operator==(const const_iterator& y) const { return node == y.node; }
    base_ptr minimum(base_ptr x){
        while(x->left->if_tnull != true){
            x = x->left;
        }       
        return x;
    }
    base_ptr maximum(base_ptr x){
        while(x->right->if_tnull != true)
            x =  x->right;
        return x;
    }
    void successor()const{
        if(node->right->if_tnull != true){
            node =  minimum(node->right);
            return ;
        }
        base_ptr y = node->parent;
        while(node == y->right){
            node = y;
            y = y->parent;
        }
        if (node->right != y){ //y=header
            node = y;  
        }
    }
    void predecessor()const{
        if (node->color == RED && node->parent->parent == node){
            node = node->right;
        }else if(node->left->if_tnull != true){
            node = maximum(node->left);
        } else {
            base_ptr y = node->parent;
            while(node == y->left){
                node = y;
                y = y->parent;
            }
            node = y;
        }
    }
    reference operator*() const{return base_ptr(node)->value_field;}
    pointer operator->()const{return &(operator*());}

    const_iterator& operator++(){ successor(); return *this;}
    const_iterator operator++(int) {
        const_iterator tmp = *this;
        successor();
        return tmp;
    }
    const_iterator& operator--(){
        std::cout << "here?--\n";
        predecessor(); return *this;}
    const_iterator operator--(int){
        std::cout << "here?@@\n";
        const_iterator tmp = *this;
        predecessor();
        return tmp;
    }
    friend bool operator==(const const_iterator &x, const const_iterator &y){
        return x.node == y.node;
    }
    friend bool operator!=(const const_iterator &x, const const_iterator &y){
        return x.node != y.node;
    }
};


#endif