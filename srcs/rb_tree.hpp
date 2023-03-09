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
        typedef rb_tree_node<Value> node_type;
        typedef node_type           *node_ptr;
        typedef size_t size_type;
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
            tnull->value_field = Value(); //printout 0
            // std::cout << "initial tnull:" << tnull->value_field.first << "\n";
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
        void copy_tree(node_ptr des , node_ptr src, node_ptr other_tnull){
            std::cout << "root :" << src->value_field.first << "\n";
            if (src ==  NULL)
                return ;
            else if(src == other_tnull){
                std::cout << "root1 :" << src->value_field.first << "\n";
                des = this->tnull;
            }
            else{
                std::cout << "root2 :" << src->value_field.first << "\n";
                des = node_alloc.allocate(1);
                node_alloc.construct(des, src->value_field);
                des->parent = src->parent;
                des->left = src->left;
                des->right = src->right;
                des->color = src->color;
                copy_tree(des->left, src->left, other_tnull);
                copy_tree(des->right, src->right, other_tnull);
            }
        }
        //construct
        rb_tree(const Compare& comp= Compare()):node_count(0),comp(comp), node_alloc(node_allocator()){
            init();
        }
        rb_tree(const value_type* first, const value_type* last, const Compare& comp = Compare())
          : node_count(0), comp(comp), node_alloc(node_allocator()){ 
            init();
            insert(first, last);
        }
        rb_tree(const rb_tree<Value,Compare,allocator>& x):node_count(x.node_count), comp(x.comp), node_alloc(x.node_alloc){
            init();
            // std::cout << "root??" << x.root->value_field.first <<"\n";
            //root = x.root;
            header = x.header;
            header->left = x.header->left;
            header->right = x.header->right;
            copy_tree(root, x.root, x.tnull);
            std::cout << "what is root ?" << x.root->value_field.first << "\n";
            std::cout << "what is root ?" << root->value_field.first << "\n";
            root = x.root;
            // if(root != tnull){
            //     leftmost() = minimum(root);
            //     rightmost() = maximum(root);
            // }
        }
        rb_tree<Value,Compare,allocator>& operator=(const rb_tree<Value,Compare,allocator>& x){
            // tree = x.tree;
            return *this;
        }
        ~rb_tree(){
            if (root){
                erase(begin(), end());
                node_count = 0;
                if (tnull != NULL){
                    node_alloc.destroy(tnull);
                    node_alloc.deallocate(tnull, 1);
                }
                if (header != NULL){
                    node_alloc.destroy(header);
                    //node_alloc.deallocate(header, 1); ???
                }
            }
        }
        node_ptr& leftmost() { return header->left; }
        node_ptr& leftmost() const { return header->left; }
        node_ptr& rightmost() { return header->right; }
        node_ptr& rightmost() const { return header->right; }
        node_ptr minimum(node_ptr x) {
            while (x->left != tnull)
                x = x->left;
            return x;
        }
        node_ptr maximum(node_ptr x) {
            while (x->right != tnull)
                x = x->right;
            return x;
        }
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

            while(x != tnull){
                y = x;
                compare = comp(new_value, x->value_field);
                x = compare? x->left: x->right; 
            }
            iterator j = iterator(y);
            if(compare == true){ // x->left
                if(j == (begin()))
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
                        leftRotate(node->parent->parent);
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
            }
            root->color = BLACK;
        }
        void erase(iterator position){
            node_ptr z = position.node;
            node_ptr y = z;
            node_ptr x;
            if(y->left == tnull) // __z has at most one non-null child. y == z.
                x = y->right;   //__x might be null.
            else{
                if (y->right == tnull) //__z has exactly one non-null child. y == z.
                    x = y->left; //_x is not null.
                else {  //z has two children,  set y to __z's successor.  __x might be null.
                    y = y->right;
                    while(y->left != tnull)
                        y = y->left; //find a node with no left child.
                    x = y->right;
                }
            } //  relink y in place of z , y is z's successor
            if(y != z){  
                z->left->parent = y;
                y->left = z->left;
                if(y != z->right){
                    x->parent = y->parent;
                    y->parent->left = x;
                    y->right = z->right;
                    z->right->parent = y;
                } else  
                    x->parent = y;
                if(root == z)
                    root = y;
                else if (z->parent->left == z)
                    z->parent->left = y;
                else
                    z->parent->right = y;
                y->parent = z->parent;
                std::swap(y->color, z->color);
                y = z;
            }else{ //y == z
                x->parent = y->parent;
                if(root == z)
                    root = x;
                else{
                    if(z->parent->left == z) //if z left side
                        z->parent->left = x;
                    else 
                        z->parent->right = x;
                }
                if(leftmost() == z){
                    if(z->right == tnull) //z->left must be tnull also?
                         leftmost() = z->parent;
                     //makes leftmost == header if __z == __root
                    else
                        leftmost() = minimum(x);
                }
                if(rightmost() == z){
                    if(z->left == tnull)
                        rightmost() = z->parent;
                else //
                    rightmost() = maximum(x);
                }
            }
            if(y->color != RED){
                while(x != root && x->color == BLACK){
                    if(x == x->parent->left){
                        node_ptr s = x->parent->right;
                        if(s->color == RED){
                            s->color = BLACK;
                            x->parent->color = RED;
                            leftRotate(x->parent);
                            s = x->parent->right;
                        }
                        if(s->left->color == BLACK && s->right->color == BLACK){
                            s->color = RED;
                            x = x->parent;
                        } else{
                            if (s->right->color == BLACK){
                                s->left->color = BLACK;
                                s->color = RED;
                                rightRotate(s);
                                s = x->parent->right;
                            }
                            s->color = x->parent->color;
                            x->parent->color = BLACK;
                            s->right->color = BLACK;
                            leftRotate(x->parent);
                            x = root;
                        }
                    }else{
                        node_ptr s = x->parent->left;
                        if (s->color == RED) {
                            s->color = BLACK;
                            x->parent->color = RED;
                            rightRotate(x->parent);
                            s = x->parent->left;
                        }
                        if (s->right->color == BLACK && s->right->color == BLACK) {
                            s->color = RED;
                            x = x->parent;
                        } else {
                            if (s->left->color == BLACK) {
                                s->right->color = BLACK;
                                s->color = RED;
                                leftRotate(s);
                                s = x->parent->left;
                            }
                            s->color = x->parent->color;
                            x->parent->color = BLACK;
                            s->left->color = BLACK;
                            rightRotate(x->parent);
                            x = root;
                        }
                    }
                }
                x->color = BLACK;
            }
            put_node(y);
            --node_count;
        }
        size_type erase(const value_type& x){
            iterator found = find(x);
            if (found == end())
                return 0;
            erase(found);
            return 1;
        }
        void erase_without_balance(node_ptr node){
            while(node != NULL && node != tnull){
                //std::cout << "node->right :" << node->value_field.first << "\n";
                //std::cout << "if tnull"<< node->if_tnull<<"\n";
                erase_without_balance(node->right);
                node_ptr y = node->left;
                put_node(node);
                node = y;
                //std::cout << "node :" << node->value_field.first << "\n";
            }      
        }
        void erase(iterator first, iterator last){
            if(first == begin() && last == end() && node_count != 0){
                erase_without_balance(root);
                leftmost() = header;
                root = tnull;
                rightmost() = header;
                node_count = 0;
            }else{
                while(first != last){
                    erase(first);
                    ++first;
                }
            }
        }
        void swap(rb_tree<Value,Compare,allocator>&x){
            std::swap(root, x.root);
            std::swap(header, x.header);
            std::swap(node_count, x.node_count);
            std::swap(comp, x.comp);
            std::swap(node_alloc, x.node_alloc);
        }
        void clear(){
            erase(begin(), end());
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
            //std::cout << "\njere??? : " << root->color<< "\n";
            std::string sColor;
                if (root->color == RED)
                    sColor = "RED";
                else if (root->color == BLACK)
                    sColor = "BLACK";
            std::cout << root->value_field.first << "|"  << root->value_field.second <<  "(" << sColor << ")" << std::endl;
            printHelper(root->left, indent, false);
            printHelper(root->right, indent, true);
            }
        }
        void clear_tree(node_ptr subtree){
            if (subtree != NULL && subtree != tnull){
                node_ptr next_left = subtree->left;
                node_ptr next_right = subtree->right;
                put_node(subtree);
                clear_tree(next_left);
                clear_tree(next_right);
            }
        }
};


#endif