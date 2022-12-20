/**
 * @file SplayTree.cpp
 * @author Carlos Salguero
 * @brief Declaration of Node class for Splay Tree
 * @version 0.1
 * @date 2022-12-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef SPLAY_TREE_NODE_H
#define SPLAY_TREE_NODE_H

#include <memory> // C++11, smart pointers

template <class T>
class Node
{
public:
    // Constructor
    Node() = default;
    Node(const T &);
    Node(const T &, const std::shared_ptr<Node<T>> &,
         const std::shared_ptr<Node<T>> &);

    // Destructor
    ~Node() = default;

    // Getter
    T get_data() const;
    std::shared_ptr<Node<T>> get_left() const;
    std::shared_ptr<Node<T>> get_right() const;

    // Setter
    void set_data(const T &);
    void set_left(const std::shared_ptr<Node<T>> &);
    void set_right(const std::shared_ptr<Node<T>> &);

private:
    T data;
    std::shared_ptr<Node<T>> left;
    std::shared_ptr<Node<T>> right;
};

#endif //! SPLAY_TREE_NODE_H