#include <iostream>
#include <memory> // C++11, smart pointers

#include "NonLinearDataStructures/Heap/Heap.cpp"

int main()
{
    Heap<int> heap;

    heap.insert(10);
    heap.insert(20);
    heap.insert(30);
    heap.insert(40);
    heap.insert(50);
    heap.insert(60);

    std::cout << heap << std::endl;

    heap.remove(20);
    std::cout << heap << std::endl;

    // extract min
    auto max = heap.extract_max();

    if (max.has_value())
        std::cout << "Max: " << max.value()->get_data() << std::endl;

    // search
    auto search = heap.search(30);

    if (search.has_value())
        std::cout << "Found: " << search.value()->get_data() << std::endl;
}