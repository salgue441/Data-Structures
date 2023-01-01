/**
* @file SplayTree.h
* @author Carlos Salguero
* @brief Splay Tree class declaration.
*
* @version 0.1
*
* @date 2023-01-01
*/

#ifndef SPLAY_TREE_H
#define SPLAY_TREE_H

#include <memory>
#include <optional>
#include <queue>

#include "Node.cpp"

template <class T>
class SplayTree{
public:
  // Consturctor
  SplayTree() = default;
  SplayTree(std::shared_ptr<Node<T>>);
  SplayTree(std::shared_ptr<Node<T>> &);

  // Destructor
  ~SplayTree() = default;

  // Getters
  std::shared_ptr<Node<T>> get_root() const;

  // Operator overloads
  template <class ostream_t>
  friend std::ostream &operator<<(std::ostream &, const SplayTree<ostream_t> &);

  // Methods
  bool is_empty() const;
  bool contains() const;
  std::optional<T> search(const T &);

  void insert(const T &);
  void remove(const T &);
  void clear();

private:
  std::shared_ptr<Node<T>> root;

  // Private getters
  std::shared_ptr<Node<T>> get_parent(const std::shared_ptr<Node<T>> &) const;
  std::shared_ptr<Node<T>> get_grandparent(const std::shared_ptr<Node<T>> &) const;

  // Private methods
  void splay(const std::shared_ptr<Node<T>> &);
  void zig(const std::shared_ptr<Node<T>> &);
  void zig_zig(const std::shared_ptr<Node<T>> &);
  void zig_zag(const std::shared_ptr<Node<T>> &);
  void zig_zig_zig(const std::shared_ptr<Node<T>> &);
  void zig_zig_zag(const std::shared_ptr<Node<T>> &);
  void zig_zag_zig(const std::shared_ptr<Node<T>> &);
  void zig_zag_zag(const std::shared_ptr<Node<T>> &);
};

#endif //! SPLAY_TREE_H
