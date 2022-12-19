/**
 * @file Queue.cpp
 * @author Carlos Salguero
 * @brief Implementation of the Queue class
 * @version 0.1
 * @date 2022-12-19
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Queue.h"

// Constructor
/**
 * @brief
 * Construct a new Queue< T>:: Queue object
 * @tparam T Type of the data
 * @param size Size of the queue
 */
template <class T>
Queue<T>::Queue(size_t size) : m_size(size)
{
    m_front = nullptr;
    m_back = nullptr;
}

/**
 * @brief
 * Construct a new Queue< T>:: Queue object
 * @tparam T Type of the data
 * @param size Size of the queue
 * @param front Pointer to the front of the queue
 */
template <class T>
Queue<T>::Queue(size_t size, std::shared_ptr<Node<T>> front)
    : m_size(size), m_front(front)
{
    m_back = nullptr;
}

/**
 * @brief
 * Construct a new Queue< T>:: Queue object
 * @tparam T Type of the data
 * @param size Size of the queue
 * @param front Pointer to the front of the queue
 * @param back Pointer to the back of the queue
 */
template <class T>
Queue<T>::Queue(size_t size, std::shared_ptr<Node<T>> front, std::shared_ptr<Node<T>> back)
    : m_size(size), m_front(front), m_back(back)
{
}

// Getters
/**
 * @brief
 * Get the Size object
 * @tparam T Type of the data
 * @return size_t Size of the queue
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
size_t Queue<T>::get_size() const
{
    return m_size;
}

/**
 * @brief
 * Get the Front object
 * @tparam T Type of the data
 * @return std::shared_ptr<Node<T>> Pointer to the front of the queue
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
std::shared_ptr<Node<T>> Queue<T>::get_front() const
{
    return m_front;
}

/**
 * @brief
 * Get the Back object
 * @tparam T Type of the data
 * @return std::shared_ptr<Node<T>> Pointer to the back of the queue
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
std::shared_ptr<Node<T>> Queue<T>::get_back() const
{
    return m_back;
}

// Operator Overload
/**
 * @brief
 * Overload the << operator
 * @tparam T Type of the data
 * @param os Output stream
 * @param queue Queue to be printed
 * @return std::ostream& Output stream
 * @time complexity O(n)
 * @space complexity O(1)
 */
template <typename ostream_t>
ostream_t &operator<<(ostream_t &os, const Queue<int> &queue)
{
    std::shared_ptr<Node<int>> current = queue.get_front();

    while (current != nullptr)
    {
        os << current->get_data() << " ";
        current = current->get_next();
    }

    return os;
}

// Functions
/**
 * @brief
 * Check if the queue is empty
 * @tparam T Type of the data
 * @return true Queue is empty
 * @return false Queue is not empty
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
bool Queue<T>::is_empty() const
{
    return m_front == nullptr;
}

/**
 * @brief
 * Add a new element to the queue
 * @tparam T Type of the data
 * @param data Data to be added
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void Queue<T>::enqueue(const T &data)
{
    std::shared_ptr<Node<T>> new_node = std::make_shared<Node<T>>(data);

    if (is_empty())
    {
        m_front = new_node;
        m_back = new_node;
    }

    else
    {
        m_back->set_next(new_node);
        m_back = new_node;
    }

    m_size--;
}

/**
 * @brief
 * Clears the queue
 * @tparam T Type of the data
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void Queue<T>::clear()
{
    m_front = nullptr;
    m_back = nullptr;
    m_size = 0;
}

/**
 * @brief
 * Remove the first element of the queue
 * @tparam T Type of the data
 * @return std::optional<T> Data of the first element
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
std::optional<T> Queue<T>::dequeue()
{
    if (is_empty())
    {
        throw std::runtime_error("Queue is empty");
        return std::nullopt;
    }

    std::shared_ptr<Node<T>> temp = m_front;
    m_front = m_front->get_next();
    m_size++;

    return temp->get_data();
}

/**
 * @brief
 * Get the first element of the queue
 * @tparam T Type of the data
 * @return std::optional<T> Data of the first element
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
std::optional<T> Queue<T>::peek() const
{
    if (is_empty())
    {
        throw std::runtime_error("Queue is empty");
        return std::nullopt;
    }

    return m_front->get_data();
}

/**
 * @brief
 * Print the queue
 * @tparam T Type of the data
 * @time complexity O(n)
 * @space complexity O(1)
 */
template <class T>
std::string Queue<T>::to_string() const
{
    std::shared_ptr<Node<T>> current = m_front;
    std::stringstream ss;

    while (current != nullptr)
    {
        ss << current->get_data() << " ";
        current = current->get_next();
    }

    return ss.str();
}