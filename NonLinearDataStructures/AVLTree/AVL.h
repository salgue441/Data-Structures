/**
 * @file AVL.h
 * @author Carlos Salguero
 * @brief Declaration of the AVL class
 * @version 0.1
 * @date 2022-12-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef AVL_H
#define AVL_H

#include <string>
#include <memory>   // C++11, smart pointers
#include <optional> // C++17, std::optional encapsulation
#include <sstream>  // std::stringstream for to_string() function
#include <queue>    // C++11, std::queue for to_string() function

#include "Node.cpp"

template <class T>
class AVL
{
public:
    // Constructor
    AVL() = default;
    AVL(size_t);
    AVL(const std::shared_ptr<Node<T>> &);
    AVL(size_t, const std::shared_ptr<Node<T>> &);

    // Destructor
    ~AVL() = default;

    // Getters
    std::shared_ptr<Node<T>> get_root() const;
    size_t get_size() const;

    // Operator Overload
    template <typename ostream_t>
    friend std::ostream &operator<<(std::ostream &, const AVL<ostream_t> &);

    // Functions
    bool is_empty() const;
    bool contains(const T &) const;

    void insert(const T &);
    void remove(const T &);
    void clear() const;

    std::optional<std::shared_ptr<Node<T>>> find(const T &) const;
    std::optional<std::shared_ptr<Node<T>>> find_parent(const T &) const;

    std::optional<std::shared_ptr<Node<T>>> find_min(
        const std::shared_ptr<Node<T>> &) const;
    std::optional<std::shared_ptr<Node<T>>> find_max(
        const std::shared_ptr<Node<T>> &) const;

    std::optional<std::shared_ptr<Node<T>>> find_successor(
        const std::shared_ptr<Node<T>> &) const;

    std::string to_string() const;

private:
    // Data Members
    std::shared_ptr<Node<T>> root;
    size_t size;

    // Helper Functions
    bool is_balanced(const std::shared_ptr<Node<T>> &) const;
    size_t get_height(const std::shared_ptr<Node<T>> &) const;
    int get_balance_factor(const std::shared_ptr<Node<T>> &) const;

    std::shared_ptr<Node<T>> rotate_left(const std::shared_ptr<Node<T>> &);
    std::shared_ptr<Node<T>> rotate_right(const std::shared_ptr<Node<T>> &);
};

#endif //! AVL_H
