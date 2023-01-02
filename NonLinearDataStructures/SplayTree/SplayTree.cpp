/**
 * @file SplayTree.cpp
 * @author Carlos Salguero
 * @brief Implementation of the SplayTree class
 * @version 0.1
 * @date 2023-01-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "SplayTree.h"

// Constructors
/**
 * @brief
 * Construct a new Splay Tree:: Splay Tree object
 * @tparam T Type of the data to be stored in the tree
 * @param root Root of the tree
 */
template <class T>
SplayTree<T>::SplayTree(std::shared_ptr<Node<T>> root) : root(root)
{
}

/**
 * @brief
 * Construct a new Splay Tree:: Splay Tree object
 * @tparam T Type of the data to be stored in the tree
 * @param root Root of the tree
 */
template <class T>
SplayTree<T>::SplayTree(std::shared_ptr<Node<T>> &root) : root(root)
{
}

// Private getters
/**
 * @brief
 * Get the parent of a node
 * @tparam T Type of the data to be stored in the tree
 * @param node Node to get the parent of
 * @return std::shared_ptr<Node<T>> Parent of the node
 * @return nullptr If the node is the root
 * @throw std::invalid_argument If the node is not in the tree
 * @throw std::invalid_argument If the node is nullptr
 * @time complexity O(log n)
 * @space complexity O(1)
 */
template <class T>
std::shared_ptr<Node<T>> SplayTree<T>::get_parent(
    const std::shared_ptr<Node<T>> &node) const
{
  if (!contains_node(node))
    throw std::invalid_argument("Node is not in the tree");

  if (node == nullptr)
    throw std::invalid_argument("Node is nullptr");

  if (node == root)
    return nullptr;

  return node->get_parent();
}

/**
 * @brief
 * Get the grandparent of a node
 * @tparam T Type of the data to be stored in the tree
 * @param node Node to get the grandparent of
 * @return std::shared_ptr<Node<T>> Grandparent of the node
 * @return nullptr If the node is the root or the parent of the root
 * @throw std::invalid_argument If the node is not in the tree
 * @throw std::invalid_argument If the node is nullptr
 * @time complexity O(log n)
 * @space complexity O(1)
 */
template <class T>
std::shared_ptr<Node<T>> SplayTree<T>::get_grandparent(
    const std::shared_ptr<Node<T>> &node) const
{
  if (!contains_node(node))
    throw std::invalid_argument("Node is not in the tree");

  if (node == nullptr)
    throw std::invalid_argument("Node is nullptr");

  if (node == root || node->get_parent() == root)
    return nullptr;

  return node->get_parent()->get_parent();
}

// Getters
/**
 * @brief
 * Get the root of the tree
 * @tparam T Type of the data to be stored in the tree
 * @return std::shared_ptr<Node<T>> Root of the tree
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
std::shared_ptr<Node<T>> SplayTree<T>::get_root() const
{
  return root;
}

// Operator overloads
/**
 * @brief
 * Overload the << operator to print the tree
 * @tparam ostream_t Type of the data to be stored in the tree
 * @param os Output stream
 * @param tree Tree to print
 * @return std::ostream& Output stream
 * @throw std::invalid_argument If the tree is empty
 * @time complexity O(n)
 * @space complexity O(n)
 */
template <typename ostream_t>
std::ostream &operator<<(std::ostream &os, const SplayTree<ostream_t> &tree)
{
  if (tree.is_empty())
    throw std::invalid_argument("Tree is empty");

  std::queue<std::shared_ptr<Node<ostream_t>>> queue;
  queue.push(tree.get_root());

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

  return os;
}

// Private methods
/**
 * @brief
 * Zig rotation of a node with its parent (left rotation)
 * @tparam T Type of the data to be stored in the tree
 * @param node Node to rotate
 * @throw std::invalid_argument If the node is not in the tree
 * @throw std::invalid_argument If the node is nullptr
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void SplayTree<T>::zig(const std::shared_ptr<Node<T>> &node)
{
  if (!contains_node(node))
    throw std::invalid_argument("Node is not in the tree");

  if (node == nullptr)
    throw std::invalid_argument("Node is nullptr");

  auto parent = node->get_parent();

  if (parent == nullptr)
    return;

  if (node == parent->get_left())
  {
    parent->set_left(node->get_right());
    node->set_right(parent);
  }

  else
  {
    parent->set_right(node->get_left());
    node->set_left(parent);
  }

  node->set_parent(parent->get_parent());
  parent->set_parent(node);

  if (node->get_parent() != nullptr)
  {
    if (node->get_parent()->get_left() == parent)
      node->get_parent()->set_left(node);

    else
      node->get_parent()->set_right(node);
  }

  else
    root = node;
}

/**
 * @brief
 * Zig-zig rotation of a node with its parent and grandparent
 * (left-left rotation)
 * @tparam T Type of the data to be stored in the tree
 * @param node Node to rotate
 * @throw std::invalid_argument If the node is not in the tree
 * @throw std::invalid_argument If the node is nullptr
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void SplayTree<T>::zig_zig(const std::shared_ptr<Node<T>> &node)
{
  if (!contains_node(node))
    throw std::invalid_argument("Node is not in the tree");

  if (node == nullptr)
    throw std::invalid_argument("Node is nullptr");

  auto parent = node->get_parent();
  auto grandparent = parent->get_parent();

  if (grandparent == nullptr)
    return;

  if (node == parent->get_left())
  {
    parent->set_left(node->get_right());
    node->set_right(parent);
    grandparent->set_left(parent->get_right());
    parent->set_right(grandparent);
  }

  else
  {
    parent->set_right(node->get_left());
    node->set_left(parent);
    grandparent->set_right(parent->get_left());
    parent->set_left(grandparent);
  }

  node->set_parent(grandparent->get_parent());
  parent->set_parent(node);
  grandparent->set_parent(parent);

  if (node->get_parent() != nullptr)
  {
    if (node->get_parent()->get_left() == grandparent)
      node->get_parent()->set_left(node);

    else
      node->get_parent()->set_right(node);
  }

  else
    root = node;
}

/**
 * @brief
 * Zig-zag rotation of a node with its parent and grandparent
 * (left-right rotation)
 * @tparam T Type of the data to be stored in the tree
 * @param node Node to rotate
 * @throw std::invalid_argument If the node is not in the tree
 * @throw std::invalid_argument If the node is nullptr
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void SplayTree<T>::zig_zag(const std::shared_ptr<Node<T>> &node)
{
  if (!contains_node(node))
    throw std::invalid_argument("Node is not in the tree");

  if (node == nullptr)
    throw std::invalid_argument("Node is nullptr");

  auto parent = node->get_parent();
  auto grandparent = parent->get_parent();

  if (grandparent == nullptr)
    return;

  if (node == parent->get_left())
  {
    parent->set_left(node->get_right());
    node->set_right(parent);
    grandparent->set_right(node->get_left());
    node->set_left(grandparent);
  }

  else
  {
    parent->set_right(node->get_left());
    node->set_left(parent);
    grandparent->set_left(node->get_right());
    node->set_right(grandparent);
  }

  node->set_parent(grandparent->get_parent());
  parent->set_parent(node);
  grandparent->set_parent(node);

  if (node->get_parent() != nullptr)
  {
    if (node->get_parent()->get_left() == grandparent)
      node->get_parent()->set_left(node);

    else
      node->get_parent()->set_right(node);
  }

  else
    root = node;
}

/**
 * @brief
 * Zag rotation of a node with its parent (right rotation)
 * @tparam T Type of the data to be stored in the tree
 * @param node Node to rotate
 * @throw std::invalid_argument If the node is not in the tree
 * @throw std::invalid_argument If the node is nullptr
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void SplayTree<T>::zag(const std::shared_ptr<Node<T>> &node)
{
  if (!contains_node(node))
    throw std::invalid_argument("Node is not in the tree");

  if (node == nullptr)
    throw std::invalid_argument("Node is nullptr");

  auto parent = node->get_parent();

  if (parent == nullptr)
    return;

  if (node == parent->get_left())
  {
    parent->set_left(node->get_right());
    node->set_right(parent);
  }

  else
  {
    parent->set_right(node->get_left());
    node->set_left(parent);
  }

  node->set_parent(parent->get_parent());
  parent->set_parent(node);

  if (node->get_parent() != nullptr)
  {
    if (node->get_parent()->get_left() == parent)
      node->get_parent()->set_left(node);

    else
      node->get_parent()->set_right(node);
  }

  else
    root = node;
}

/**
 * @brief
 * Zag zag rotation of a node with its parent and grandparent
 * (right-right rotation)
 * @tparam T Type of the data to be stored in the tree
 * @param node Node to rotate
 * @throw std::invalid_argument If the node is not in the tree
 * @throw std::invalid_argument If the node is nullptr
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void SplayTree<T>::zag_zag(const std::shared_ptr<Node<T>> &node)
{
  if (!contains_node(node))
    throw std::invalid_argument("Node is not in the tree");

  if (node == nullptr)
    throw std::invalid_argument("Node is nullptr");

  auto parent = node->get_parent();
  auto grandparent = parent->get_parent();

  if (grandparent == nullptr)
    return;

  if (node == parent->get_left())
  {
    parent->set_left(node->get_right());
    node->set_right(parent);
    grandparent->set_right(parent->get_left());
    parent->set_left(grandparent);
  }

  else
  {
    parent->set_right(node->get_left());
    node->set_left(parent);
    grandparent->set_left(parent->get_right());
    parent->set_right(grandparent);
  }

  node->set_parent(grandparent->get_parent());
  parent->set_parent(node);
  grandparent->set_parent(parent);

  if (node->get_parent() != nullptr)
  {
    if (node->get_parent()->get_left() == grandparent)
      node->get_parent()->set_left(node);

    else
      node->get_parent()->set_right(node);
  }

  else
    root = node;
}

/**
 * @brief
 * Zag zig rotation of a node with its parent and grandparent
 * (right-left rotation)
 * @tparam T Type of the data to be stored in the tree
 * @param node Node to rotate
 * @throw std::invalid_argument If the node is not in the tree
 * @throw std::invalid_argument If the node is nullptr
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void SplayTree<T>::zag_zig(const std::shared_ptr<Node<T>> &node)
{
  if (!contains_node(node))
    throw std::invalid_argument("Node is not in the tree");

  if (node == nullptr)
    throw std::invalid_argument("Node is nullptr");

  auto parent = node->get_parent();
  auto grandparent = parent->get_parent();

  if (grandparent == nullptr)
    return;

  if (node == parent->get_left())
  {
    parent->set_left(node->get_right());
    node->set_right(parent);
    grandparent->set_right(node->get_left());
    node->set_left(grandparent);
  }

  else
  {
    parent->set_right(node->get_left());
    node->set_left(parent);
    grandparent->set_left(node->get_right());
    node->set_right(grandparent);
  }

  node->set_parent(grandparent->get_parent());
  parent->set_parent(node);
  grandparent->set_parent(node);

  if (node->get_parent() != nullptr)
  {
    if (node->get_parent()->get_left() == grandparent)
      node->get_parent()->set_left(node);

    else
      node->get_parent()->set_right(node);
  }

  else
    root = node;
}

/**
 * @brief
 * Splay a node to the root of the tree
 * @tparam T Type of the data to be stored in the tree
 * @param node Node to splay
 * @throw std::invalid_argument If the node is not in the tree
 * @throw std::invalid_argument If the node is nullptr
 * @time complexity O(log n)
 * @space complexity O(1)
 */
template <class T>
void SplayTree<T>::splay(const std::shared_ptr<Node<T>> &node)
{
  if (!contains_node(node))
    throw std::invalid_argument("Node is not in the tree");

  if (node == nullptr)
    throw std::invalid_argument("Node is nullptr");

  while (node->get_parent() != nullptr)
  {
    auto parent = node->get_parent();
    auto grandparent = parent->get_parent();

    if (grandparent == nullptr)
    {
      if (node == parent->get_left())
        zig(node);

      else
        zag(node);
    }

    else
    {
      if (node == parent->get_left())
      {
        if (parent == grandparent->get_left())
          zig_zig(node);

        else
          zig_zag(node);
      }

      else
      {
        if (parent == grandparent->get_left())
          zag_zig(node);

        else
          zag_zag(node);
      }
    }
  }
}

// Methods
/**
 * @brief
 * Check if the tree is empty
 * @tparam T Type of the data to be stored in the tree
 * @return true If the tree is empty
 * @return false If the tree is not empty
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
bool SplayTree<T>::is_empty() const
{
  return root == nullptr;
}

/**
 * @brief
 * Check if the tree contains a node with a specific data
 * @tparam T Type of the data to be stored in the tree
 * @param data Data to check if it is in the tree
 * @return true If the tree contains a node with the data
 * @return false If the tree does not contain a node with the data
 * @time complexity O(log n)
 * @space complexity O(1)
 */
template <class T>
bool SplayTree<T>::contains(const T &data) const
{
  auto node = std::make_shared<Node<T>>(data);
  return contains_node(node);
}

/**
 * @brief
 * Check if a node is in the tree
 * @tparam T Type of the data to be stored in the tree
 * @param node Node to check if it is in the tree
 * @return true If the node is in the tree
 * @return false If the node is not in the tree
 * @time complexity O(log n)
 * @space complexity O(1)
 */
template <class T>
bool SplayTree<T>::contains_node(const std::shared_ptr<Node<T>> &node) const
{
  if (node == nullptr)
    return false;

  if (node == root)
    return true;

  return contains_node(node->get_parent());
}

/**
 * @brief
 * Find a node in the tree with a specific data
 * @tparam T Type of the data to be stored in the tree
 * @param data Data to find in the tree
 * @return std::shared_ptr<Node<T>> Node with the data
 * @return std::nullopt If the data is not in the tree
 * @time complexity O(log n)
 * @space complexity O(1)
 */
template <class T>
std::optional<std::shared_ptr<Node<T>>>
SplayTree<T>::find(const T &data) const
{
  return find(root, data);
}

/**
 * @brief
 * Find a node in the tree
 * @tparam T Type of the data to be stored in the tree
 * @param node Node to start the search
 * @param data Data to find in the tree
 * @return std::shared_ptr<Node<T>> Node with the data
 * @return std::nullopt If the data is not in the tree
 * @time complexity O(log n)
 * @space complexity O(1)
 */
template <class T>
std::optional<std::shared_ptr<Node<T>>>
SplayTree<T>::find(
    const std::shared_ptr<Node<T>> &node, const T &data) const
{
  if (node == nullptr)
    return std::nullopt;

  if (node->get_data() == data)
    return node;

  if (data < node->get_data())
    return find(node->get_left(), data);

  return find(node->get_right(), data);
}

/**
 * @brief
 * Insert a node in the tree
 * @tparam T Type of the data to be stored in the tree
 * @param data Data to be stored in the node
 * @throw std::invalid_argument If the data is already in the tree
 * @time complexity O(log n)
 * @space complexity O(1)
 */
template <class T>
void SplayTree<T>::insert(const T &data)
{
  if (contains(data))
    throw std::invalid_argument("Data is already in the tree");

  auto node = std::make_shared<Node<T>>(data);

  if (is_empty())
  {
    root = node;
    return;
  }

  auto current = root;

  while (true)
  {
    if (data < current->get_data())
    {
      if (current->get_left() == nullptr)
      {
        current->set_left(node);
        break;
      }

      current = current->get_left();
    }

    else
    {
      if (current->get_right() == nullptr)
      {
        current->set_right(node);
        break;
      }

      current = current->get_right();
    }
  }
}

/**
 * @brief
 * Remove a node from the tree
 * @tparam T Type of the data to be stored in the tree
 * @param data Data to be removed from the tree
 * @throw std::invalid_argument If the data is not in the tree
 * @time complexity O(log n)
 * @space complexity O(1)
 */
template <class T>
void SplayTree<T>::remove(const T &data)
{
  if (!contains(data))
    throw std::invalid_argument("Data is not in the tree");

  auto node = find_node(data);

  if (node->get_left() == nullptr && node->get_right() == nullptr)
  {
    if (node == root)
    {
      root = nullptr;
      return;
    }

    auto parent = node->get_parent();

    if (parent->get_left() == node)
      parent->set_left(nullptr);

    else
      parent->set_right(nullptr);

    splay(parent);
  }

  else if (node->get_left() == nullptr)
  {
    auto right = node->get_right();

    if (node == root)
    {
      root = right;
      right->set_parent(nullptr);
      return;
    }

    auto parent = node->get_parent();

    if (parent->get_left() == node)
      parent->set_left(right);

    else
      parent->set_right(right);

    right->set_parent(parent);
    splay(right);
  }

  else if (node->get_right() == nullptr)
  {
    auto left = node->get_left();

    if (node == root)
    {
      root = left;
      left->set_parent(nullptr);
      return;
    }

    auto parent = node->get_parent();

    if (parent->get_left() == node)
      parent->set_left(left);

    else
      parent->set_right(left);

    left->set_parent(parent);
    splay(left);
  }

  else
  {
    auto successor = get_successor(node);
    auto parent = node->get_parent();

    if (parent->get_left() == node)
      parent->set_left(successor);

    else
      parent->set_right(successor);

    successor->set_parent(parent);
    successor->set_left(node->get_left());
    node->get_left()->set_parent(successor);

    if (successor != node->get_right())
    {
      auto successor_parent = successor->get_parent();
      successor_parent->set_left(successor->get_right());

      if (successor->get_right() != nullptr)
        successor->get_right()->set_parent(successor_parent);

      successor->set_right(node->get_right());
      node->get_right()->set_parent(successor);
    }

    splay(successor);
  }
}

/**
 * @brief
 * Clear the tree
 * @tparam T Type of the data to be stored in the tree
 * @throw std::invalid_argument If the tree is empty
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void SplayTree<T>::clear()
{
  if (is_empty())
    throw std::invalid_argument("Tree is empty");

  root = nullptr;
}

/**
 * @brief
 * Prints the tree in order.
 * @tparam T Type of the data to be stored in the tree
 * @return std::string String representation of the tree
 * @throw std::invalid_argument If the tree is empty
 * @time complexity O(n)
 * @space complexity O(n)
 */
template <class T>
std::string SplayTree<T>::in_order() const
{
  if (is_empty())
    throw std::invalid_argument("Tree is empty");

  std::stringstream stream;

  // Lambda function to print the tree in order
  std::function<void(const std::shared_ptr<Node<T>> &)> in_order =
      [&stream, &in_order](const std::shared_ptr<Node<T>> &node)
  {
    if (node == nullptr)
      return;

    in_order(node->get_left());
    stream << node->get_data() << " ";
    in_order(node->get_right());
  };

  in_order(root);

  return stream.str();
}

/**
 * @brief
 * Prints the tree in pre order.
 * @tparam T Type of the data to be stored in the tree
 * @return std::string String representation of the tree
 * @throw std::invalid_argument If the tree is empty
 * @time complexity O(n)
 * @space complexity O(n)
 */
template <class T>
std::string SplayTree<T>::pre_order() const
{
  if (is_empty())
    throw std::invalid_argument("Tree is empty");

  std::stringstream stream;

  // Lambda function to print the tree in pre order
  std::function<void(const std::shared_ptr<Node<T>> &)> pre_order =
      [&stream, &pre_order](const std::shared_ptr<Node<T>> &node)
  {
    if (node == nullptr)
      return;

    stream << node->get_data() << " ";
    pre_order(node->get_left());
    pre_order(node->get_right());
  };

  pre_order(root);

  return stream.str();
}

/**
 * @brief
 * Prints the tree in post order.
 * @tparam T Type of the data to be stored in the tree
 * @return std::string String representation of the tree
 * @throw std::invalid_argument If the tree is empty
 * @time complexity O(n)
 * @space complexity O(n)
 */
template <class T>
std::string SplayTree<T>::post_order() const
{
  if (is_empty())
    throw std::invalid_argument("Tree is empty");

  std::stringstream stream;

  // Lambda function to print the tree in post order
  std::function<void(const std::shared_ptr<Node<T>> &)> post_order =
      [&stream, &post_order](const std::shared_ptr<Node<T>> &node)
  {
    if (node == nullptr)
      return;

    post_order(node->get_left());
    post_order(node->get_right());
    stream << node->get_data() << " ";
  };

  post_order(root);

  return stream.str();
}