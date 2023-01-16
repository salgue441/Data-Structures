/**
 * @file Node.cpp
 * @author Carlos Salguero
 * @brief Node implementation for the Stack class
 * @version 0.1
 * @date 2022-12-19
 *
 * @copyright Copyright (c) 2022
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
Node<T>::Node(const T &data)
{
    m_data = data;
}

/**
 * @brief Construct a new Node< T>:: Node object
 * @tparam T Type of the data
 * @param data Data to be stored in the node
 * @param next Pointer to the next node
 */
template <class T>
Node<T>::Node(const T &data, const std::shared_ptr<Node<T>> &next)
{
    m_data = data;
    m_next = next;
}

// Getters
/**
 * @brief
 * Get the Data object
 * @tparam T Type of the data
 * @return T Data stored in the node
 */
template <class T>
T Node<T>::get_data() const
{
    return m_data;
}

/**
 * @brief
 * Get the Next object
 * @tparam T Type of the data
 * @return std::shared_ptr<Node<T>> Pointer to the next node
 */
template <class T>
std::shared_ptr<Node<T>> Node<T>::get_next() const
{
    return m_next;
}

// Setters
/**
 * @brief
 * Sets the data of the node
 * @tparam T Type of the data
 * @param data Data to be stored in the node
 */
template <class T>
void Node<T>::set_data(const T &data)
{
    m_data = data;
}

/**
 * @brief
 * Sets the next node
 * @tparam T Type of the data
 * @param next Pointer to the next node
 */
template <class T>
void Node<T>::set_next(const std::shared_ptr<Node<T>> &next)
{
    m_next = next;
}