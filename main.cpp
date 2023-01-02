#include <iostream>
#include <memory> // C++11, smart pointers

#include "NonLinearDataStructures/SplayTree/SplayTree.cpp"

int main()
{
    SplayTree<int> splay_tree;

    splay_tree.insert(10);
    splay_tree.insert(5);
    splay_tree.insert(15);
    splay_tree.insert(2);
    splay_tree.insert(7);
    splay_tree.insert(12);
    splay_tree.insert(17);

    std::cout << splay_tree << std::endl;

    // remove
    auto node = splay_tree.find(5);

    splay_tree.remove(5);
    std::cout << splay_tree << std::endl;
}