/**
 * @file Node.h
 * @author Carlos Salguero
 * @brief Declaration of the Node class for SplayTree
 * @version 0.1
 * @date 2023-01-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef NODE_H
#define NODE_H

#include <memory> // C++11, smart pointers

template <class T>
class Node
{
public:
  // Constructors
  Node() = default;
  Node(const T &);
  Node(const T &, std::shared_ptr<Node<T>>);
  Node(const T &, std::shared_ptr<Node<T>>, std::shared_ptr<Node<T>>);
  Node(const T &, std::shared_ptr<Node<T>>, std::shared_ptr<Node<T>>,
       std::shared_ptr<Node<T>>);

  // Destructor
  ~Node() = default;

  // Getters
  T get_data() const;
  std::shared_ptr<Node<T>> get_left() const;
  std::shared_ptr<Node<T>> get_right() const;
  std::shared_ptr<Node<T>> get_parent() const;

  // Setters
  void set_data(const T &);
  void set_left(std::shared_ptr<Node<T>>);
  void set_right(std::shared_ptr<Node<T>>);
  void set_parent(std::shared_ptr<Node<T>>);

private:
  T data;
  std::shared_ptr<Node<T>> left;
  std::shared_ptr<Node<T>> right;
  std::shared_ptr<Node<T>> parent;
};

#endif //! NODE_H