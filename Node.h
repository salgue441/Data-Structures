#ifndef NODE_H
#define NODE_H

#include <memory>

template <typename T>
class Node
{
public:
    // Constructor
    Node() = default;
    Node(const T &);
    Node(const T &, std::shared_ptr<Node<T>>);

    // Destructor
    ~Node() = default;

    // Getters
    T get_data() const;
    std::shared_ptr<Node<T>> get_next() const;

private:
    T data;
    std::shared_ptr<Node<T>> next;
};

#endif //! NODE_H