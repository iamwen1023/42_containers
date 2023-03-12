#include "./map.hpp"
#include <iostream>
#include <map>
#include <utility>

int main(){
    // rb_tree<std::pair<int,char>, pair_compare<int, char>, std::allocator<std::pair<const int, char> > >  bst;
    // bst.insert(std::make_pair(1,'a'));
    // // bst.printTree();
    // bst.insert(std::make_pair(2,'b'));
    // // bst.printTree();
    // bst.insert(std::make_pair(3,'c'));
    // // bst.printTree();
    //   bst.insert(std::make_pair(8,'d'));
    //     bst.insert(std::make_pair(9,'e'));
    //       bst.insert(std::make_pair(10,'f'));
    //         bst.insert(std::make_pair(13,'i'));
    //           bst.insert(std::make_pair(14,'j'));
    //             bst.insert(std::make_pair(15,'k'));
    //               bst.insert(std::make_pair(16,'l'));
    //               //bst.printTree();
    // rb_tree<std::pair<int,char>, pair_compare<int, char>, std::allocator<std::pair<const int, char> > >::iterator a = bst.find(std::make_pair(16, 'i'));
    // std::cout << a.node->value_field.first << "|" << a.node->value_field.second <<"\n";
    // // rb_tree<std::pair<int,char>, pair_compare<int, char>, std::allocator<std::pair<const int, char> > >::iterator b = bst.lower_bound(std::make_pair(11, 'i'));
    // // std::cout << b.node->value_field.first << "|" << b.node->value_field.second <<"\n";
    // // rb_tree<std::pair<int,char>, pair_compare<int, char>, std::allocator<std::pair<const int, char> > >::iterator c = bst.upper_bound(std::make_pair(16, 'i'));
    // // std::cout << c.node->value_field.first << "|" << c.node->value_field.second <<"\n";
    // // rb_tree<std::pair<int,char>, pair_compare<int, char>, std::allocator<std::pair<const int, char> > >::iterator i = bst.begin();
    // //bst.insert(i, std::make_pair(100,'a'));
    // bst.erase(bst.begin(), bst.end());
    // bst.printTree();
   // bst.printTree();
    //ft::map<int, int> b;
    ft::map<int, char> ex;

    ex.insert(ft::make_pair(1, 'a'));
    ex.insert(ft::make_pair(2, 'b'));
    ex.insert(ft::make_pair(3, 'c'));

    ex.printTreemap();
   
    ft::map<int, char> trytry(ex);
    trytry.printTreemap();
    trytry.insert(ft::make_pair(4, 'a'));
    trytry.insert(ft::make_pair(5, 'a'));
    trytry.insert(ft::make_pair(6, 'a'));
    trytry.insert(ft::make_pair(7, 'a'));
    trytry.insert(ft::make_pair(8, 'a'));
    trytry.insert(ft::make_pair(9, 'a'));
    //trytry.printTreemap();
    ft::map<int, char> ex1;
    ex1=trytry;
    ex1.printTreemap();
    bool ans= (ex1==trytry);
    bool ans2= (ex1==ex);
    std::cout << "result:" << ans  << ans2 << std::endl;
    std::cout << ex1[3] << "\n";
    ex1[3] = 'z';
    std::cout << ex1[3] << "\n";
    // rb_tree<std::pair<int,char>, pair_compare<int, char>, std::allocator<std::pair<const int, char> > >  bst;
    // bst.insert({1, '3'});
    // bst.insert({3,'4'});
    // bst.insert({5,'7'});
    // bst.printTree();

    


}