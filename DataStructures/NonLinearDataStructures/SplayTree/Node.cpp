/**
 * @file Node.cpp
 * @author Carlos Salguero
 * @brief Implementation of the Node class for SplayTree
 * @version 0.1
 * @date 2023-01-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "Node.h"

// Constructor
/**
 * @brief
 * Construct a new Node< T>:: Node object
 * @tparam T Type of data
 * @param data Data to be stored in the node
 */
template <class T>
Node<T>::Node(const T &data) : data(data)
{
  this->left = nullptr;
  this->right = nullptr;
  this->parent = nullptr;
}

/**
 * @brief Construct a new Node< T>:: Node object
 * @tparam T Type of data
 * @param data Data to be stored in the node
 * @param parent Parent node
 */
template <class T>
Node<T>::Node(const T &data, std::shared_ptr<Node<T>> parent)
    : data(data), parent(parent)
{
  this->left = nullptr;
  this->right = nullptr;
}

/**
 * @brief Construct a new Node< T>:: Node object
 * @tparam T Type of data
 * @param data Data to be stored in the node
 * @param left Left child
 * @param right Right child
 */
template <class T>
Node<T>::Node(const T &data, std::shared_ptr<Node<T>> left,
              std::shared_ptr<Node<T>> right)
    : data(data), left(left), right(right)
{
  this->parent = nullptr;
}

/**
 * @brief Construct a new Node< T>:: Node object
 * @tparam T Type of data
 * @param data Data to be stored in the node
 * @param left Left child
 * @param right Right child
 * @param parent Parent node
 */
template <class T>
Node<T>::Node(const T &data, std::shared_ptr<Node<T>> left,
              std::shared_ptr<Node<T>> right, std::shared_ptr<Node<T>> parent)
{
  this->data = data;
  this->left = left;
  this->right = right;
  this->parent = parent;
}

// Getters
/**
 * @brief
 * Get the data stored in the node
 * @tparam T Type of data
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
 * @brief
 * Get the left child of the node
 * @tparam T Type of data
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
 * @brief
 * Get the right child of the node
 * @tparam T Type of data
 * @return std::shared_ptr<Node<T>> Right child of the node
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
std::shared_ptr<Node<T>> Node<T>::get_right() const
{
  return this->right;
}

/**
 * @brief
 * Get the parent of the node
 * @tparam T Type of data
 * @return std::shared_ptr<Node<T>> Parent of the node
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
std::shared_ptr<Node<T>> Node<T>::get_parent() const
{
  return this->parent;
}

// Setters
/**
 * @brief
 * Set the data stored in the node
 * @tparam T Type of data
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
 * Set the left child of the node
 * @tparam T Type of data
 * @param left Left child of the node
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void Node<T>::set_left(std::shared_ptr<Node<T>> left)
{
  this->left = left;
}

/**
 * @brief
 * Set the right child of the node
 * @tparam T Type of data
 * @param right Right child of the node
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void Node<T>::set_right(std::shared_ptr<Node<T>> right)
{
  this->right = right;
}

/**
 * @brief
 * Set the parent of the node
 * @tparam T Type of data
 * @param parent Parent of the node
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void Node<T>::set_parent(std::shared_ptr<Node<T>> parent)
{
  this->parent = parent;
}