#include <iostream>
#include <optional>
#include <memory>

#include "LinearDataStructures/LinkedLists/SinglyCircularLinkedList/SinglyCircularLinkedList.cpp"

int main()
{
    SinglyCircularLinkedList<int> list;

    list.push_front(1);
    list.push_front(2);
    list.push_front(3);

    list.push_back(4);
    list.push_back(5);
    list.push_back(6);

    list.insert(7, 3);
    list.insert(8, 0);

    std::cout << list << std::endl;

    list.pop_front();
    list.pop_back();
    list.remove(3);

    std::cout << list << std::endl;

    list.reverse();
    std::cout << list << std::endl;

    list.ascending_bubble_sort();
    std::cout << list << std::endl;
}