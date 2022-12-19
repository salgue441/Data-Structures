/**
 * @file Queue.h
 * @author Carlos Salguero
 * @brief Declaration of the Queue class
 * @version 0.1
 * @date 2022-12-19
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <string>
#include <memory>   // C++11, smart pointers
#include <optional> // C++17, std::optional encapsulation
#include <sstream>  // std::stringstream for to_string()

#include "Node.cpp"

template <class T>
class Queue
{
public:
    // Constructor
    Queue() = default;
    Queue(size_t);
    Queue(size_t, std::shared_ptr<Node<T>>);
    Queue(size_t, std::shared_ptr<Node<T>>, std::shared_ptr<Node<T>>);

    // Destructor
    ~Queue() = default;

    // Getters
    size_t get_size() const;
    std::shared_ptr<Node<T>> get_front() const;
    std::shared_ptr<Node<T>> get_back() const;

    // Operator Overload
    template <typename ostream_t>
    friend std::ostream &operator<<(std::ostream &, const Queue<T> &);

    // Functions
    bool is_empty() const;

    void enqueue(const T &);
    void clear();

    std::optional<T> dequeue();
    std::optional<T> peek() const;
    std::string to_string() const;

private:
    std::shared_ptr<Node<T>> m_front;
    std::shared_ptr<Node<T>> m_back;
    size_t m_size;
};

#endif //! QUEUE_H