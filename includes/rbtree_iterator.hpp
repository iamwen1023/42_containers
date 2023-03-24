#ifndef RBTREE_ITERATOR_HPP
#define RBTREE_ITERATOR_HPP
#include "./rb_tree.hpp"
#include "./iterator_traits.hpp"
namespace ft {
    template<class Value>
    struct rb_tree_iterator {
        typedef ft::bidirectional_iterator_tag iterator_category;
        typedef Value value_type;
        typedef value_type* pointer;
        typedef value_type& reference;
        typedef typename rb_tree_node<Value>::base_ptr base_ptr;
        typedef rb_tree_iterator<Value> iterator;
        typedef std::ptrdiff_t						difference_type;

        base_ptr node;

        rb_tree_iterator(){}
        explicit rb_tree_iterator(base_ptr x): node(x){}
        rb_tree_iterator(const iterator& it):node(it.node){}

        base_ptr successor(base_ptr x){
            if(x->right->if_tnull != true){
                x = x->right;
                while(x->left->if_tnull != true)
                    x = x->left;     
            } else{
                base_ptr y = x->parent;
                while(x == y->right){
                    x = y;
                    y = y->parent;
                }
                if (x->right != y){ //y=header
                    x = y;  
                }
            }
            return x;
        }
        base_ptr  predecessor(base_ptr x){
            if (x->color == RED && x->parent->parent == x){// when node = header , when node = end()
                x = x->right;
            }else if(x->left->if_tnull != true){
                x = x->left;
                while(x->right->if_tnull != true)
                    x = x->right;  
            } else {
                base_ptr y = x->parent;
                while(x == y->left){
                    x = y;
                    y = y->parent;
                }
                x = y;
            }
            return x;
        }
        reference operator*() const{return base_ptr(node)->value_field;}
        pointer operator->()const{return &(operator*());}

        iterator& operator++(){ this->node = successor(this->node); return *this;}
        iterator operator++(int){
            iterator tmp = *this;
            this->node = successor(this->node);
            return tmp;
        }
        iterator& operator--(){this->node = predecessor(node);return *this;}
        iterator operator--(int){
            iterator tmp = *this;
            this->node = predecessor(node);
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
        typedef std::ptrdiff_t						difference_type;

        base_ptr node;

        const_rb_tree_iterator():node(NULL){}
        explicit const_rb_tree_iterator(base_ptr x):node(x){}
        //const_rb_tree_iterator(const base_ptr x):node(x){}
        const_rb_tree_iterator(const rb_tree_iterator<Value>& it):node(it.node){}
    
        base_ptr successor(base_ptr x){
            if(x->right->if_tnull != true){
                x = x->right;
                while(x->left->if_tnull != true)
                    x = x->left;     
            } else{
                base_ptr y = x->parent;
                while(x == y->right){
                    x = y;
                    y = y->parent;
                }
                if (x->right != y){ //y=header
                    x = y;  
                }
            }
            return x;
        }
        base_ptr  predecessor(base_ptr x){
            if (x->color == RED && x->parent->parent == x){// when node = header , when node = end()
                x = x->right;
            }else if(x->left->if_tnull != true){
                x = x->left;
                while(x->right->if_tnull != true)
                    x = x->right;  
            } else {
                base_ptr y = x->parent;
                while(x == y->left){
                    x = y;
                    y = y->parent;
                }
                x = y;
            }
            return x;
        }
        reference operator*() const{return base_ptr(node)->value_field;}
        pointer operator->()const{return &(operator*());}

        const_iterator& operator++(){ this->node = successor(this->node); return *this;}
        const_iterator operator++(int){
            const_iterator tmp = *this;
            this->node = successor(this->node);
            return tmp;
        }
        const_iterator& operator--(){this->node = predecessor(node);return *this;}
        const_iterator operator--(int){
            const_iterator tmp = *this;
            this->node = predecessor(node);
            return tmp;
        }
    
        friend bool operator==(const const_iterator &x, const const_iterator &y){
            return x.node == y.node;
        }
        friend bool operator!=(const const_iterator &x, const const_iterator &y){
            return x.node != y.node;
        }

    };

        template <typename T, typename U>
        bool operator==(const rb_tree_iterator<T> &x, const const_rb_tree_iterator<U> &y){
            return x.node == y.node;
        }
        template <typename T, typename U>
        bool operator!=(const rb_tree_iterator<T> &x, const const_rb_tree_iterator<U> &y){
            return x.node != y.node ;
        }
        template <typename T, typename U>
        bool operator==(const const_rb_tree_iterator<T> &x, const rb_tree_iterator<U>&y){
            return x.node == y.node;
        }
        template <typename T, typename U>
        bool operator!=(const const_rb_tree_iterator<T> &x, const rb_tree_iterator<U> &y){
            return x.node != y.node;
        }

}



#endif