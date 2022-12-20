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
 * @tparam T Type of the data stored in the heap
 * @param root Root of the heap
 */
template <class T>
Heap<T>::Heap(std::shared_ptr<Node<T>> &root)
{
    this->root = root;
}

// Getter
/**
 * @brief
 * Get the root of the heap
 * @tparam T Type of the data stored in the heap
 * @return std::shared_ptr<Node<T>> Root of the heap
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
std::shared_ptr<Node<T>> Heap<T>::get_root() const
{
    return this->root;
}

// Operator overload
/**
 * @brief
 * Overload the << operator to print the heap
 * @tparam T Type of the data stored in the heap
 * @tparam ostream_t Type of the output stream
 * @param os Output stream
 * @param heap Heap to print
 * @return std::ostream& Output stream
 */
template <typename ostream_t>
std::ostream &operator<<(std::ostream &os, const Heap<ostream_t> &heap)
{
    auto root = heap.get_root();

    if (root == nullptr)
    {
        os << "Heap is empty" << std::endl;
        return os;
    }

    std::queue<std::shared_ptr<Node<ostream_t>>> queue;
    queue.push(root);

    while (!queue.empty())
    {
        auto node = queue.front();
        queue.pop();

        os << node->get_data() << " ";

        if (node->get_left() != nullptr)
            queue.push(node->get_left());

        if (node->get_right() != nullptr)
            queue.push(node->get_right());
    }

    return os;
}

// Private helper functions
/**
 * @brief
 * Get the parent of a node
 * @tparam T Type of the data stored in the heap
 * @param node Node to get the parent of
 * @return std::shared_ptr<Node<T>> Parent of the node
 * @time complexity O(n)
 * @space complexity O(n)
 */
template <class T>
std::shared_ptr<Node<T>> Heap<T>::get_parent(std::shared_ptr<Node<T>> &node)
{
    auto root = this->get_root();

    if (root == nullptr)
        return nullptr;

    if (root == node)
        return nullptr;

    std::queue<std::shared_ptr<Node<T>>> queue;
    queue.push(root);

    while (!queue.empty())
    {
        auto current_node = queue.front();
        queue.pop();

        if (current_node->get_left() == node ||
            current_node->get_right_child() == node)
            return current_node;

        if (current_node->get_left() != nullptr)
            queue.push(current_node->get_left());

        if (current_node->get_right_child() != nullptr)
            queue.push(current_node->get_right_child());
    }

    return nullptr;
}

/**
 * @brief
 * Get the left child of a node
 * @tparam T Type of the data stored in the heap
 * @param node Node to get the left child of
 * @return std::shared_ptr<Node<T>> Left child of the node
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
std::shared_ptr<Node<T>> Heap<T>::get_left_child(std::shared_ptr<Node<T>> &node)
{
    return node->get_left();
}

/**
 * @brief
 * Get the right child of a node
 * @tparam T Type of the data stored in the heap
 * @param node Node to get the right child of
 * @return std::shared_ptr<Node<T>> Right child of the node
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
std::shared_ptr<Node<T>> Heap<T>::get_right_child(std::shared_ptr<Node<T>> &node)
{
    return node->get_right();
}

/**
 * @brief
 * Swaps the data of two nodes
 * @tparam T Type of the data stored in the heap
 * @param node1 First node
 * @param node2 Second node
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void Heap<T>::swap(std::shared_ptr<Node<T>> &node1,
                   std::shared_ptr<Node<T>> &node2)
{
    auto temp = node1->get_data();
    node1->set_data(node2->get_data());
    node2->set_data(temp);
}

/**
 * @brief
 * Heapify the heap
 * @tparam T Type of the data stored in the heap
 * @param node Node to heapify
 * @time complexity O(n)
 * @space complexity O(n)
 */
template <class T>
void Heap<T>::heapify(std::shared_ptr<Node<T>> &node)
{
    if (node == nullptr)
        return;

    auto left_child = this->get_left_child(node);
    auto right_child = this->get_right_child(node);

    if (left_child != nullptr && left_child->get_data() > node->get_data())
    {
        this->swap(left_child, node);
        this->heapify(left_child);
    }

    if (right_child != nullptr && right_child->get_data() > node->get_data())
    {
        this->swap(right_child, node);
        this->heapify(right_child);
    }
}

// Public functions
/**
 * @brief
 * Checks if the heap is empty
 * @tparam T Type of the data stored in the heap
 * @return true If the heap is empty
 * @return false If the heap is not empty
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
bool Heap<T>::is_empty() const
{
    return this->root == nullptr;
}

/**
 * @brief
 * Insert a node into the heap
 * @tparam T Type of the data stored in the heap
 * @param data Data to insert
 * @time complexity O(n)
 * @space complexity O(n)
 */
template <class T>
void Heap<T>::insert(const T &data)
{
    auto new_node = std::make_shared<Node<T>>(data);

    if (this->root == nullptr)
    {
        this->root = new_node;
        return;
    }

    std::queue<std::shared_ptr<Node<T>>> queue;
    queue.push(this->root);

    while (!queue.empty())
    {
        auto node = queue.front();
        queue.pop();

        if (node->get_left() == nullptr)
        {
            node->set_left(new_node);
            break;
        }

        else
            queue.push(node->get_left());

        if (node->get_right() == nullptr)
        {
            node->set_right(new_node);
            break;
        }

        else
            queue.push(node->get_right());
    }

    this->heapify(this->root);
}

/**
 * @brief
 * Remove a node from the heap
 * @tparam T Type of the data stored in the heap
 * @param data Data to remove
 * @time complexity O(n)
 * @space complexity O(n)
 */
template <class T>
void Heap<T>::remove(const T &data)
{
    if (this->root == nullptr)
        return;

    std::queue<std::shared_ptr<Node<T>>> queue;
    queue.push(this->root);

    while (!queue.empty())
    {
        auto node = queue.front();
        queue.pop();

        if (node->get_data() == data)
        {
            node->set_data(this->root->get_data());
            this->root = nullptr;
            break;
        }

        if (node->get_left() != nullptr)
        {
            if (node->get_left()->get_data() == data)
            {
                node->set_left(nullptr);
                break;
            }

            else
                queue.push(node->get_left());
        }

        if (node->get_right() != nullptr)
        {
            if (node->get_right()->get_data() == data)
            {
                node->set_right(nullptr);
                break;
            }

            else
                queue.push(node->get_right());
        }
    }

    this->heapify(this->root);
}

/**
 * @brief
 * Extracts the max value from the heap.
 * @tparam T Type of the data stored in the heap
 * @return std::optional<std::shared_ptr<Node<T>>>
 *        Pointer to the node if found
 * @return std::nullopt if not found
 * @time complexity O(n)
 * @space complexity O(n)
 */
template <class T>
std::optional<std::shared_ptr<Node<T>>> Heap<T>::extract_max()
{
    if (this->root == nullptr)
        return std::nullopt;

    auto max = this->root;
    this->remove(this->root->get_data());

    return max;
}

/**
 * @brief
 * Finds a node in the heap
 * @tparam T Type of the data stored in the heap
 * @param data Data to find
 * @return std::optional<std::shared_ptr<Node<T>>>
 *         Pointer to the node if found
 * @return std::nullopt if not found
 * @time complexity O(n)
 * @space complexity O(n)
 */
template <class T>
std::optional<std::shared_ptr<Node<T>>> Heap<T>::search(const T &data) const
{
    if (this->root == nullptr)
        return std::nullopt;

    std::queue<std::shared_ptr<Node<T>>> queue;
    queue.push(this->root);

    while (!queue.empty())
    {
        auto node = queue.front();
        queue.pop();

        if (node->get_data() == data)
            return node;

        if (node->get_left() != nullptr)
            queue.push(node->get_left());

        if (node->get_right() != nullptr)
            queue.push(node->get_right());
    }

    return std::nullopt;
}