/**
 * @file BST.h
 * @author Carlos Salguero
 * @brief Declaration of the BST class for the Binary Search Tree
 * @version 0.1
 * @date 2023-01-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef BST_H
#define BST_H

#include <memory>     // C++11, smart pointers
#include <optional>   // C++17, std::optional encapsulation
#include <queue>      // for level-order traversal
#include <string>     // for to_string() method
#include <sstream>    // for ostringstream for to_string() method
#include <functional> // for std::function

#include "Node.cpp"

template <class T>
class BST
{
public:
    // Constructors
    BST() = default;
    BST(const T &);
    BST(const std::shared_ptr<Node<T>> &);
    BST(const T &, const std::shared_ptr<Node<T>> &);

    // Destructor
    ~BST() = default;

    // Getters
    std::shared_ptr<Node<T>> get_root() const;

    // Operator overload
    template <typename ostream_t>
    friend std::ostream &operator<<(std::ostream &, const BST<ostream_t> &);

    // Methods
    bool is_empty() const;
    bool contains(const T &) const;

    std::optional<std::shared_ptr<Node<T>>> find(const T &) const;

    void insert(const T &);
    void remove(const T &);
    void clear();

    std::string to_string() const;

private:
    std::shared_ptr<Node<T>> root;
};

#endif //! BST_H