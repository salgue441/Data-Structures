/**
* @file Node.h
* @author Carlos Salguero
* @brief Node class declaration for Splay Tree. 
*
* @version 0.1
*
* @date 2023-01-01
*/

#ifndef NODE_H
#define NODE_H

#include <memory>

template <class T>
class Node
{
public:
  // Constructor
  Node() = default;
  Node(std::shared_ptr<Node>, std::shared_ptr<Node>);
  Node(std::shared_ptr<Node> &, std::shared_ptr<Node> &);

  // Destructor
  ~Node() = default;

  // Getters
  std::shared_ptr<Node> get_left() const;
  std::shared_ptr<Node> get_right() const;

  // Setters
  void set_left(std::shared_ptr<Node>);
  void set_right(std::shared_ptr<Node>);
  void set_left(std::shared_ptr<Node> &);
  void set_right(std::shared_ptr<Node> &);

private:
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;
};

#endif //! NODE_H
