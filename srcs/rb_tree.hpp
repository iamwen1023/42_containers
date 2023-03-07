#ifndef RB_TREE_HPP
#define RB_TREE_HPP
#include <functional>
#include <memory>
#include <iostream>
#include "./rb_node.hpp"
#include "./rbtree_iterator.hpp"
#include "./pair.hpp"

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
        typedef rb_tree_iterator<value_type>                       iterator;
        typedef const_rb_tree_iterator<value_type>                 const_iterator;
    //protected:
        node_ptr       root;
        node_ptr       header;
        node_ptr       tnull;
        size_type       node_count;
        key_compare     comp;
        node_allocator  node_alloc;
        
        void init(){
            tnull = node_alloc.allocate(1);
            tnull->color = BLACK; //black
            tnull->left = NULL;
            tnull->right = NULL;
            tnull->parent = NULL;
            tnull->if_tnull = true;
            tnull->value_field = Value();
            root = tnull;
            header = node_alloc.allocate(1);
            header->color = RED;
            header->left = header;
            header->right = header;
            header->parent = NULL;  //?
            header->if_tnull = false;
        }
        node_type *creat_node(const value_type& x){
            node_type *new_node = node_alloc.allocate(1);
            node_alloc.construct(new_node, x);
            new_node->left = tnull;
            new_node->right = tnull;
            new_node->color = RED;
            new_node->parent =  NULL;
            new_node->if_tnull = false;
            return new_node;
        }
        void put_node(node_ptr node){
            node_alloc.destroy(node);
            node_alloc.deallocate(node, 1);
        }

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
        node_ptr& leftmost() { return header->left; }
        node_ptr& leftmost() const { return header->left; }
        node_ptr& rightmost() { return header->right; }
        node_ptr& rightmost() const { return header->right; }
        iterator begin() { return iterator(header->left); }
        const_iterator begin() const { return const_iterator(header->left); }
        iterator end() { return iterator(header); }
        const_iterator end() const { return const_iterator(header); }
        iterator rbegin() { return reverse_iterator(end()); }
        const_iterator rbegin() const { return const_reverse_iterator(end()); }
        iterator rend() { return reverse_iterator(begin()); }
        const_iterator rend() const { return const_reverse_iterator(begin()); }
        iterator find(const value_type &k){
            node_ptr x = root;

            while(x != tnull && x != NULL){
                if(comp(x->value_field, k) == false && comp(k, x->value_field) == false)
                    return iterator(x);
                else if (comp(x->value_field, k) == false)
                    x = x->left;  
                else
                     x = x->right;
            }
            return iterator(header);
        }
        const_iterator find(const value_type& k) const{
            node_ptr x = root;

            while(x != tnull && x != NULL){
                if(comp(x->value_field, k) == false && comp(k, x->value_field) == false)
                    return const_iterator(x);
                else if (comp(x->value_field, k) == false)
                    x = x->left;
                else
                    x = x->right;
            }
            return const_iterator(header);
        }
        //std::cout << a.node->value_field.first << "|" << a.node->value_field.second <<"\n";
        iterator    lower_bound(const value_type &k){

            node_ptr x = root;
	        node_ptr y = header; //end()??
	        while ( x != NULL && x != tnull){
	            if (comp(x->value_field, k) ==  false){
                    y = x;
		            x =  x->left;
	            }else{
                    x = x->right;
                }   
            }
            return iterator(y);
        }
        const_iterator lower_bound(const value_type& k) const{
            node_ptr x = root;
	        node_ptr y = header;
	        while ( x != NULL && x != tnull){
	            if (comp(x->value_field, k) ==  false){
                    y = x;
		            x =  x->left;
	            }else{
                    x = x->right;
                }   
            }
            return const_iterator(y);
        }
        iterator upper_bound(const value_type& k) {
            node_ptr x = root;
	        node_ptr y = header;
	        while ( x != NULL && x != tnull){
	            if (comp(x->value_field, k) ==  true){
                    y = x;
		            x =  x->left;
	            }else{
                    x = x->right;
                }   
            }
            return iterator(y);
        }
        const_iterator upper_bound(const value_type& k)const {
            node_ptr x = root;
	        node_ptr y = header;
	        while ( x != NULL && x != tnull){
	            if (comp(x->value_field, k) ==  true){
                    y = x;
		            x =  x->left;
	            }else{
                    x = x->right;
                }   
            }
            return const_iterator(y);
        }
        
        void leftRotate(node_ptr x){
            node_ptr y = x->right;
            x->right = y->left;
            if( y->left != tnull)
                y->left->parent = x;
            y->parent = x->parent;
            //if(x->parent == header)
            if (x == root)
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
            //if(x->parent == header)
            if (x == root)
                this->root = x;
            else if (x == x->parent->left)
                x->parent->left = y;
            else
                x->parent->right = y;
            y->right = x;
            x->parent = y;
        }
        ft::pair<iterator, bool> insert(const value_type& new_value){
            node_ptr y = header;
            node_ptr x = root;
            bool compare = true;
            // while (x != tnull){
            //     y = x;
            //     if (comp(new_value, x->value_field) == false && (comp(x->value_field , new_value) == false)){
            //         std::cout << "insert duplicate key!" << std::endl;
            //         return (ft::make_pair(iterator(x), false));
            //     } else if(comp(new_value, x->value_field) == true){
            //         x = x->left;
            //     } else{
            //         x = x->right;
            //     }
            while(x != tnull){
                y = x;
                compare = comp(new_value, x->value_field);
                x = compare? x->left: x->right; 
            }
            iterator j = iterator(y);
            if(compare == true){ // x->left
                if(j.operator== (begin()))
                    return ft::make_pair(insert_1(x, y ,new_value), true);
                else
                    --j;
            }
            if((comp(j.node->value_field, new_value)))
                return ft::make_pair(insert_1(x, y ,new_value), true);
            return (ft::make_pair(j, false));
        }
        //y = parent node, x insert position?
        iterator insert_1(node_ptr x, node_ptr y, const value_type& new_value){
            ++node_count;
            node_ptr new_node = creat_node(new_value);
            if (y == header || x != tnull ||  comp(new_value, y->value_field) == true){
                y->left = new_node; // also makes leftmost = z when y == header?
                if (y == header){
                    root = new_node;
                    //rightmost() = new_node;
                    header->right = new_node;
                } else if (y == header->left){
                    //leftmost() = new_node;
                    header->left = new_node;
                }
            }else{
                y->right = new_node;
                if (y == header->right){
                    //rightmost() = new_node;
                    header->right = new_node;
                }
            }
            new_node->parent = y;
            x = new_node;
            if (new_node->parent == header){
                new_node->color = BLACK;
                return iterator(new_node);
            }
            if (new_node->parent->parent == header){
                return iterator(new_node);
            }
            insertFIX(x);
            return iterator(new_node);
        }
        
        iterator insert(iterator position, const value_type& x){
            if(position == iterator(header->left)){
                if(node_count > 0 && comp(x, position.node->value_field) == true)
                    return insert_1(position.node, position.node, x);
                else
                    return insert(x).first;
            } else if (position == iterator(header)){ //end
                if(comp(header->right->value_field, x) == true){
                    return insert_1(tnull, header->right, x);
                } else
                    return insert(x).first;
            } else{
                iterator before = --position;
                if(comp(before.node->value_field, x) == true && comp(x, position.node->value_field) == true){
                    if(before.node->right == tnull){
                        return insert_1(tnull, before.node, x);
                    }else
                        return insert_1(position.node, position.node, x);
                }else
                    return insert(x).first;
            }
        }
        void insert_range(const value_type* first, const value_type* last){
            while(first != last)
                insert(*first++);
        }

        void    insertFIX(node_ptr node){
            node_ptr u;

            while(node->parent->color == RED){
                if (node->parent == node->parent->parent->right){
                    u = node->parent->parent->left;
                    if(u->color == RED){
                        u->color = BLACK;
                        node->parent->color = BLACK;
                        node->parent->parent->color = RED;
                        node = node->parent->parent;
                    } else {
                        if (node == node->parent->left){
                            node = node->parent;
                            rightRotate(node);
                        }
                        node->parent->color = BLACK;
                        node->parent->parent->color = RED;
                        printTree();
                        leftRotate(node->parent->parent);
                        printTree();
                    }
                } else {
                    u = node->parent->parent->right;
                    if(u->color == RED){
                        u->color = BLACK;
                        node->parent->color = BLACK;
                        node->parent->parent->color = RED;
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
                std::cout << "here\n";
                printTree();
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
        void erase(iterator position){
            node_ptr z = position.node;
            node_ptr y = z;
            node_ptr x;
            if(y->left == tnull) //find the node to replace
                x = y->right;
            else{
                if (y->right == tnull)
                    y = y->left;
                else {
                    y = y->right;
                    while(y->left != tnull)
                        y = y->left;
                    x = y->right;
                }
            } // x= node to replace, y= parent of x
            if(y != z){  //relink y in place of z  y==z when both child of position are tnull
                z->left->parent = y;
                y->left = z->left;
                if(y != z->right){
                    x->parent = y->parent;
                    y->parent->left = x;
                    y->right = z->right;
                    z->right->parent = y;
                } else  
                    x->parent = y;
                if(root = z)
                    root = y;
                else if (z->parent->left == z)
                    z->parent->left = y;
                else
                    z->parent->right = y;
                y->parent = z->parent;
                swap(y->color, z->color);
                y = z;
            }else{

            }  

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
            //std::cout << "\njere??? : " << root->color<< "\n";
            std::string sColor;
                if (root->color == RED)
                    sColor = "RED";
                else if (root->color == BLACK)
                    sColor = "BLACK";
                else
                    sColor = "tnull";
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