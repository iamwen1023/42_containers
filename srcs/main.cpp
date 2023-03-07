#include "./map.hpp"
#include <iostream>
#include <map>
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
    // bst.printTree();
    bst.insert(std::make_pair(2,'b'));
    // bst.printTree();
    bst.insert(std::make_pair(3,'c'));
    // bst.printTree();
      bst.insert(std::make_pair(8,'d'));
        // bst.insert(std::make_pair(9,'e'));
        //   bst.insert(std::make_pair(10,'f'));
        //     bst.insert(std::make_pair(13,'i'));
        //       bst.insert(std::make_pair(14,'j'));
        //         bst.insert(std::make_pair(15,'k'));
        //           bst.insert(std::make_pair(16,'l'));
                  bst.printTree();
    rb_tree<std::pair<int,char>, pair_compare<int, char>, std::allocator<std::pair<const int, char> > >::iterator a = bst.find(std::make_pair(16, 'i'));
    rb_tree<std::pair<int,char>, pair_compare<int, char>, std::allocator<std::pair<const int, char> > >::iterator b = bst.lower_bound(std::make_pair(11, 'i'));
    std::cout << b.node->value_field.first << "|" << b.node->value_field.second <<"\n";
    rb_tree<std::pair<int,char>, pair_compare<int, char>, std::allocator<std::pair<const int, char> > >::iterator c = bst.upper_bound(std::make_pair(16, 'i'));
    std::cout << c.node->value_field.first << "|" << c.node->value_field.second <<"\n";
    rb_tree<std::pair<int,char>, pair_compare<int, char>, std::allocator<std::pair<const int, char> > >::iterator i = bst.begin();
    //bst.insert(i, std::make_pair(100,'a'));
   // bst.printTree();
    //ft::map<int, int> b;


}