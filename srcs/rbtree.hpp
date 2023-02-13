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
                    x = x->left;
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
        

}


#endif