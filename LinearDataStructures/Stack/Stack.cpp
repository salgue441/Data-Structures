/**
 * @file Stack.cpp
 * @author Carlos Salguero
 * @brief Implementation of the Stack class
 * @version 0.1
 * @date 2022-12-19
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Stack.h"

// Constructor
/**
 * @brief Construct a new Stack< T>:: Stack object
 * @tparam T Type of the data
 * @param size Size of the stack
 */
template <class T>
Stack<T>::Stack(size_t size) : m_size(size)
{
    m_top = nullptr;
}

/**
 * @brief Construct a new Stack< T>:: Stack object
 * @tparam T Type of the data
 * @param size Size of the stack
 * @param top Pointer to the top of the stack
 */
template <class T>
Stack<T>::Stack(size_t size, std::shared_ptr<Node<T>> top)
    : m_size(size), m_top(top)
{
}

// Getters
/**
 * @brief
 * Get the Size object
 * @tparam T Type of the data
 * @return size_t Size of the stack
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
size_t Stack<T>::get_size() const
{
    return m_size;
}

/**
 * @brief
 * Get the Top object
 * @tparam T Type of the data
 * @return std::shared_ptr<Node<T>> Pointer to the top of the stack
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
std::shared_ptr<Node<T>> Stack<T>::get_top() const
{
    return m_top;
}

// Operator overloading
/**
 * @brief
 * Overload the << operator
 * @tparam T Type of the data
 * @param os Output stream
 * @param stack Stack to be printed
 * @return std::ostream& Output stream
 * @time complexity O(n)
 * @space complexity O(1)
 */
template <typename ostream_t>
std::ostream &operator<<(std::ostream &os, const Stack<ostream_t> &stack)
{
    std::shared_ptr<Node<ostream_t>> current = stack.m_top;

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
 * Check if the stack is empty
 * @tparam T Type of the data
 * @return true Stack is empty
 * @return false Stack is not empty
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
bool Stack<T>::is_empty() const
{
    return m_top == nullptr;
}

/**
 * @brief
 * Check if the stack is full
 * @tparam T Type of the data
 * @return true Stack is full
 * @return false Stack is not full
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
bool Stack<T>::is_full() const
{
    return m_size == 0;
}

/**
 * @brief
 * Check if the stack contains a value
 * @tparam T Type of the data
 * @param value Value to be searched
 * @return true Stack contains the value
 * @return false Stack does not contain the value
 * @time complexity O(n)
 * @space complexity O(1)
 */
template <class T>
bool Stack<T>::contains(const T &value) const
{
    std::shared_ptr<Node<T>> current = m_top;

    while (current != nullptr)
    {
        if (current->get_data() == value)
            return true;

        current = current->get_next();
    }

    return false;
}

/**
 * @brief
 * Push a value to the stack
 * @tparam T Type of the data
 * @param value Value to be pushed
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void Stack<T>::push(const T &value)
{
    if (is_full())
        return;

    std::shared_ptr<Node<T>> new_node = std::make_shared<Node<T>>(value);

    new_node->set_next(m_top);
    m_top = new_node;
    m_size--;
}

/**
 * @brief
 * Pop a value from the stack
 * @tparam T Type of the data
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void Stack<T>::pop()
{
    if (is_empty())
        return;

    m_top = m_top->get_next();
    m_size++;
}

/**
 * @brief
 * Clears the stack.
 * @tparam T Type of the data
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void Stack<T>::clear()
{
    m_top = nullptr;
    m_size = 0;
}

/**
 * @brief
 * Peeks the top of the stack
 * @tparam T Type of the data
 * @return T Value at the top of the stack
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
std::optional<T> Stack<T>::peek() const
{
    if (is_empty())
        return std::nullopt;

    return m_top->get_data();
}

/**
 * @brief
 * Prints the stack to the console
 * @tparam T Type of the data
 * @return std::string String representation of the stack
 * @time complexity O(n)
 * @space complexity O(1)
 */
template <class T>
std::string Stack<T>::to_string() const
{
    std::stringstream ss;
    ss << *this;

    return ss.str();
}