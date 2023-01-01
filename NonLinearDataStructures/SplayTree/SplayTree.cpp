/**
* @file SplayTree.cpp
* @author Carlos Salguero
* @brief Splay Tree class implementation.
*
* @version 0.1
*
* @date 2023-01-01
* @copyright Copyright (c) 2023
*/

#include "SplayTree.h"

// Constructor
/*
* @brief Construct a new SplayTree:: SplayTree object
* @param root Root of the tree
* @time complexity O(1)
* @space complexity O(1)
*/
template <class T>
SplayTree<T>::SplayTree(std::shared_ptr<Node<T>> root)
{
  this->root = root;
};

/**
* @brief Construct a new SplayTree:: SplayTree object
* @param root Root of the tree
* @time complexity O(1)
* @space complexity O(1)
*/
template <class T>
SplayTree<T>::SplayTree(std::shared_ptr<Node<T>> &root)
{
  this->root = root;
};

// Private getters
/*
 * @brief Get the parent of the tree
 * @return std::shared_ptr<Node> Parent of the tree
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
std::shared_ptr<Node<T>> SplayTree<T>::get_parent() const
{
  for (auto it = this->root; it != nullptr; it = it->get_left())
    if (it->get_left() == nullptr)
      return it;

  return nullptr;
}

/*
 * @brief Get the grandparent of the node
 * @return std::shared_ptr<Node> Grandparent of the node
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
std::shared_ptr<Node<T>> SplayTree<T>::get_grandparent() const
{
  std::shared_ptr<Node<T>> parent = this->get_parent();

  if (parent == nullptr)
    return nullptr;

  return parent->get_parent();
}

// Getters
/*
* @brief Get the root of the tree
* @return std::shared_ptr<Node> Root of the tree
* @time complexity O(1)
* @space complexity O(1)
*/
template <class T>
std::shared_ptr<Node<T>> SplayTree<T>::get_root() const
{
  return this->root;
};

// Operator overloads
/*
* @brief Overload the << operator
* @param os Output stream
* @param tree Tree to be printed
* @return std::ostream& Output stream
* @time complexity O(n)
* @space complexity O(n)
*/
template <class ostream_t>
std::ostream &operator<<(std::ostream &os, const SplayTree<ostream_t> &tree)
{
  std::queue<std::shared_ptr<Node<ostream_t>>> q;
  q.push(tree.get_root());

  while (!q.empty())
  {
    std::shared_ptr<Node<ostream_t>> node = q.front();
    q.pop();

    if (node == nullptr)
      continue;

    os << node->get_data() << " ";
    q.push(node->get_left());
    q.push(node->get_right());
  }

  return os;
}

// Private methods
/*
 * @brief Rotate the tree to the left
 * @param node Node to be rotated
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void SplayTree<T>::rotate_left(std::shared_ptr<Node<T>> node)
{
  auto right = node->get_right();
  auto parent = node->get_parent();

  if (parent != nullptr)
  {
    if (parent->get_left() == node)
      parent->set_left(right);
    else
      parent->set_right(right);
  }

  else if (this->root == node)
    this->root = right;

  node->set_right(right->get_left());
  right->set_left(node);

  if (node->get_right() != nullptr)
    node->get_right()->set_parent(node);

  right->set_parent(parent);
  node->set_parent(right);

  if (this->root == right)
    this->root->set_parent(nullptr);

  return;
}

/*
 * @brief Rotate the tree to the right
 * @param node Node to be rotated
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void SplayTree<T>::rotate_right(std::shared_ptr<Node<T>> node)
{
  auto left = node->get_left();
  auto parent = node->get_parent();

  if (parent != nullptr)
  {
    if (parent->get_left() == node)
      parent->set_left(left);
    else
      parent->set_right(left);
  }

  else if (this->root == node)
    this->root = left;

  node->set_left(left->get_right());
  left->set_right(node);

  if (node->get_left() != nullptr)
    node->get_left()->set_parent(node);

  left->set_parent(parent);
  node->set_parent(left);

  if (this->root == left)
    this->root->set_parent(nullptr);

  return;
}
