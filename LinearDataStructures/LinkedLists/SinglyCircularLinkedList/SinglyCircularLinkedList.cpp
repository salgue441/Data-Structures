/**
 * @file SinglyCircularLinkedList.cpp
 * @author Carlos Salguero
 * @brief Implementation of the SinglyCircularLinkedList class
 * @version 0.1
 * @date 2022-12-19
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "SinglyCircularLinkedList.h"

/**
 * @brief
 * Construct a new SinglyCircularLinkedList< T>:: SinglyCircularLinkedList
 * object
 * @tparam T Type of the data
 * @param data Data to be stored in the head node
 */
template <class T>
SinglyCircularLinkedList<T>::SinglyCircularLinkedList(const T &data)
    : m_head(std::make_shared<Node<T>>(data))
{
    m_head->set_next(m_head);
}

/**
 * @brief
 * Construct a new Singly Circular Linked List< T>:: Singly Circular Linked
 * List object
 * @tparam T Type of the data
 * @param data Data to be stored in the head node
 * @param next Pointer to the next node
 */
template <class T>
SinglyCircularLinkedList<T>::SinglyCircularLinkedList(const T &data,
                                                      std::shared_ptr<Node<T>> next)
    : m_head(std::make_shared<Node<T>>(data, next))
{
}

/**
 * @brief Construct a new Singly Circular Linked List< T>:: Singly Circular
 * Linked List object
 * @tparam T Type of the data
 * @param data Data to be stored in the head node
 * @param next Pointer to the next node
 * @param size Size of the list
 */
template <class T>
SinglyCircularLinkedList<T>::SinglyCircularLinkedList(const T &data,
                                                      std::shared_ptr<Node<T>> next, size_t size)
    : m_head(std::make_shared<Node<T>>(data, next)), m_size(size)
{
}

// Getters
/**
 * @brief
 * Get the head node
 * @tparam T Type of the data
 * @return std::shared_ptr<Node<T>> Pointer to the head node
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
std::shared_ptr<Node<T>> SinglyCircularLinkedList<T>::get_head() const
{
    return m_head;
}

/**
 * @brief
 * Get the size of the list
 * @tparam T Type of the data
 * @return size_t Size of the list
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
size_t SinglyCircularLinkedList<T>::get_size() const
{
    return m_size;
}

// Operator overloading
/**
 * @brief
 * Overload the << operator to print the list
 * @tparam T Type of the data
 * @param os Output stream
 * @param list List to be printed
 * @return std::ostream& Output stream
 * @time complexity O(n)
 * @space complexity O(1)
 */
template <class T>
std::ostream &operator<<(std::ostream &os, const SinglyCircularLinkedList<T> &list)
{
    std::shared_ptr<Node<T>> current = list.get_head();

    do
    {
        os << current->get_data() << " ";
        current = current->get_next();
    } while (current != list.get_head());

    return os;
}

// Functions
/**
 * @brief
 * Checks if the list is empty
 * @tparam T Type of the data
 * @return true If the list is empty
 * @return false If the list is not empty
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
bool SinglyCircularLinkedList<T>::is_empty() const
{
    return (m_head == nullptr);
}

/**
 * @brief
 * Checks if the list contains a given value
 * @tparam T Type of the data
 * @param data Value to be searched
 * @return true If the list contains the value
 * @return false If the list does not contain the value
 * @time complexity O(n)
 * @space complexity O(1)
 */
template <class T>
bool SinglyCircularLinkedList<T>::contains(const T &data) const
{
    std::shared_ptr<Node<T>> current = m_head;

    do
    {
        if (current->get_data() == data)
            return true;

        current = current->get_next();
    } while (current != m_head);

    return false;
}

/**
 * @brief
 * Insert a new node at the beginning of the list
 * @tparam T Type of the data
 * @param data Data to be stored in the new node
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void SinglyCircularLinkedList<T>::push_front(const T &data)
{
    std::shared_ptr<Node<T>> new_node = std::make_shared<Node<T>>(data, m_head);

    if (is_empty())
    {
        m_head = new_node;
        m_head->set_next(m_head);
    }

    else
    {
        std::shared_ptr<Node<T>> current = m_head;

        while (current->get_next() != m_head)
            current = current->get_next();

        current->set_next(new_node);
        m_head = new_node;
    }

    m_size++;
}

/**
 * @brief
 * Insert a new node at the end of the list
 * @tparam T Type of the data
 * @param data Data to be stored in the new node
 * @time complexity O(n)
 * @space complexity O(1)
 */
template <class T>
void SinglyCircularLinkedList<T>::push_back(const T &data)
{
    std::shared_ptr<Node<T>> new_node = std::make_shared<Node<T>>(data, m_head);

    if (is_empty())
    {
        m_head = new_node;
        m_head->set_next(m_head);
    }

    else
    {
        std::shared_ptr<Node<T>> current = m_head;

        while (current->get_next() != m_head)
            current = current->get_next();

        current->set_next(new_node);
    }

    m_size++;
}

/**
 * @brief
 * Insert a new node at a given position
 * @tparam T Type of the data
 * @param data Data to be stored in the new node
 * @param pos Position where the new node is to be inserted
 * @throw std::out_of_range If the position is invalid
 * @time complexity O(n)
 * @space complexity O(1)
 */
template <class T>
void SinglyCircularLinkedList<T>::insert_at(const T &data, size_t pos)
{
    if (pos > m_size)
        throw std::out_of_range("Invalid position");

    else if (pos == 0)
        push_front(data);

    else if (pos == m_size)
        push_back(data);

    else
    {
        std::shared_ptr<Node<T>> new_node = std::make_shared<Node<T>>(data, nullptr);
        std::shared_ptr<Node<T>> current = m_head;

        for (size_t i = 0; i < pos - 1; i++)
            current = current->get_next();

        new_node->set_next(current->get_next());
        current->set_next(new_node);

        m_size++;
    }
}

/**
 * @brief
 * Remove the first node of the list
 * @tparam T Type of the data
 * @throw std::out_of_range If the list is empty
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void SinglyCircularLinkedList<T>::pop_front()
{
    if (is_empty())
        throw std::out_of_range("List is empty");

    else if (m_size == 1)
    {
        m_head = nullptr;
        m_size--;
    }

    else
    {
        std::shared_ptr<Node<T>> current = m_head;

        while (current->get_next() != m_head)
            current = current->get_next();

        current->set_next(m_head->get_next());
        m_head = m_head->get_next();

        m_size--;
    }
}

/**
 * @brief
 * Remove the last node of the list
 * @tparam T Type of the data
 * @throw std::out_of_range If the list is empty
 * @time complexity O(n)
 * @space complexity O(1)
 */
template <class T>
void SinglyCircularLinkedList<T>::pop_back()
{
    if (is_empty())
        throw std::out_of_range("List is empty");

    else if (m_size == 1)
    {
        m_head = nullptr;
        m_size--;
    }

    else
    {
        std::shared_ptr<Node<T>> current = m_head;

        while (current->get_next()->get_next() != m_head)
            current = current->get_next();

        current->set_next(m_head);
        m_size--;
    }
}

/**
 * @brief
 * Remove a node at a given position
 * @tparam T Type of the data
 * @param pos Position of the node to be removed
 * @throw std::out_of_range If the position is invalid
 * @time complexity O(n)
 * @space complexity O(1)
 */
template <class T>
void SinglyCircularLinkedList<T>::remove_at(size_t pos)
{
    if (pos >= m_size)
        throw std::out_of_range("Invalid position");

    else if (pos == 0)
        pop_front();

    else if (pos == m_size - 1)
        pop_back();

    else
    {
        std::shared_ptr<Node<T>> current = m_head;

        for (size_t i = 0; i < pos - 1; i++)
            current = current->get_next();

        current->set_next(current->get_next()->get_next());

        m_size--;
    }
}

/**
 * @brief
 * Reverses the list
 * @tparam T Type of the data
 * @throw std::out_of_range If the list is empty
 * @time complexity O(n)
 * @space complexity O(1)
 */
template <class T>
void SinglyCircularLinkedList<T>::reverse()
{
    if (is_empty())
        throw std::out_of_range("List is empty");

    // Reverse circular single linked list
    // 1 -> 2 -> 3 -> 4 -> 5 -> 1
    // 1 <- 2 <- 3 <- 4 <- 5 <- 1

    auto current = m_head;
    auto previous = std::shared_ptr<Node<T>>{nullptr};
    auto next = std::shared_ptr<Node<T>>{nullptr};

    for (size_t i = 0; i < m_size; i++)
    {
        next = current->get_next();
        current->set_next(previous);

        previous = current;
        current = next;

        if (current == m_head)
            break;
    }

    m_head = previous;
}

/**
 * @brief
 * Search for a given data in the list
 * @tparam T Type of the data
 * @param data Data to be searched
 * @return std::optional<T> Data if found, std::nullopt otherwise
 */
template <class T>
std::optional<T> SinglyCircularLinkedList<T>::search(const T &data) const
{
    std::shared_ptr<Node<T>> current = m_head;

    do
    {
        if (current->get_data() == data)
            return current->get_data();

        current = current->get_next();
    } while (current != m_head);

    return std::nullopt;
}

/**
 * @brief
 * Searches for a given index in the list.
 * @tparam T Type of the data
 * @param index Index to be searched
 * @return std::optional<T> Data if found, std::nullopt otherwise
 */
template <class T>
std::optional<T> SinglyCircularLinkedList<T>::search_at(size_t index) const
{
    if (index >= m_size)
        return std::nullopt;

    std::shared_ptr<Node<T>> current = m_head;

    for (size_t i = 0; i < index; i++)
        current = current->get_next();

    return current->get_data();
}

/**
 * @brief
 * Prints the list
 * @tparam T Type of the data
 * @return std::string String with the list
 * @time complexity O(n)
 * @space complexity O(1)
 */
template <class T>
std::string SinglyCircularLinkedList<T>::to_string() const
{
    std::stringstream ss;
    std::shared_ptr<Node<T>> current = m_head;

    do
    {
        ss << current->get_data() << " ";
        current = current->get_next();
    } while (current != m_head);

    return ss.str();
}

// Sorting algorithms
/**
 * @brief
 * Bubble sort algorithm. A sorting algorithm that compares each pair of
 * adjacent items and swaps them if they are in the wrong order. The pass
 * through the list is repeated until no swaps are needed, which indicates
 * that the list is sorted.
 * Allows the user to choose the sorting order
 * @tparam T Type of node
 * @param order Sorting order (true = ascending (default), false = descending)
 * @return void
 * @time complexity O(n^2)
 * @space complexity O(1)
 */
template <class T>
void SinglyCircularLinkedList<T>::bubble_sort(const std::optional<bool> &order)
{
    if (is_empty() || m_size == 1)
        return;

    if (order.value_or(true))
        bubble_sort_ascending();

    else
        bubble_sort_descending();
}

/**
 * @brief
 * Insertion sort algorithm. A sorting algorithm that builds the final sorted
 * array (or list) one item at a time. It is much less efficient on large
 * lists than more advanced algorithms such as quicksort, heapsort, or merge
 * sort. Allows the user to choose the sorting order
 * @tparam T Type of node
 * @param order Sorting order (true = ascending (default), false = descending)
 * @return void
 * @time complexity O(n^2)
 * @space complexity O(1)
 */
template <class T>
void SinglyCircularLinkedList<T>::insertion_sort(const std::optional<bool> &order)
{
    if (is_empty() || m_size == 1)
        return;

    if (order.value_or(true))
        insertion_sort_ascending();

    else
        insertion_sort_descending();
}

// Private sorting algorithms
/**
 * @brief
 * Bubble sort algorithm. Ascending order
 * @tparam T Type of node
 * @return void
 * @time complexity O(n^2)
 * @space complexity O(1)
 */
template <class T>
void SinglyCircularLinkedList<T>::bubble_sort_ascending()
{
    auto current = m_head;
    auto next = std::shared_ptr<Node<T>>(nullptr);

    for (size_t i = 0; i < m_size - 1; i++)
    {
        current = m_head;

        for (size_t j = 0; j < m_size - i - 1; j++)
        {
            next = current->get_next();

            if (current->get_data() > next->get_data())
            {
                auto temp = current->get_data();
                current->set_data(next->get_data());
                next->set_data(temp);
            }

            current = current->get_next();
        }
    }
}

/**
 * @brief
 * Bubble sort algorithm. Descending order
 * @tparam T Type of node
 * @return void
 * @time complexity O(n^2)
 * @space complexity O(1)
 */
template <class T>
void SinglyCircularLinkedList<T>::bubble_sort_descending()
{
    auto current = m_head;
    auto next = std::shared_ptr<Node<T>>(nullptr);

    for (size_t i = 0; i < m_size - 1; i++)
    {
        current = m_head;

        for (size_t j = 0; j < m_size - i - 1; j++)
        {
            next = current->get_next();

            if (current->get_data() < next->get_data())
            {
                auto temp = current->get_data();
                current->set_data(next->get_data());
                next->set_data(temp);
            }

            current = current->get_next();
        }
    }
}

/**
 * @brief
 * Insertion sort algorithm. Ascending order
 * @tparam T Type of node
 * @return void
 * @time complexity O(n^2)
 * @space complexity O(1)
 */
template <class T>
void SinglyCircularLinkedList<T>::insertion_sort_ascending()
{
    // Sort SinglyCircularLinkedList in ascending order
    auto current = m_head;
    auto next = std::shared_ptr<Node<T>>(nullptr);
    auto key = T();

    for (size_t i = 1; i < m_size; i++)
    {
        current = m_head;
        next = std::shared_ptr<Node<T>>(nullptr);
        key = current->get_data();

        for (size_t j = 0; j < i; j++)
        {
            next = current->get_next();

            if (key > next->get_data())
            {
                current->set_data(next->get_data());
                next->set_data(key);
            }

            current = current->get_next();
            key = current->get_data();
        }
    }
}

/**
 * @brief
 * Insertion sort algorithm. Descending order
 * @tparam T Type of node
 * @return void
 * @time complexity O(n^2)
 * @space complexity O(1)
 */
template <class T>
void SinglyCircularLinkedList<T>::insertion_sort_descending()
{
    auto current = m_head;
    auto next = std::shared_ptr<Node<T>>(nullptr);
    auto key = T();

    for (size_t i = 1; i < m_size; i++)
    {
        current = m_head;
        next = std::shared_ptr<Node<T>>(nullptr);
        key = current->get_data();

        for (size_t j = 0; j < i; j++)
        {
            next = current->get_next();

            if (key > next->get_data())
            {
                current->set_data(next->get_data());
                next->set_data(key);
            }

            current = current->get_next();
        }
    }
}