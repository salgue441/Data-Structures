/**
 * @file Node.cpp
 * @author Carlos Salguero
 * @brief Implementation of the Node class
 * @version 0.1
 * @date 2022-12-18
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Node.h"

// Constructor
/**
 * @brief
 * Construct a new Node< T>:: Node object
 * @tparam T Type of node
 * @param data Data to be stored in the node
 */
template <typename T>
Node<T>::Node(const T &data)
    : data{data}, next{nullptr}
{
}

/**
 * @brief
 * Construct a new Node< T>:: Node object
 * @tparam T Type of node
 * @param data Data to be stored in the node
 * @param next Pointer to the next node
 */
template <typename T>
Node<T>::Node(const T &data, std::shared_ptr<Node<T>> next)
    : data{data}, next{next}
{
}

// Getters
/**
 * @brief
 * Get the data stored in the node
 * @tparam T Type of node
 * @return T Data stored in the node
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <typename T>
T Node<T>::get_data() const
{
    return data;
}

/**
 * @brief
 * Get the next node
 * @tparam T Type of node
 * @return std::shared_ptr< Node< T>> Pointer to the next node
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <typename T>
std::shared_ptr<Node<T>> Node<T>::get_next() const
{
    return next;
}
