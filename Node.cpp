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
 */
template <typename T>
std::shared_ptr<Node<T>> Node<T>::get_next() const
{
    return next;
}
