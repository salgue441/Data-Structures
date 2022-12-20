/**
 * @file Heap.cpp
 * @author Carlos Salguero
 * @brief Implementation of the Heap class
 * @version 0.1
 * @date 2022-12-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Heap.h"

// Constructor
/**
 * @brief
 * Construct a new Heap< T>:: Heap object
 * @tparam T Type of the data
 * @param size Size of the heap
 */
template <class T>
Heap<T>::Heap(size_t size)
    : m_root(nullptr), m_size(size)
{
}

/**
 * @brief
 * Construct a new Heap< T>:: Heap object
 * @tparam T Type of the data
 * @param root Root of the heap
 */
template <class T>
Heap<T>::Heap(const std::shared_ptr<Node<T>> &root)
    : m_root(root), m_size(0)
{
}

/**
 * @brief
 * Construct a new Heap< T>:: Heap object
 * @tparam T Type of the data
 * @param root Root of the heap
 * @param size Size of the heap
 */
template <class T>
Heap<T>::Heap(const std::shared_ptr<Node<T>> &root, size_t size)
    : m_root(root), m_size(size)
{
}

// Getters
/**
 * @brief
 * Get the root of the heap
 * @tparam T Type of the data
 * @return std::shared_ptr< Node< T>> Root of the heap
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
std::shared_ptr<Node<T>> Heap<T>::get_root() const
{
    return m_root;
}

/**
 * @brief
 * Get the size of the heap
 * @tparam T Type of the data
 * @return size_t Size of the heap
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
size_t Heap<T>::get_size() const
{
    return m_size;
}

// Operator overloading
/**
 * @brief
 * Overload the << operator to print the heap
 * @tparam ostream_t Type of the data
 * @param os Output stream
 * @param heap Heap to be printed
 * @return std::ostream& Output stream
 * @time complexity O(n)
 * @space complexity O(n)
 */
template <typename ostream_t>
std::ostream &operator<<(std::ostream &os, const Heap<ostream_t> &heap)
{
    os << heap.to_string();

    return os;
}

// Sorting Methods
/**
 * @brief
 * Sort the heap using the heap sort algorithm
 * @tparam T Type of the data
 * @time complexity O(n log n)
 * @space complexity O(1)
 */
template <class T>
void Heap<T>::heap_sort()
{
    build_heap();

    for (size_t i = m_size - 1; i > 0; i--)
    {
        std::swap(m_root, get_last_node());

        m_size--;

        heapify(m_root);
    }
}

/**
 * @brief
 * Heapify the heap from root node.
 * @tparam T Type of the data
 * @time complexity O(log n)
 * @space complexity O(1)
 */
template <class T>
void Heap<T>::heapify()
{
    std::shared_ptr<Node<T>> left_child = get_left_child(m_root);
    std::shared_ptr<Node<T>> right_child = get_right_child(m_root);
    std::shared_ptr<Node<T>> largest = m_root;

    if (left_child != nullptr && left_child->get_data() > largest->get_data())
        largest = left_child;

    if (right_child != nullptr && right_child->get_data() > largest->get_data())
        largest = right_child;

    if (largest != m_root)
    {
        std::swap(m_root->get_data(), largest->get_data());
        heapify(largest);
    }
}

// Heap Methods
/**
 * @brief
 * Build the heap
 * @tparam T Type of the data
 * @time complexity O(n)
 * @space complexity O(1)
 */
template <class T>
void Heap<T>::build_heap()
{
    std::shared_ptr<Node<T>> last_node = get_last_node();
    std::shared_ptr<Node<T>> parent = get_parent(last_node);

    while (parent != nullptr)
    {
        heapify(parent);
        parent = get_parent(parent);
    }
}

// Functions
/**
 * @brief
 * Checks if the heap is empty
 * @tparam T Type of the data
 * @return true If the heap is empty
 * @return false If the heap is not empty
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
bool Heap<T>::is_empty() const
{
    return m_size == 0;
}

/**
 * @brief
 * Get the last node of the heap
 * @tparam T Type of the data
 * @time complexity O(n)
 * @space complexity O(1)
 */
template <class T>
void Heap<T>::insert(const T &data)
{
    std::shared_ptr<Node<T>> new_node = std::make_shared<Node<T>>(data);
    std::shared_ptr<Node<T>> last_node = get_last_node();

    if (last_node == nullptr)
        m_root = new_node;

    std::shared_ptr<Node<T>> parent = get_parent(last_node);

    if (parent->get_left_child() == nullptr)
        parent->set_left_child(new_node);
    else
        parent->set_right_child(new_node);

    m_size++;
}

/**
 * @brief
 * Removes a node from the heap
 * @tparam T Type of the data
 * @param data Data to be removed
 * @time complexity O(n)
 * @space complexity O(1)
 */
template <class T>
void Heap<T>::remove(const T &data)
{
    std::shared_ptr<Node<T>> node = find(data);

    if (node == nullptr)
        return;

    std::shared_ptr<Node<T>> last_node = get_last_node();

    std::swap(node->get_data(), last_node->get_data());

    if (last_node == m_root)
        m_root = nullptr;

    std::shared_ptr<Node<T>> parent = get_parent(last_node);

    if (parent->get_left_child() == last_node)
        parent->set_left_child(nullptr);

    else
        parent->set_right_child(nullptr);

    m_size--;

    heapify(m_root);
}

/**
 * @brief
 * Clears the heap
 * @tparam T Type of the data
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void Heap<T>::clear()
{
    m_root = nullptr;
    m_size = 0;
}

/**
 * @brief
 * Find a node in the heap
 * @tparam T Type of the data
 * @param node Node to be searched
 * @return std::optional<std::shared_ptr<Node<T>>>
 *         If the node is found, returns the node
 * @return If the node is not found, returns std::nullopt
 * @time complexity O(n)
 * @space complexity O(1)
 */
template <class T>
std::optional<std::shared_ptr<Node<T>>> Heap<T>::find(
    const std::shared_ptr<Node<T>> &node) const
{
    if (node == nullptr)
        return std::nullopt;

    if (node->get_data() == data)
        return node;

    std::optional<std::shared_ptr<Node<T>>> left_child =
        find(node->get_left_child(), data);
    std::optional<std::shared_ptr<Node<T>>> right_child =
        find(node->get_right_child(), data);

    if (left_child.has_value())
        return left_child;

    if (right_child.has_value())
        return right_child;

    return std::nullopt;
}

/**
 * @brief
 * Prints the heap
 * @tparam T Type of the data
 * @time complexity O(n)
 * @space complexity O(1)
 */
template <class T>
std::string Heap<T>::to_string() const
{
    std::stringstream ss;

    if (m_root == nullptr)
        return ss.str();

    std::queue<std::shared_ptr<Node<T>>> queue;
    queue.push(m_root);

    while (!queue.empty())
    {
        std::shared_ptr<Node<T>> node = queue.front();
        queue.pop();

        ss << node->get_data() << " ";

        if (node->get_left_child() != nullptr)
            queue.push(node->get_left_child());

        if (node->get_right_child() != nullptr)
            queue.push(node->get_right_child());
    }

    return ss.str();
}