/**
 * @file Node.cpp
 * @author Carlos Salguero
 * @brief Implementation of the Node class for the Singly Circular Linked List
 * @version 0.1
 * @date 2023-01-03
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "Node.h"

// Constructor
/**
 * @brief
 * Construct a new Node< T>:: Node object
 * @tparam T Type of the data
 * @param data Data to be stored in the node
 */
template <class T>
Node<T>::Node(T &data) : data(data)
{
    this->next = nullptr;
}

/**
 * @brief
 * Construct a new Node< T>:: Node object
 * @tparam T Type of the data
 * @param data Data to be stored in the node
 * @param next Pointer to the next node
 */
template <class T>
Node<T>::Node(T &data, std::shared_ptr<Node<T>> next) : data(data), next(next)
{
}

// Getters
/**
 * @brief
 * Get the next object
 * @tparam T Type of the data
 * @return std::shared_ptr<Node<T>> Pointer to the next node
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
std::shared_ptr<Node<T>> Node<T>::get_next() const
{
    return this->next;
}

/**
 * @brief
 * Get the data object
 * @tparam T Type of the data
 * @return T Data stored in the node
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
T Node<T>::get_data() const
{
    return this->data;
}

// Setters
/**
 * @brief
 * Set the next object
 * @tparam T Type of the data
 * @param next Pointer to the next node
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void Node<T>::set_next(std::shared_ptr<Node<T>> next)
{
    this->next = next;
}

/**
 * @brief
 * Set the data object
 * @tparam T Type of the data
 * @param data Data to be stored in the node
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void Node<T>::set_data(T data)
{
    this->data = data;
}