/**
 * @file Stack.h
 * @author Carlos Salguero
 * @brief Declaration of the Stack class
 * @version 0.1
 * @date 2022-12-19
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef STACK_H
#define STACK_H

#include <string>
#include <memory>   // C++11, smart pointers
#include <optional> // C++17, std::optional encapsulation
#include <sstream>  // std::stringstream for to_string()

#include "Node.cpp"

template <class T>
class Stack
{
public:
    // Constructor
    Stack() = default;
    Stack(size_t);
    Stack(size_t, std::shared_ptr<Node<T>>);

    // Destructor
    ~Stack() = default;

    // Getters
    std::shared_ptr<Node<T>> get_top() const;
    size_t get_size() const;

    // Operator overload
    template <typename ostream_t>
    friend std::ostream &operator<<(std::ostream &, const Stack<ostream_t> &);

    // Functions
    bool is_empty() const;
    bool is_full() const;
    bool contains(const T &) const;

    void push(const T &);
    void pop();
    void clear();

    std::optional<T> peek() const;
    std::string to_string() const;

private:
    std::shared_ptr<Node<T>> m_top;
    size_t m_size;
};

#endif //! STACK_H