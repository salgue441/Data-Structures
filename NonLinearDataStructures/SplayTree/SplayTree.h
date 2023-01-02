/**
 * @file SplayTree.h
 * @author Carlos Salguero
 * @brief Declaration of the SplayTree class
 * @version 0.1
 * @date 2023-01-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SPLAYTREE_H
#define SPLAYTREE_H

#include <memory> // C++11, smart pointers
#include <queue>  // C++11, queue
#include <optional>
#include <string>
#include <sstream>

#include "Node.cpp"

template <class T>
class SplayTree
{
public:
  // Constructors
  SplayTree() = default;
  SplayTree(std::shared_ptr<Node<T>>);
  SplayTree(std::shared_ptr<Node<T>> &);

  // Destructor
  ~SplayTree() = default;

  // Getters
  std::shared_ptr<Node<T>> get_root() const;

  // Operator overload
  template <typename ostream_t>
  friend std::ostream &operator<<(std::ostream &, const SplayTree<ostream_t> &);

  // Functions
  bool is_empty() const;
  bool contains(const T &) const;
  bool contains_node(const std::shared_ptr<Node<T>> &) const;
  std::optional<std::shared_ptr<Node<T>>> find(
      const std::shared_ptr<Node<T>> &, const T &) const;

  void insert(const T &);
  void remove(const T &);
  void clear();

  std::string to_string() const;

private:
  std::shared_ptr<Node<T>> root;

  // Private getters
  std::shared_ptr<Node<T>> get_parent(const std::shared_ptr<Node<T>> &) const;
  std::shared_ptr<Node<T>> get_grandparent(const std::shared_ptr<Node<T>> &)
      const;

  // Private methods
  void splay(const std::shared_ptr<Node<T>> &);
  void zig(const std::shared_ptr<Node<T>> &);
  void zig_zig(const std::shared_ptr<Node<T>> &);
  void zig_zag(const std::shared_ptr<Node<T>> &);
  void zag(const std::shared_ptr<Node<T>> &);
  void zag_zag(const std::shared_ptr<Node<T>> &);
  void zag_zig(const std::shared_ptr<Node<T>> &);
};

#endif //! SPLAYTREE_H