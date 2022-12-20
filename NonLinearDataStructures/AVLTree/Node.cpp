/**
 * @file Node.cpp
 * @author Carlos Salguero
 * @brief Implementation of the Node class for the AVLTree class
 * @version 0.1
 * @date 2022-12-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Node.h"

// Constructor
/**
 * @brief
 * Construct a new Node< T>:: Node object
 * @tparam T Type of the data
 * @param data Data to be stored in the node
 */
template <class T>
Node<T>::Node(const T &data) : data(data), left(nullptr), right(nullptr) {}

/**
 * @brief
 * Construct a new Node< T>:: Node object
 * @tparam T Type of the data
 * @param data Data to be stored in the node
 * @param left Pointer to the left child
 * @param right Pointer to the right child
 */
template <class T>
Node<T>::Node(const T &data, const std::shared_ptr<Node> &left,
              const std::shared_ptr<Node> &right)
{
    this->data = data;
    this->left = left;
    this->right = right;
}

// Getters
/**
 * @brief
 * Get the data stored in the node
 * @tparam T Type of the data
 * @return T Data stored in the node
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
T Node<T>::get_data() const
{
    return data;
}

/**
 * @brief
 * Get the pointer to the left child
 * @tparam T Type of the data
 * @return std::shared_ptr<Node> Pointer to the left child
 */
template <class T>
std::shared_ptr<Node<T>> Node<T>::get_left() const
{
    return left;
}

/**
 * @brief
 * Get the pointer to the right child
 * @tparam T Type of the data
 * @return std::shared_ptr<Node> Pointer to the right child
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
std::shared_ptr<Node<T>> Node<T>::get_right() const
{
    return right;
}

// Setters
/**
 * @brief
 * Set the data stored in the node
 * @tparam T Type of the data
 * @param data Data to be stored in the node
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void Node<T>::set_data(const T &data)
{
    this->data = data;
}

/**
 * @brief
 * Set the pointer to the left child
 * @tparam T Type of the data
 * @param left Pointer to the left child
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void Node<T>::set_left(const std::shared_ptr<Node> &left)
{
    this->left = left;
}

/**
 * @brief
 * Set the pointer to the right child
 * @tparam T Type of the data
 * @param right Pointer to the right child
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void Node<T>::set_right(const std::shared_ptr<Node> &right)
{
    this->right = right;
}