/**
 * @file SinglyCircularLinkedList.h
 * @author Carlos Salguero
 * @brief Definition of a Singly Circular Linked List
 * @version 0.1
 * @date 2023-01-04
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SINGLY_CIRCULAR_LINKED_LIST_H
#define SINGLY_CIRCULAR_LINKED_LIST_H

#include <memory>
#include <string>
#include <sstream>
#include <optional>

#include "Node.cpp"

template <class T>
class SinglyCircularLinkedList
{
public:
    // Constructors
    SinglyCircularLinkedList() = default;
    SinglyCircularLinkedList(T);
    SinglyCircularLinkedList(T, std::shared_ptr<Node<T>>);

    // Destructor
    ~SinglyCircularLinkedList() = default;

    // Getters
    std::shared_ptr<Node<T>> get_head() const;
    unsigned int get_size() const;
    T get_data() const;

    // Operator overload
    template <typename ostream_t>
    friend std::ostream &operator<<(std::ostream &,
                                    const SinglyCircularLinkedList<ostream_t> &);

    // Methods
    bool is_empty() const;
    std::optional<std::shared_ptr<Node<T>>> search(T) const;

    void push_front(T);
    void push_back(T);
    void insert(T, unsigned int);

    void pop_front();
    void pop_back();
    void remove(unsigned int);

    void reverse();

    std::string to_string() const;

    // Sorts
    void ascending_bubble_sort();
    void ascending_selection_sort();
    void ascending_insertion_sort();
    void ascending_merge_sort();
    void ascending_quick_sort();

    void descending_bubble_sort();
    void descending_selection_sort();
    void descending_insertion_sort();
    void descending_merge_sort();
    void descending_quick_sort();

private:
    std::shared_ptr<Node<T>> head;
    unsigned int size{};
    T data{};

    // Private methods
    void swap_nodes(std::shared_ptr<Node<T>>, std::shared_ptr<Node<T>>);

    // Privatae sorts
    std::shared_ptr<Node<T>> middle(std::shared_ptr<Node<T>> &);
    std::shared_ptr<Node<T>> merge_sort(std::shared_ptr<Node<T>>);
    std::shared_ptr<Node<T>> merge_sort_descending(std::shared_ptr<Node<T>>);
    std::shared_ptr<Node<T>> merge(std::shared_ptr<Node<T>>,
                                   std::shared_ptr<Node<T>>);
};

#endif //! SINGLY_CIRCULAR_LINKED_LIST_H