#include <iostream>
#include <memory> // C++11, smart pointers

#include "LinearDataStructures/Queue/Queue.cpp"

int main()
{
    Queue<int> queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
};