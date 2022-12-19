#include <iostream>
#include <memory>

#include "LinearDataStructures/LinkedLists/DoubleLinkedList/DoubleLinkedList.cpp"

int main()
{
    DoubleLinkedList<int> list;

    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);

    std::cout << list << std::endl;

    list.reverse();
    std::cout << list << std::endl;
}