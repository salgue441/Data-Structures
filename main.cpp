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

    std::cout << tree.in_order() << std::endl;
    std::cout << tree.pre_order() << std::endl;
    std::cout << tree.post_order() << std::endl;

    auto node = tree.find(4);

    (node)
        ? std::cout << "Found node: " << node.value()->get_data() << std::endl
        : std::cout << "Node not found" << std::endl;
}