#include <iostream>
#include <memory> // C++11, smart pointers

#include "LinearDataStructures/Stack/Stack.cpp"

int main()
{
    Stack<int> stack(5);

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    std::cout << stack << std::endl;
}