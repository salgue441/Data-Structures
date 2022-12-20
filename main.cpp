#include <iostream>
#include <memory> // C++11, smart pointers

#include "NonLinearDataStructures/AVLTree/AVL.cpp"

int main()
{
    AVL<int> avl;

    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(50);
    avl.insert(25);

    std::cout << avl.to_string() << std::endl;

        return 0;
}