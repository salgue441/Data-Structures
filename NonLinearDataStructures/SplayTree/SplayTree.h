/**
 * @file SplayTree.cpp
 * @author Carlos Salguero
 * @brief Declaration of SplayTree class
 * @version 0.1
 * @date 2022-12-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef SPLAY_TREE_H
#define SPLAY_TREE_H

#include <memory>   // C++11, smart pointers
#include <optional> // C++17, optional encapsulation
#include <queue>    // C++11, queue data structure

#include "Node.cpp"

template <class T>
class SplayTree
{
public:
    // Constructor
    SplayTree() = default;
    SplayTree(const std::shared_ptr<Node<T>> &);

    // Destructor
    ~SplayTree() = default;

    // Getter
    std::shared_ptr<Node<T>> get_root() const;

    // Operator overload
    template <typename ostream_t>
    friend std::ostream &operator<<(std::ostream &,
                                    const SplayTree<ostream_t> &);

    // Methods
    bool is_empty() const;

    void insert(const T &);
    void remove(const T &);

    std::optional<std::shared_ptr<Node<T>>> search(const T &) const;

private:
    std::shared_ptr<Node<T>> root;

    // Getters
    std::shared_ptr<Node<T>> get_parent(const std::shared_ptr<Node<T>> &) const;
    std::shared_ptr<Node<T>> get_grandparent(
        const std::shared_ptr<Node<T>> &) const;
    std::shared_ptr<Node<T>> get_left_child(
        const std::shared_ptr<Node<T>> &) const;
    std::shared_ptr<Node<T>> get_right_child(
        const std::shared_ptr<Node<T>> &) const;

    // Helper functions
    void zig_rotation(const std::shared_ptr<Node<T>> &);
    void zag_rotation(const std::shared_ptr<Node<T>> &);
    void zig_zig_rotation(const std::shared_ptr<Node<T>> &);
    void zag_zag_rotation(const std::shared_ptr<Node<T>> &);
    void zig_zag_rotation(const std::shared_ptr<Node<T>> &);
    void zag_zig_rotation(const std::shared_ptr<Node<T>> &);
    void swap(const std::shared_ptr<Node<T>> &,
              const std::shared_ptr<Node<T>> &);
    void splay(const std::shared_ptr<Node<T>> &);
};

#endif //! SPLAY_TREE_H