/**
* @file Node.cpp
* @author Carlos Salguero
* @brief Node class implementation for Splay Tree.
*   
* @version 0.1
*
* @date 2023-01-01
*/

#include "Node.h"

// Constructor
/*
* @brief Construct a new Node:: Node object
* @param left Left child of the node
* @param right Right child of the node
*/
template <class T>
Node<T>::Node(std::shared_ptr<Node<T>> left, std::shared_ptr<Node<T>> right)
{
  this->left = left;
  this->right = right;
};

/*
* @brief Construct a new Node:: Node object
* @param left Left child of the node
* @param right Right child of the node
*/
template <class T>
Node<T>::Node(std::shared_ptr<Node<T>> &left, std::shared_ptr<Node<T>> &right)
{
  this->left = left;
  this->right = right;
};

// Getters
/*
* @brief Get the left child of the node
* @return std::shared_ptr<Node> Left child of the node
* @time complexity O(1)
* @space complexity O(1)
*/
template <class T>
std::shared_ptr<Node<T>> Node<T>::get_left() const
{
  return this->left;
};

/*
* @brief Get the right child of the node
* @return std::shared_ptr<Node> Right child of the node
* @time complexity O(1)
* @space complexity O(1)
*/
template <class T>
std::shared_ptr<Node<T>> Node<T>::get_right() const
{
  return this->right;
}

// Setters
/*
* @brief Set the left child of the node
* @param left Left child of the node
* @time complexity O(1)
* @space complexity O(1)
*/
template <class T>
void Node<T>::set_left(std::shared_ptr<Node> left)
{
  this->left = left;
}

/*
* @brief Set the right child of the node
* @param right Right child of the node
* @time complexity O(1)
* @space complexity O(1)
*/
template <class T>
void Node<T>::set_right(std::shared_ptr<Node<T>> right)
{
  this->right = right;
}

