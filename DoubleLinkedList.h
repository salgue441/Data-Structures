/**
 * @file DoubleLinkedList.h
 * @author Carlos Salguero
 * @brief Declaration of the DoubleLinkedList class
 * @version 0.1
 * @date 2022-12-18
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <string>
#include <memory>   // C++11, std::shared_ptr and std::make_shared
#include <optional> // C++17, std::optional encapsulation
#include <sstream>  // std::stringstream for to_string() function

#include "Node.cpp"

template <class T>
class DoubleLinkedList
{
public:
    // Constructor
    DoubleLinkedList() = default;
    DoubleLinkedList(const T &);
    DoubleLinkedList(const T &, std::shared_ptr<Node<T>>,
                     std::shared_ptr<Node<T>>);

    // Destructor
    ~DoubleLinkedList() = default;

    // Getters
    size_t get_size() const;
    std::shared_ptr<Node<T>> get_head() const;
    std::shared_ptr<Node<T>> get_tail() const;

    T get_before(std::shared_ptr<Node<T>>) const;
    T get_after(std::shared_ptr<Node<T>>) const;

    // Operator Overloads
    template <class ostream_t>
    friend std::ostream_t &operator<<(std::ostream_t &,
                                      const DoubleLinkedList<ostream_t> &);

    // Functions
    bool is_empty() const;
    bool contains(const T &) const;

    void clear();
    void push_front(const T &);
    void push_back(const T &);

    void pop_front();
    void pop_back();
    void remove_at(const T &);
    void insert_at(const T &, const T &);
    void replace_at(const T &, const T &);
    void reverse();

    std::string to_string() const;

    // Sorting Algorithms
    void bubble_sort(std::optional<bool> &order = true);
    void bubble_sort_ascending();
    void bubble_sort_descending();

    void selection_sort(std::optional<bool> &order = true);
    void selection_sort_ascending();
    void selection_sort_descending();

    void insertion_sort(std::optional<bool> &order = true);
    void insertion_sort_ascending();
    void insertion_sort_descending();

    void quick_sort(std::optional<bool> &order = true);
    void quick_sort_ascending();
    void quick_sort_descending();

    void merge_sort(std::optional<bool> &order = true);

private:
    std::shared_ptr<Node<T>> head;
    std::shared_ptr<Node<T>> tail;
    size_t size;
};

#endif //! DOUBLE_LINKED_LIST_H