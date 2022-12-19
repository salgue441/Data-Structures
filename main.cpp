#include <iostream>
#include <memory>
#include <optional>
#include <functional>

// Data Structures
#include "SinglyLinkedList.cpp"

int main()
{
    SinglyLinkedList<int> list{};

    list.push_front(11);
    list.push_front(2);
    list.push_front(33);
    list.push_front(4);
    list.push_front(5);
    list.push_front(64);
    list.push_front(7);
    list.push_front(8);
    list.push_front(9);
    list.push_front(10);

    std::cout << list << std::endl;

    // Sort the list
    list.merge_sort();
    std::cout << list << std::endl;

    return 0;
}