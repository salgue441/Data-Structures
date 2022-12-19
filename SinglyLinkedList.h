/**
 * @file LinkedList.h
 * @author Carlos Salguero
 * @brief Declaration of the LinkedList class
 * @version 0.1
 * @date 2022-12-18
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <memory>

#include "Node.h"

template <typename T>
class SinglyLinkedList
{
public:
    // Constructor
    SinglyLinkedList() = default;
    SinglyLinkedList(const T &);
    SinglyLinkedList(const T &, std::shared_ptr<Node<T>>);

    // Destructor
    ~SinglyLinkedList() = default;

    // Getters
    std::shared_ptr<Node<T>> get_head() const;
    unsigned int get_size() const;

    T get_front() const;
    T get_last() const;
    T get_at_index(const size_t &) const;

    // Functions
    long int index_of(const T &) const;

    bool is_empty() const;
    bool contains(const T &) const;

    void clear();
    void push_front(const T &);
    void push_back(const T &);

    void insert(const T &, const size_t &);
    void insert(const T &, const std::shared_ptr<Node<T>> &);

    void pop_front();
    void pop_back();
    void remove(const size_t &);
    void reverse();

    std::string to_string() const;

private:
    std::shared_ptr<Node<T>> head{};
    unsigned int size{};
};

#endif //! SINGLY_LINKED_LIST_H