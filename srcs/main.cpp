#include "./map.hpp"
#include <iostream>
//enum color_type {RED, BLACK};
template <typename Pair>
struct SelectFirst {
    typedef typename Pair::first_type result_type;
    const result_type& operator()(const Pair& p) const {
        return p.first;
    }
    result_type& operator()(Pair& p) const {
        return p.first;
    }
};

template <class Key, class T, class Compare = std::less<Key> >
class pair_compare : std::less<Key>{
    protected:
    Compare _comp;
    pair_compare(Compare c) : _comp(c) {}

        public:
                    // This so the RBTree can construct the class
        pair_compare(void) : _comp(Compare()) {}

        typedef Key                                         key_type;
        typedef T                                           mapped_type;
        typedef std::pair<const key_type, mapped_type>           value_type;

        typedef value_type  first_argument_type;
        typedef value_type  second_argument_type;
                    
        bool operator()(const value_type &x, const value_type &y)const
        { return _comp(x.first, y.first); }
};

int main(){
    rb_tree<std::pair<int,char>, pair_compare<int, char>, std::allocator<std::pair<const int, char> > >  bst;
    bst.insert(std::make_pair(1,'a'));
    bst.printTree();
    bst.insert(std::make_pair(2,'b'));
    bst.printTree();
    bst.insert(std::make_pair(3,'c'));
    bst.printTree();
      bst.insert(std::make_pair(8,'d'));
      bst.printTree();
        bst.insert(std::make_pair(9,'e'));
        bst.printTree();
          bst.insert(std::make_pair(10,'f'));
          bst.printTree();
            bst.insert(std::make_pair(13,'i'));
            bst.printTree();
              bst.insert(std::make_pair(14,'j'));
              bst.printTree();
                bst.insert(std::make_pair(15,'k'));
                bst.printTree();
                  bst.insert(std::make_pair(16,'l'));
                  bst.printTree();
    auto a = bst.find(std::make_pair(9, 'i'));
    std::cout << a.node->value_field.first << "|" << a.node->value_field.second <<"\n";
    auto b = bst.lower_bound(std::make_pair(10, 'i'));
    std::cout << b.node->value_field.first << "|" << b.node->value_field.second <<"\n";
   // bst.printTree();
    //ft::map<int, int> b;


}