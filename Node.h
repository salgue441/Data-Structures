/**
 * @file Node.h
 * @author Carlos Salguero
 * @brief Declaration of the Node class for the DoubleLinkedList
 * @version 0.1
 * @date 2022-12-18
 *
 * @copyright Copyright (c) 2022
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
    Node(const T &);
    Node(const T &, std::shared_ptr<Node<T>>, std::shared_ptr<Node<T>>);

    // Destructor
    ~Node() = default;

    // Getters
    T get_data() const;
    std::shared_ptr<Node<T>> get_next() const;
    std::shared_ptr<Node<T>> get_prev() const;

    // Setters
    void set_data(const T &);
    void set_next(std::shared_ptr<Node<T>>);
    void set_prev(std::shared_ptr<Node<T>>);

private:
    T data;
    std::shared_ptr<Node<T>> next;
    std::shared_ptr<Node<T>> prev;
};

#endif //! NODE_H