/**
 * @file SinglyLinkedList.h
 * @author Carlos Salguero
 * @brief Declaration of the SinglyLinkedList class
 * @version 0.1
 * @date 2022-12-18
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <string>
#include <memory>   // C++11, std::shared_ptr and std::make_shared
#include <optional> // C++17, std::optional encapsulation
#include <sstream>  // std::stringstream for to_string() function

// Custom Headers
#include "Node.cpp"
#include "header.h"

template <class T>
class SinglyLinkedList
{
public:
    // Constructor
    SinglyLinkedList() = default;
    SinglyLinkedList(const T &);
    SinglyLinkedList(const std::shared_ptr<Node<T>> &);
    SinglyLinkedList(const T &, std::shared_ptr<Node<T>>);

    // Destructor
    ~SinglyLinkedList() = default;

    // Getters
    std::shared_ptr<Node<T>> get_head() const;
    unsigned int get_size() const;

    T get_front() const;
    T get_last() const;
    T get_at_index(const size_t &) const;

    // Operator Overload
    template <class ostream_t>
    friend std::ofstream &operator<<(std::ofstream &,
                                     const SinglyLinkedList<ostream_t> &);

    // Functions
    bool is_empty() const;
    bool contains(const T &) const;

    void push_front(const T &);
    void push_back(const T &);
    void push_at_index(const T &, const size_t &);
    void pop_front();
    void pop_back();
    void pop_at_index(const T &);
    void remove_at(const T &);
    void reverse();

    std::string to_string() const;

    // Sorting Algorithms
    void bubble_sort(const std::optional<bool> &order = true);
    void insertion_sort(const std::optional<bool> &order = true);
    void selection_sort(const std::optional<bool> &order = true);
    void quick_sort(const std::optional<bool> &order = true);
    void merge_sort(const std::optional<bool> &order = true);

private:
    std::shared_ptr<Node<T>> head{};
    unsigned int size{};
};

#endif //! SINGLY_LINKED_LIST_H