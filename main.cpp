#include <iostream>
#include <memory> // C++11, smart pointers

#include "NonLinearDataStructures/BinaryTree/BinaryTree.cpp"

int main()
{
    BinaryTree<int> tree;

    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);

    std::cout << tree << std::endl;
    std::cout << tree.post_order() << std::endl;

    return 0;
};