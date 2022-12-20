/**
 * @file Node.cpp
 * @author Carlos Salguero
 * @brief Node Implementation for Splay Tree
 * @version 0.1
 * @date 2022-12-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Node.h"

// Constructor
/**
 * @brief Construct a new Node< T>:: Node object
 * @tparam T Type of the data stored in the node
 * @param data Data to store in the node
 */
template <class T>
Node<T>::Node(const T &data)
{
    this->data = data;
}

/**
 * @brief Construct a new Node< T>:: Node object
 * @tparam T Type of the data stored in the node
 * @param data Data to store in the node
 * @param left Left child of the node
 * @param right Right child of the node
 */
template <class T>
Node<T>::Node(const T &data, const std::shared_ptr<Node<T>> &left,
              const std::shared_ptr<Node<T>> &right)
{
    this->data = data;
    this->left = left;
    this->right = right;
}

// Getter
/**
 * @brief Get the data stored in the node
 * @tparam T Type of the data stored in the node
 * @return T Data stored in the node
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
T Node<T>::get_data() const
{
    return this->data;
}

/**
 * @brief Get the left child of the node
 * @tparam T Type of the data stored in the node
 * @return std::shared_ptr<Node<T>> Left child of the node
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
std::shared_ptr<Node<T>> Node<T>::get_left() const
{
    return this->left;
}

/**
 * @brief Get the right child of the node
 * @tparam T Type of the data stored in the node
 * @return std::shared_ptr<Node<T>> Right child of the node
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
std::shared_ptr<Node<T>> Node<T>::get_right() const
{
    return this->right;
}

// Setter
/**
 * @brief Set the data stored in the node
 * @tparam T Type of the data stored in the node
 * @param data Data to store in the node
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void Node<T>::set_data(const T &data)
{
    this->data = data;
}

/**
 * @brief Set the left child of the node
 * @tparam T Type of the data stored in the node
 * @param left Left child of the node
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void Node<T>::set_left(const std::shared_ptr<Node<T>> &left)
{
    this->left = left;
}

/**
 * @brief Set the right child of the node
 * @tparam T Type of the data stored in the node
 * @param right Right child of the node
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void Node<T>::set_right(const std::shared_ptr<Node<T>> &right)
{
    this->right = right;
}