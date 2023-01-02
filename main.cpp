#include <iostream>
#include <memory> // C++11, smart pointers

#include "NonLinearDataStructures/SplayTree/SplayTree.cpp"

int main()
{
    SplayTree<int> tree;

    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);
    

    std::cout << tree << std::endl;
}