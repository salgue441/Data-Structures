/**
 * @file BST.cpp
 * @author Carlos Salguero
 * @brief Implementation of the BST class for the Binary Search Tree
 * @version 0.1
 * @date 2023-01-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "BST.h"

// Constructors
/**
 * @brief
 * Construct a new BST<T>::BST object
 * @tparam T Type of the data
 * @param data Data to be stored in the root node
 */
template <class T>
BST<T>::BST(const T &data)
{
    root = std::make_shared<Node<T>>(data);
}

/**
 * @brief
 * Construct a new BST<T>::BST object
 * @tparam T Type of the data
 * @param root Root node of the tree
 */
template <class T>
BST<T>::BST(const std::shared_ptr<Node<T>> &root)
{
    this->root = root;
}

/**
 * @brief
 * Construct a new BST<T>::BST object
 * @tparam T Type of the data
 * @param data Data to be stored in the root node
 * @param root Root node of the tree
 */
template <class T>
BST<T>::BST(const T &data, const std::shared_ptr<Node<T>> &root)
{
    this->root = std::make_shared<Node<T>>(data, root);
}

// Getters
/**
 * @brief
 * Get the root node of the tree
 * @tparam T Type of the data
 * @return std::shared_ptr<Node<T>> Root node of the tree
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
std::shared_ptr<Node<T>> BST<T>::get_root() const
{
    return root;
}

// Operator overload
/**
 * @brief
 * Overload the << operator to print the tree
 * @tparam ostream_t Type of the data
 * @param os Output stream
 * @param bst Binary Search Tree
 * @return std::ostream& Output stream
 * @time complexity O(n)
 * @space complexity O(n)
 */
template <typename ostream_t>
std::ostream &operator<<(std::ostream &os, const BST<ostream_t> &bst)
{
    os << bst.to_string();
    return os;
}

// Methods
/**
 * @brief
 * Check if the tree is empty
 * @tparam T Type of the data
 * @return true If the tree is empty
 * @return false If the tree is not empty
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
bool BST<T>::is_empty() const
{
    return root == nullptr;
}

/**
 * @brief
 * Check if the tree contains a node with the given data
 * @tparam T Type of the data
 * @param data Data to be searched
 * @return true If the tree contains the data
 * @return false If the tree does not contain the data
 * @time complexity O(log n)
 * @space complexity O(1)
 */
template <class T>
bool BST<T>::contains(const T &data) const
{
    return find(data) != nullptr;
}

/**
 * @brief
 * Find a node with the given data
 * @tparam T Type of the data
 * @param data Data to be searched
 * @return std::optional<std::shared_ptr<Node<T>>> Node with the given data
 * @return std::nullopt If the tree does not contain the data
 * @throw std::invalid_argument If the tree is empty
 * @time complexity O(log n)
 * @space complexity O(1)
 */
template <class T>
std::optional<std::shared_ptr<Node<T>>> BST<T>::find(const T &data) const
{
    if (is_empty())
        throw std::invalid_argument("The tree is empty");

    std::shared_ptr<Node<T>> current = root;

    while (current != nullptr)
    {
        if (data == current->get_data())
            return current;

        else if (data < current->get_data())
            current = current->get_left();

        else
            current = current->get_right();
    }

    return std::nullopt;
}

/**
 * @brief
 * Insert a node with the given data
 * @tparam T Type of the data
 * @param data Data to be inserted
 * @time complexity O(log n)
 * @space complexity O(1)
 */
template <class T>
void BST<T>::insert(const T &data)
{
    if (is_empty())
    {
        root = std::make_shared<Node<T>>(data);
        return;
    }

    std::shared_ptr<Node<T>> current = root;

    while (current != nullptr)
    {
        if (data == current->get_data())
            return;

        else if (data < current->get_data())
        {
            if (current->get_left() == nullptr)
            {
                current->set_left(std::make_shared<Node<T>>(data));
                return;
            }
            current = current->get_left();
        }

        else
        {
            if (current->get_right() == nullptr)
            {
                current->set_right(std::make_shared<Node<T>>(data));
                return;
            }
            current = current->get_right();
        }
    }
}

/**
 * @brief
 * Remove a node with the given data
 * @tparam T Type of the data
 * @param data Data to be removed
 * @throw std::invalid_argument If the tree is empty
 * @time complexity O(log n)
 * @space complexity O(1)
 */
template <class T>
void BST<T>::remove(const T &data)
{
    if (is_empty())
        throw std::invalid_argument("The tree is empty");

    auto current = root;
    auto parent = std::shared_ptr<Node<T>>{nullptr};

    while (current != nullptr)
    {
        if (data == current->get_data())
        {
            if (current->get_left() == nullptr && current->get_right() == nullptr)
            {
                if (parent == nullptr)
                    root = nullptr;

                else if (parent->get_left() == current)
                    parent->set_left(nullptr);

                else
                    parent->set_right(nullptr);
            }

            else if (current->get_left() == nullptr)
            {
                if (parent == nullptr)
                    root = current->get_right();

                else if (parent->get_left() == current)
                    parent->set_left(current->get_right());

                else
                    parent->set_right(current->get_right());
            }

            else if (current->get_right() == nullptr)
            {
                if (parent == nullptr)
                    root = current->get_left();

                else if (parent->get_left() == current)
                    parent->set_left(current->get_left());

                else
                    parent->set_right(current->get_left());
            }

            else
            {
                auto successor = current->get_right();
                auto successor_parent = current;

                while (successor->get_left() != nullptr)
                {
                    successor_parent = successor;
                    successor = successor->get_left();
                }

                current->set_data(successor->get_data());

                if (successor_parent->get_left() == successor)
                    successor_parent->set_left(successor->get_right());

                else
                    successor_parent->set_right(successor->get_right());
            }

            return;
        }

        else if (data < current->get_data())
        {
            parent = current;
            current = current->get_left();
        }

        else
        {
            parent = current;
            current = current->get_right();
        }
    }
}

/**
 * @brief
 * Clears the tree
 * @tparam T Type of the data
 * @throw std::invalid_argument If the tree is empty
 * @time complexity O(n)
 * @space complexity O(n)
 */
template <class T>
void BST<T>::clear()
{
    if (is_empty())
        throw std::invalid_argument("The tree is empty");

    root = nullptr;
}

/**
 * @brief
 * Prints the tree in string format (inorder traversal)
 * @tparam T Type of the data
 * @return std::string String representation of the tree
 * @throw std::invalid_argument If the tree is empty
 * @time complexity O(n)
 * @space complexity O(n)
 */
template <class T>
std::string BST<T>::to_string() const
{
    if (is_empty())
        throw std::invalid_argument("The tree is empty");

    std::stringstream result;

    std::function<void(std::shared_ptr<Node<T>>)> inorder = [&](std::shared_ptr<Node<T>> node)
    {
        if (node == nullptr)
            return;

        inorder(node->get_left());

        result << node->get_data() << " ";
        inorder(node->get_right());
    };

    inorder(root);

    return result.str();
}