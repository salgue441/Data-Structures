/**
 * @file Node.h
 * @author Carlos Salguero
 * @brief Declaration of the Node class for the Singly Circular Linked List
 * @version 0.1
 * @date 2023-01-03
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef NODE_H
#define NODE_H

#include <memory>

template <class T>
class Node
{
public:
    // Constructor
    Node() = default;
    Node(T &);
    Node(T &, std::shared_ptr<Node<T>>);

    // Destructor
    ~Node() = default;

    // Getters
    std::shared_ptr<Node<T>> get_next() const;
    T get_data() const;

    // Setters
    void set_next(std::shared_ptr<Node<T>>);
    void set_data(T);

private:
    std::shared_ptr<Node<T>> next;
    T data;
};

#endif //! NODE_H