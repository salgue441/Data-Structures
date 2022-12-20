/**
 * @file BinaryTree.h
 * @author Carlos Salguero
 * @brief Declaration of the BinaryTree class
 * @version 0.1
 * @date 2022-12-19
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <string>
#include <memory>   // C++11, smart pointers
#include <optional> // C++17, std::optional encapsulation
#include <sstream>  // std::stringstream for the to_string() method
#include <queue>    // for the to_string() method
#include <stack>    // for the in_order(), pre_order() and post_order() methods

#include "Node.cpp"

template <class T>
class BinaryTree
{
public:
    // Constructor
    BinaryTree() = default;
    BinaryTree(std::shared_ptr<T>);

    // Destructor
    ~BinaryTree() = default;

    // Getters
    std::shared_ptr<Node<T>> get_root() const;

    // Operator Overload
    template <typename ostream_t>
    friend std::ostream &operator<<(std::ostream &,
                                    const BinaryTree<ostream_t> &);

    // Functions
    bool is_empty() const;
    bool is_leaf(const std::shared_ptr<Node<T>> &) const;

    std::optional<std::shared_ptr<Node<T>>> find(const T &) const;
    std::optional<std::shared_ptr<Node<T>>> find_parent(const T &) const;

    void insert(const T &);
    void remove(const T &);
    void clear();

    std::string to_string() const;
    std::string in_order() const;
    std::string pre_order() const;
    std::string post_order() const;

private:
    std::shared_ptr<Node<T>> m_root;
};

#endif //! BINARY_TREE_H