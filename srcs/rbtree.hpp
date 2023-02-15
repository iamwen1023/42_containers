#ifndef RBTREE_HPP
#define RBTREE_HPP
template <class Key, class T,>
struct node_value{
    Key *key;
    T   *value;
}
struct node{
    char color;
    // struct node_value;
    int value;
    struct node *left;
    struct node *right;
    struct node *parent;
};
typedef node *NodePtr;

class RBTree {
    private:
        NodePtr root;
        NodePtr TNULL;

        void initializeNullNode(NodePtr node, NodePtr parent){
            node->data = 0;
            node->parent = parent;
            node->right = nullptr;
            node->left = nullptr;
            node->color = 0;
        }
        //preorder 
        void preorderHelper(NodePtr node){
            if (node != TNULL){
                std::cout << node->data << " ";
                preorderHelper(node->left);
                preorderHelper(node->right);
            }
        }
        //inorder
        void inorderHelper(NodePtr node){
            if (node != TNULL){
                preorderHelper(node->left);
                std::cout << node->data << " ";
                preorderHelper(node->right);
            }
        }
        //postorder
        void inorderHelper(NodePtr node){
            if (node != TNULL){
                preorderHelper(node->left);
                preorderHelper(node->right);
                std::cout << node->data << " ";
            }
        }

        NodePtr searchTreeHelp(NodePtr node, int value){
            if (node== TNULL || value =  node->data)
                return node;
            if (value < node->data){
                return searchTreeHelp(node->left . value);
            } else
                return searchTreeHelp(node->right, value);
        }
        void leftRotate(NodePtr x){
            NodePtr y = x->right;
            x->right = y->left;
            if( y->left != TNULL)
                y->left->parent = x;
            y->parent = x->parent;
            if(x->parent == nullptr)
                this->root = y;
            else if(x == x->parent->left)
                x->parent->left = y;
            else
                x->parent->right = y;
            y->left = x;
            x->parent = y;
        }
        void rightRotate(NodePtr x){
            NodePtr y = x->left;
            x->left = y->right;
            if(y->right !=TNULL)
                y->right->parent = x;
            y->parent = x->parent;
            if(x->parent == nullptr)
                this->root = x;
            else if (x == x->parent->left)
                x->parent->left = y;
            else
                x->parent->right = y;
            y->right = x;
            x->parent = y;
        }

        void insert(int key){
            NodePtr node =  new node;
            node->data = key;
            node->left = TNULL;
            node->right = TNULL;
            node->parent = TNULL;
            node->color = 'R';
            NodePtr x= this->root;
            NodePtr y= nullptr;
            while(x != TNULL){
                y = x;
                if (node->data < x->data)
                    x = x->left;
                else
                    x = x->right;
            }
            node->parent = y;
            if(y == nullptr)
                root = node;
            else if (node->data < y->data)
                y->left = node;
            else
                y->right = node;
            if (node->parent == nullptr)
                node->color = 'B';
            if (node->parent->parent == nullptr)
                return ;
            insertFIX(node);
        }
        void insertFIX(NodePtr node){
            NodePtr u;
            while(node->parent->color == 'R'){
                if(node->parent == node->parent->parent->right){
                    u = node->parent->left;
                    if(u->color == 'R'){
                        node->parent->color = 'B';
                        u->color = 'B';
                        node->parent->parent = 'R';
                        node = node->parent->parent;
                    }else {
                        if (node == node->parent->right){
                            node = node->parent;
                            leftRotate(node);
                        }
                        node->parent->color = 'B';
                        node->parent->parent->color = 'R';
                        rightRotate(node->parent->parent);
                    }
                } else{
                    u = node->parent->right;
                    if(u->color == 'R'){
                        node->parent->color = 'B';
                        u->color = 'B';
                        node->parent->parent = 'R';
                        node = node->parent->parent;
                    }else {
                        if (node == node->parent->right){
                            node = node->parent;
                            leftRotate(node);
                        }
                        node->parent->color = 'B';
                        node->parent->parent->color = 'R';
                        rightRotate(node->parent->parent);
                    }
                }
                if(node == root)
                    break ;
            }
            root->color = 'B';
        }
        NodePtr minimum(NodePtr node){
            while(node->left != TNULL){
                node = node->left;
            }
            return node;
        }
        NodePtr maximum(NodePtr node){
            while(node->right != TNULL){
                node = node->right;
            }
            return node;
        }
        void transplant(NodePtr u, NodePtr v){
            if(u->parent == TNULL)
                this->root = v;
            else if(u == u->parent->left)
                u->parent->left = v;
            else
                u->parent->right = v;
            v->parent = u->parent;
        }
        void RB_delete(NodePtr node){
            NodePtr y = node;
            NodePtr x;
            char color_origin = y->color;
            if (node->left == TNULL){
                x = node->right;
                transplant(node, node->right); 
            } else if (node->right == TNULL){
                x = node->left
                transplant(node, node->left);
            } else {
                y = minimum(node->right);
                color_origin = y->color;
                x = y->right;
                if(y->parent == node)
                    x->parent = y;
                else {
                    transplant(y, y->right);
                    y->right = node->right;
                    y->left->parent = y;
                    transplant(node, y);
                    y->left = node->left;
                    y->left->parent = y;
                    y->color = node->color;
                }
            }
            if (color_origin = 'B');
                deleteFix(x);
        }

}


#endif