/**
 * @file Node.h
 * @author Carlos Salguero
 * @brief Declaration of the Node class for the AVLTree class
 * @version 0.1
 * @date 2022-12-20
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
    Node(const T &, const std::shared_ptr<Node> &,
         const std::shared_ptr<Node> &);

    // Destructor
    ~Node() = default;

    // Getters
    T get_data() const;
    std::shared_ptr<Node> get_left() const;
    std::shared_ptr<Node> get_right() const;

    // Setters
    void set_data(const T &);
    void set_left(const std::shared_ptr<Node> &);
    void set_right(const std::shared_ptr<Node> &);

private:
    T data;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;
};

#endif // NODE_H