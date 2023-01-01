/**
 * @file SinglyCircularLinkedList.h
 * @author Carlos Salguero
 * @brief Declaration of the SinglyCircularLinkedList class
 * @version 0.1
 * @date 2022-12-19
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef SINGLY_CIRCULAR_LINKED_LIST_H
#define SINGLY_CIRCULAR_LINKED_LIST_H

#include <string>
#include <sstream>  // For std::stringstream in to_string()
#include <memory>   // C++11, for std::shared_ptr and std::make_shared()
#include <optional> // C++17, for std::optional encapsulation

#include "Node.cpp"

template <class T>
class SinglyCircularLinkedList
{
public:
    // Constructor
    SinglyCircularLinkedList() = default;
    SinglyCircularLinkedList(const T &);
    SinglyCircularLinkedList(const T &, std::shared_ptr<Node<T>>);
    SinglyCircularLinkedList(const T &, std::shared_ptr<Node<T>>, size_t);

    // Destructor
    ~SinglyCircularLinkedList() = default;

    // Getters
    std::shared_ptr<Node<T>> get_head() const;
    size_t get_size() const;

    // Operator overloading
    template <typename ostream_t>
    friend std::ostream &operator<<(std::ostream &,
                                    const SinglyCircularLinkedList<ostream_t> &);

    // Functions
    bool is_empty() const;
    bool contains(const T &) const;

    void push_front(const T &);
    void push_back(const T &);
    void insert_at(const T &, size_t);

    void pop_front();
    void pop_back();
    void remove_at(size_t);

    void reverse();

    std::optional<T> search(const T &) const;
    std::optional<T> search_at(size_t) const;

    std::string to_string() const;

    // Sorting algorithms
    void bubble_sort(const std::optional<bool> &order = true);
    void selection_sort(const std::optional<bool> &order = true);
    void insertion_sort(const std::optional<bool> &order = true);
    void merge_sort(const std::optional<bool> &order = true);
    void quick_sort(const std::optional<bool> &order = true);

private:
    std::shared_ptr<Node<T>> m_head;
    std::shared_ptr<Node<T>> m_tail;
    size_t m_size{};

    // Private sorting algorithms
    void bubble_sort_ascending();
    void bubble_sort_descending();

    void selection_sort_ascending();
    void selection_sort_descending();

    void insertion_sort_ascending();
    void insertion_sort_descending();

    void merge_sort_ascending();
    void merge_sort_descending();

    void quick_sort_ascending();
    void quick_sort_descending();
};

#endif //! SINGLY_CIRCULAR_LINKED_LIST_H