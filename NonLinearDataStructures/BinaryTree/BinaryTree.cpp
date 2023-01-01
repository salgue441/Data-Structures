/**
 * @file BinaryTree.cpp
 * @author Carlos Salguero
 * @brief Implementation of the Binary Tree Class
 * @version 0.1
 * @date 2022-12-19
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "BinaryTree.h"

// Constructor
/**
 * @brief
 * Construct a new Binary Tree< T>:: Binary Tree object
 * @tparam T Type of data
 * @param root Root of the binary tree.
 */
template <class T>
BinaryTree<T>::BinaryTree(std::shared_ptr<T> root) : m_root(root)
{
}

// Getters
/**
 * @brief
 * Get the root of the binary tree
 * @tparam T Type of data
 * @return std::shared_ptr<Node<T>> Root of the binary tree
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
std::shared_ptr<Node<T>> BinaryTree<T>::get_root() const
{
    return m_root;
}

// Operator Overload
/**
 * @brief
 * Overload the << operator to print the binary tree
 * @tparam ostream_t Type of data
 * @param os Output stream
 * @param binary_tree Binary tree to print
 * @return std::ostream& Output stream
 * @time complexity O(n)
 * @space complexity O(n)
 */
template <class ostream_t>
std::ostream &operator<<(std::ostream &os,
                         const BinaryTree<ostream_t> &binary_tree)
{
    os << binary_tree.to_string();

    return os;
}

// Functions
/**
 * @brief
 * Check if the binary tree is empty
 * @tparam T Type of data
 * @return true If the binary tree is empty
 * @return false If the binary tree is not empty
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
bool BinaryTree<T>::is_empty() const
{
    return m_root == nullptr;
}

/**
 * @brief
 * Check if the node is a leaf
 * @tparam T Type of data
 * @param node Node to check
 * @return true If the node is a leaf
 * @return false If the node is not a leaf
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
bool BinaryTree<T>::is_leaf(const std::shared_ptr<Node<T>> &node) const
{
    return node->get_left() == nullptr && node->get_right() == nullptr;
}

/**
 * @brief
 * Find a node in the binary tree
 * @tparam T Type of data
 * @param data Data to find
 * @return std::optional<std::shared_ptr<Node<T>>> Node found
 * @time complexity O(n)
 * @space complexity O(n)
 */
template <class T>
std::optional<std::shared_ptr<Node<T>>> BinaryTree<T>::find(const T &data) const
{
    std::shared_ptr<Node<T>> current_node = m_root;

    while (current_node != nullptr)
    {
        if (data == current_node->get_data())

            return current_node;

        else if (data < current_node->get_data())
            current_node = current_node->get_left();

        else
            current_node = current_node->get_right();
    }

    return std::nullopt;
}

/**
 * @brief
 * Finds the minimum value in the binary tree.
 * @tparam T Type of data
 * @return std::optional<std::shared_ptr<Node<T>>> Node found
 * @time complexity O(n)
 * @space complexity O(n)
 */
template <class T>
std::optional<std::shared_ptr<Node<T>>> BinaryTree<T>::find_min(
    const std::shared_ptr<Node<T>> &node) const
{
    std::shared_ptr<Node<T>> current_node = node;

    while (current_node != nullptr && current_node->get_left() != nullptr)
        current_node = current_node->get_left();

    return current_node;
}

/**
 * @brief
 * Finds the maximum value in the binary tree.
 * @tparam T Type of data
 * @return std::optional<std::shared_ptr<Node<T>>> Node found
 * @time complexity O(n)
 * @space complexity O(n)
 */
template <class T>
std::optional<std::shared_ptr<Node<T>>> BinaryTree<T>::find_max(
    const std::shared_ptr<Node<T>> &node) const
{
    std::shared_ptr<Node<T>> current_node = node;

    while (current_node != nullptr && current_node->get_right() != nullptr)
        current_node = current_node->get_right();

    return current_node;
}

/**
 * @brief
 * Find the successor of a node in the binary tree
 * @tparam T Type of data
 * @param node Node to find the successor
 * @return std::optional<std::shared_ptr<Node<T>>>
 */
template <class T>
std::optional<std::shared_ptr<Node<T>>>
BinaryTree<T>::find_successor(
    const std::shared_ptr<Node<T>> &node) const
{
    if (node->get_right() != nullptr)
        return find_min(node->get_right());

    std::shared_ptr<Node<T>> current_node = node;
    std::shared_ptr<Node<T>> parent_node = node->get_parent();

    while (parent_node != nullptr && current_node == parent_node->get_right())
    {
        current_node = parent_node;
        parent_node = parent_node->get_parent();
    }

    return parent_node;
}

/**
 * @brief
 * Insert a node in the binary tree
 * @tparam T Type of data
 * @param data Data to insert
 * @time complexity O(n)
 * @space complexity O(n)
 */
template <class T>
void BinaryTree<T>::insert(const T &data)
{
    std::shared_ptr<Node<T>> new_node = std::make_shared<Node<T>>(data);

    if (is_empty())
        m_root = new_node;

    else
    {
        std::shared_ptr<Node<T>> current_node = m_root;
        std::shared_ptr<Node<T>> parent_node = nullptr;

        while (current_node != nullptr)
        {
            parent_node = current_node;

            if (data < current_node->get_data())
                current_node = current_node->get_left();

            else
                current_node = current_node->get_right();
        }

        if (data < parent_node->get_data())
            parent_node->set_left(new_node);

        else
            parent_node->set_right(new_node);
    }
}

/**
 * @brief
 * Remove a node in the binary tree
 * @tparam T Type of data
 * @param data Data to remove
 * @time complexity O(n)
 * @space complexity O(n)
 */
template <class T>
void BinaryTree<T>::remove(const T &data)
{
    std::shared_ptr<Node<T>> current_node = m_root;
    std::shared_ptr<Node<T>> parent_node = nullptr;

    while (current_node != nullptr && current_node->get_data() != data)
    {
        parent_node = current_node;

        if (data < current_node->get_data())
            current_node = current_node->get_left();

        else
            current_node = current_node->get_right();
    }

    if (current_node == nullptr)
        return;

    if (is_leaf(current_node))
    {
        if (current_node == m_root)
            m_root = nullptr;

        else if (parent_node->get_left() == current_node)
            parent_node->set_left(nullptr);

        else
            parent_node->set_right(nullptr);
    }

    else if (current_node->get_left() == nullptr)
    {
        if (current_node == m_root)
            m_root = current_node->get_right();

        else if (parent_node->get_left() == current_node)
            parent_node->set_left(current_node->get_right());

        else
            parent_node->set_right(current_node->get_right());
    }

    else if (current_node->get_right() == nullptr)
    {
        if (current_node == m_root)
            m_root = current_node->get_left();

        else if (parent_node->get_left() == current_node)
            parent_node->set_left(current_node->get_left());

        else
            parent_node->set_right(current_node->get_left());
    }

    else
    {
        std::shared_ptr<Node<T>> successor_node = current_node->get_right();

        while (successor_node->get_left() != nullptr)
            successor_node = successor_node->get_left();

        T successor_data = successor_node->get_data();

        remove(successor_data);

        current_node->set_data(successor_data);
    }
}

/**
 * @brief
 * Removes the child of a node.
 * @tparam T Type of data
 * @param node Node to remove the child
 * @param child Child to remove
 * @time complexity O(n)
 * @space complexity O(n)
 */
template <class T>
void BinaryTree<T>::remove_child(
    const std::shared_ptr<Node<T>> &node,
    const std::shared_ptr<Node<T>> &child)
{
    if (node->get_left() == child)
        node->set_left(nullptr);

    node->set_right(nullptr);
}

/**
 * @brief
 * Finds the parent of a node in the binary tree
 * @tparam T Type of data
 * @param data Data to find
 * @return std::optional<std::shared_ptr<Node<T>>> Parent of the node
 */
template <class T>
std::optional<std::shared_ptr<Node<T>>>
BinaryTree<T>::find_parent(const T &data) const
{
    std::shared_ptr<Node<T>> current_node = m_root;
    std::shared_ptr<Node<T>> parent_node = nullptr;

    while (current_node != nullptr && current_node->get_data() != data)
    {
        parent_node = current_node;

        if (data < current_node->get_data())
            current_node = current_node->get_left();

        else
            current_node = current_node->get_right();
    }

    if (current_node == nullptr)
        return std::nullopt;

    return parent_node;
}

/**
 * @brief
 * Clears the binary tree.
 * @tparam T Type of data
 * @time complexity O(n)
 * @space complexity O(n)
 */
template <class T>
void BinaryTree<T>::clear()
{
    m_root = nullptr;
}

/**
 * @brief
 * Prints the binary tree in string format
 * @tparam T Type of data
 * @return std::string String representation of the binary tree
 * @time complexity O(n)
 * @space complexity O(n)
 */
template <class T>
std::string BinaryTree<T>::to_string() const
{
    std::stringstream ss;

    if (is_empty())
        ss << "Empty tree";

    std::queue<std::shared_ptr<Node<T>>> queue;
    queue.push(m_root);

    while (!queue.empty())
    {
        std::shared_ptr<Node<T>> current_node = queue.front();
        queue.pop();

        ss << current_node->get_data() << " ";

        if (current_node->get_left() != nullptr)
            queue.push(current_node->get_left());

        if (current_node->get_right() != nullptr)
            queue.push(current_node->get_right());
    }

    return ss.str();
}

/**
 * @brief
 * Prints the tree in order traversal
 * @tparam T Type of data
 * @time complexity O(n)
 * @space complexity O(n)
 */
template <class T>
std::string BinaryTree<T>::in_order() const
{
    std::stringstream ss;

    if (is_empty())
        ss << "Empty tree";

    std::stack<std::shared_ptr<Node<T>>> stack;
    std::shared_ptr<Node<T>> current_node = m_root;

    while (current_node != nullptr || !stack.empty())
    {
        while (current_node != nullptr)
        {
            stack.push(current_node);
            current_node = current_node->get_left();
        }

        current_node = stack.top();
        stack.pop();

        ss << current_node->get_data() << " ";

        current_node = current_node->get_right();
    }

    return ss.str();
}

/**
 * @brief
 * Prints the tree in pre order traversal
 * @tparam T Type of data
 * @time complexity O(n)
 * @space complexity O(n)
 */
template <class T>
std::string BinaryTree<T>::pre_order() const
{
    std::stringstream ss;

    if (is_empty())
        ss << "Empty tree";

    std::stack<std::shared_ptr<Node<T>>> stack;
    stack.push(m_root);

    while (!stack.empty())
    {
        std::shared_ptr<Node<T>> current_node = stack.top();
        stack.pop();

        ss << current_node->get_data() << " ";

        if (current_node->get_right() != nullptr)
            stack.push(current_node->get_right());

        if (current_node->get_left() != nullptr)
            stack.push(current_node->get_left());
    }

    return ss.str();
}

/**
 * @brief
 * Prints the tree in post order traversal
 * @tparam T Type of data
 * @time complexity O(n)
 * @space complexity O(n)
 */
template <class T>
std::string BinaryTree<T>::post_order() const
{
    std::stringstream ss;

    if (is_empty())
        ss << "Empty tree";

    std::stack<std::shared_ptr<Node<T>>> stack;
    std::shared_ptr<Node<T>> current_node = m_root;
    std::shared_ptr<Node<T>> last_node = nullptr;

    while (current_node != nullptr || !stack.empty())
    {
        while (current_node != nullptr)
        {
            stack.push(current_node);
            current_node = current_node->get_left();
        }

        current_node = stack.top();

        if (current_node->get_right() == nullptr ||
            current_node->get_right() == last_node)
        {
            ss << current_node->get_data() << " ";
            stack.pop();
            last_node = current_node;
            current_node = nullptr;
        }

        else
            current_node = current_node->get_right();
    }

    return ss.str();
}