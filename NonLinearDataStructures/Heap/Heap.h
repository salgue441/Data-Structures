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

#include <string>
#include <memory>   // std::shared_ptr, for get_root()
#include <optional> // std::optional, for find()
#include <sstream>  // std::stringstream, for to_string()
#include <queue>    // std::queue, for std_string()

#include "Node.cpp"

template <class T>
class Heap
{
public:
    // Constructor
    Heap() = default;
    Heap(size_t);
    Heap(const std::shared_ptr<Node<T>> &);
    Heap(const std::shared_ptr<Node<T>> &, size_t);

    // Destructor
    ~Heap() = default;

    // Getters
    std::shared_ptr<Node<T>> get_root() const;
    size_t get_size() const;

    // Operator overloads
    template <typename ostream_t>
    friend std::ostream &operator<<(ostream_t &, const Heap<ostream_t> &);

    // Methods
    bool is_empty() const;

    void insert(const T &);
    void remove(const T &);
    void clear();

    std::optional<std::shared_ptr<Node<T>>> find(
        const std::shared_ptr<Node<T>> &) const;
    std::string to_string() const;

private:
    std::shared_ptr<Node<T>> m_root;
    size_t m_size;

    // Sorting methods
    void heap_sort();
    void heapify();

    // Heap methods
    void build_heap();
};

#endif //! HEAP_H