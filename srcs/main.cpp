#include "./map.hpp"
#include <iostream>

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
    // rb_tree<std::pair<int,char>, pair_compare<int, char>, std::allocator<std::pair<const int, char> > >  bst(1 2 3 );
    // bst.insert(std::make_pair(1,'a'));
    // bst.insert(std::make_pair(2,'a'));
    // bst.insert(std::make_pair(3,'a'));
    // bst.printTree();
    ft::map<int, int> b;


}