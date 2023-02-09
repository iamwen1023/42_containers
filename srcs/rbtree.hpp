#ifndef RBTREE_HPP
#define RBTREE_HPP
template <class Key, class T,>
struct node_value{
    Key *key;
    T   *value;
}
struct node{
    char color;
    struct node_value;
    struct node left;
    struct node right;
    struct node parent;
};
class map {
    map();


    private:
        struct rbtree tree;
}


#endif