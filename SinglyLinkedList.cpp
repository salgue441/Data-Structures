/**
 * @file LinkedList.cpp
 * @author Carlos Salguero
 * @brief
 * @version 0.1
 * @date 2022-12-18
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "SinglyLinkedList.h"

// Constructor
/**
 * @brief
 * Construct a new SinglyLinkedList< T>:: SinglyLinkedList object
 * @tparam T Type of node
 * @param data Data to be stored in the node
 */
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(const T &data)
    : head{std::make_shared<Node<T>>(data)}, size{1}
{
}

/**
 * @brief
 * Construct a new SinglyLinkedList< T>:: SinglyLinkedList object
 * @tparam T Type of node
 * @param data Data to be stored in the node
 * @param next Pointer to the next node
 */
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(const T &data, std::shared_ptr<Node<T>> next)
    : head{std::make_shared<Node<T>>(data, next)}, size{1}
{
}

// Getters
/**
 * @brief
 * Get the head of the list
 * @tparam T Type of node
 * @return std::shared_ptr< Node< T>> Pointer to the head of the list
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <typename T>
std::shared_ptr<Node<T>> SinglyLinkedList<T>::get_head() const
{
    return head;
}

/**
 * @brief
 * Get the size of the list
 * @tparam T Type of node
 * @return size_t Size of the list
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <typename T>
unsigned int SinglyLinkedList<T>::get_size() const
{
    return size;
}

/**
 * @brief
 * Get the data stored in the first node
 * @tparam T Type of node
 * @return T Data stored in the first node
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <typename T>
T SinglyLinkedList<T>::get_front() const
{
    return head->get_data();
}

/**
 * @brief
 * Get the data stored in the last node
 * @tparam T Type of node
 * @return T Data stored in the last node
 * @time complexity O(n)
 * @space complexity O(1)
 */
template <typename T>
T SinglyLinkedList<T>::get_last() const
{
    auto current = head;

    while (current->get_next() != nullptr)
        current = current->get_next();

    return current->get_data();
}

/**
 * @brief
 * Get the data stored in the given index
 * @tparam T Type of node
 * @param index Index of the node
 * @throw std::out_of_range If the index is out of range
 * @return T Data stored in the given index
 * @time complexity O(n)
 * @space complexity O(1)
 */
template <typename T>
T SinglyLinkedList<T>::get_at_index(const size_t &index) const
{
    if (index >= size)
        throw std::out_of_range("Index out of range");

    auto current = head;

    for (size_t i = 0; i < index; i++)
        current = current->get_next();

    return current->get_data();
}

// Functions
