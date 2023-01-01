/**
 * @file Heap.h
 * @author Carlos Salguero
 * @brief Declaration of the Heap class
 * @version 0.1
 * @date 2022-12-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef HEAP_H
#define HEAP_H

#include <memory>
#include <optional>
#include <queue>

#include "Node.cpp"

template <class T>
class Heap
{
public:
    // Constructor
    Heap() = default;
    Heap(std::shared_ptr<Node<T>> &);

    // Destructor
    ~Heap() = default;

    // Getter
    std::shared_ptr<Node<T>> get_root() const;

    // Operator overload
    template <typename ostream_t>
    friend std::ostream &operator<<(std::ostream &, const Heap<T> &);

    // Methods
    bool is_empty() const;

    void insert(const T &);
    void remove(const T &);

    std::optional<std::shared_ptr<Node<T>>> extract_max();
    std::optional<std::shared_ptr<Node<T>>> search(const T &) const;

private:
    std::shared_ptr<Node<T>> root;

    // Helper functions
    std::shared_ptr<Node<T>> get_parent(std::shared_ptr<Node<T>> &);
    std::shared_ptr<Node<T>> get_left_child(std::shared_ptr<Node<T>> &);
    std::shared_ptr<Node<T>> get_right_child(std::shared_ptr<Node<T>> &);

    void swap(std::shared_ptr<Node<T>> &, std::shared_ptr<Node<T>> &);
    void heapify(std::shared_ptr<Node<T>> &);
};

#endif //! HEAP_H