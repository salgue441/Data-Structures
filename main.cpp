#include <iostream>
#include <memory> // C++11, smart pointers

#include "NonLinearDataStructures/SplayTree/SplayTree.cpp"

int main()
{
    SplayTree<int> splay_tree;

    splay_tree.insert(10);
    splay_tree.insert(20);
    splay_tree.insert(30);
    splay_tree.insert(40);
    splay_tree.insert(50);
    splay_tree.insert(25);

    std::cout << splay_tree << std::endl;

    return 0;
}