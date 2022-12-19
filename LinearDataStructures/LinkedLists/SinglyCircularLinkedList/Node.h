/**
 * @file Node.h
 * @author Carlos Salguero
 * @brief Declaration of the Node class
 * @version 0.1
 * @date 2022-12-19
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
    Node(const T &, std::shared_ptr<Node<T>>);

    // Destructor
    ~Node() = default;

    // Getters
    T get_data() const;
    std::shared_ptr<Node<T>> get_next() const;

    // Setters
    void set_data(const T &);
    void set_next(std::shared_ptr<Node<T>>);

private:
    T m_data;
    std::shared_ptr<Node<T>> m_next;
};

#endif //! NODE_H
