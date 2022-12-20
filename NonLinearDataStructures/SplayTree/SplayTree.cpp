/**
 * @file SplayTree.cpp
 * @author Carlos Salguero
 * @brief Implementation of Splay Tree
 * @version 0.1
 * @date 2022-12-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "SplayTree.h"

// Constructor
/**
 * @brief Construct a new Splay Tree< T>:: Splay Tree object
 * @tparam T Type of the data stored in the tree
 * @param root Root of the tree
 */
template <class T>
SplayTree<T>::SplayTree(std::shared_ptr<Node<T>> &root)
{
    this->root = root;
};

// Getter
/**
 * @brief Get the root of the tree
 * @tparam T Type of the data stored in the tree
 * @return std::shared_ptr<Node<T>> Root of the tree
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
std::shared_ptr<Node<T>> SplayTree<T>::get_root() const
{
    return this->root;
}

// Operator overload
/**
 * @brief Overload the << operator to print the tree
 * @tparam ostream_t Type of the output stream
 * @param os Output stream
 * @param tree Tree to print
 * @return std::ostream& Output stream
 */
template <typename ostream_t>
std::ostream &operator<<(std::ostream &os, const SplayTree<ostream_t> &tree)
{
    auto root = tree.get_root();

    if (root == nullptr)
    {
        os << "Tree is empty" << std::endl;
        return os;
    }

    std::queue<std::shared_ptr<Node<ostream_t>>> queue;
    queue.push(root);

    while (!queue.empty())
    {
        auto node = queue.front();
        queue.pop();

        os << node->get_data() << " ";

        if (node->get_left() != nullptr)
            queue.push(node->get_left());

        if (node->get_right() != nullptr)
            queue.push(node->get_right());
    }

    os << std::endl;

    return os;
}

// Private helper functions
/**
 * @brief
 * Get the parent of a node
 * @tparam T Type of the data stored in the tree
 * @param node Node to get the parent
 * @return std::shared_ptr<Node<T>> Parent of the node
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
std::shared_ptr<Node<T>> SplayTree<T>::get_parent(
    const std::shared_ptr<Node<T>> &node) const
{
    return node->get_parent();
}

/**
 * @brief
 * Get the left child of a node
 * @tparam T Type of the data stored in the tree
 * @param node Node to get the left child
 * @return std::shared_ptr<Node<T>> Left child of the node
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
std::shared_ptr<Node<T>> SplayTree<T>::get_left_child(
    const std::shared_ptr<Node<T>> &node) const
{
    return node->get_left();
}

/**
 * @brief
 * Get the right child of a node
 * @tparam T Type of the data stored in the tree
 * @param node Node to get the right child
 * @return std::shared_ptr<Node<T>> Right child of the node
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
std::shared_ptr<Node<T>> SplayTree<T>::get_right_child(
    const std::shared_ptr<Node<T>> &node) const
{
    return node->get_right();
}

// Private helper functions