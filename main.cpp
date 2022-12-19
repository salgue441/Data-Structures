#include <iostream>
#include <memory>

#include "DoubleLinkedList.cpp"

int main()
{
    DoubleLinkedList<int> list;
    list.push_back(1);
    list.push_back(22);
    list.push_back(3);
    list.push_back(4);
    list.push_back(52);
    list.push_back(6);

    std::cout << list << std::endl;

    list.merge_sort();
    std::cout << list << std::endl;

    list.merge_sort(false);
    std::cout << list << std::endl;

    return 0;
}