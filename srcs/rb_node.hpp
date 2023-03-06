#ifndef RB_NODE_HPP
#define RB_NODE_HPP

enum color_type {RED, BLACK,TNULL};
template <class Value>
struct rb_tree_node{
    typedef rb_tree_node<Value>* base_ptr;
    color_type color;
    base_ptr parent;
    base_ptr left;
    base_ptr right;
    Value value_field;

    rb_tree_node(void): parent(NULL), left(NULL), right(NULL),color(BLACK){
    }
    rb_tree_node(Value value): parent(NULL), left(NULL), right(NULL),color(RED), value_field(value){
    }

    static base_ptr minimum(base_ptr x){
        while(x->left != 0 && x->color != TNULL)
            x = x->left;
        return x;
    }
    static base_ptr maximum(base_ptr x){
        while(x->right != 0 && x->color != TNULL)
            x =  x->right;
        return x;
    }
};
#endif