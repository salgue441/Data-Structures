/**
 * @file SinglyLinkedList.cpp
 * @author Carlos Salguero
 * @brief Implementation of the SinglyLinkedList class
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
template <class T>
SinglyLinkedList<T>::SinglyLinkedList(const T &data)
    : head{std::make_shared<Node<T>>(data)}, size{1}
{
}

/**
 * @brief
 * Construct a new SinglyLinkedList< T>:: SinglyLinkedList object
 * @tparam T Type of node
 * @param new_head Pointer to the head of the list
 */
template <class T>
SinglyLinkedList<T>::SinglyLinkedList(const std::shared_ptr<Node<T>> &new_head)
    : head{new_head}, size{1}
{
}

/**
 * @brief
 * Construct a new SinglyLinkedList< T>:: SinglyLinkedList object
 * @tparam T Type of node
 * @param data Data to be stored in the node
 * @param next Pointer to the next node
 */
template <class T>
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
template <class T>
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
template <class T>
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
template <class T>
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
template <class T>
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
template <class T>
T SinglyLinkedList<T>::get_at_index(const size_t &index) const
{
    if (index >= size)
        throw std::out_of_range("Index out of range");

    auto current = head;

    for (size_t i = 0; i < index; i++)
        current = current->get_next();

    return current->get_data();
}

// Operator overloads
/**
 * @brief
 * Overload the << operator
 * @tparam T Type of node
 * @param os Output stream
 * @param list List to be printed
 * @return std::ostream& Output stream
 * @time complexity O(n)
 * @space complexity O(1)
 */
template <class ostream_t>
std::ostream &operator<<(std::ostream &os,
                         const SinglyLinkedList<ostream_t> &list)
{
    auto current = list.get_head();

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
 * Checks if the list is empty
 * @tparam T Type of node
 * @return true If the list is empty
 * @return false If the list is not empty
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
bool SinglyLinkedList<T>::is_empty() const
{
    return (head == nullptr);
}

/**
 * @brief
 * Checks if the list contains the given data
 * @tparam T Type of node
 * @param data Data to be searched
 * @return true If the list contains the given data
 * @return false If the list does not contain the given data
 * @time complexity O(n)
 * @space complexity O(1)
 */
template <class T>
bool SinglyLinkedList<T>::contains(const T &data) const
{
    auto current = head;

    while (current != nullptr)
    {
        if (current->get_data() == data)
            return true;

        current = current->get_next();
    }

    return false;
}

/**
 * @brief
 * Clears the list
 * @tparam T Type of node
 * @return void
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void SinglyLinkedList<T>::clear()
{
    head = nullptr;
    size = 0;
}

/**
 * @brief
 * Add a new node to the front of the list
 * @tparam T Type of node
 * @param data Data to be stored in the new node
 * @return void
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void SinglyLinkedList<T>::push_front(const T &data)
{
    auto new_node = std::make_shared<Node<T>>(data, head);

    head = new_node;
    size++;
}

/**
 * @brief
 * Add a new node to the back of the list
 * @tparam T Type of node
 * @param data Data to be stored in the new node
 * @return void
 * @time complexity O(n)
 * @space complexity O(1)
 */
template <class T>
void SinglyLinkedList<T>::push_back(const T &data)
{
    auto new_node = std::make_shared<Node<T>>(data);

    if (head == nullptr)
    {
        head = new_node;
        size++;
        return;
    }

    auto current = head;

    while (current->get_next() != nullptr)
        current = current->get_next();

    current->set_next(new_node);
    size++;
}

/**
 * @brief
 * Add a new node to the given index
 * @tparam T Type of node
 * @param data Data to be stored in the new node
 * @param index Index where the new node will be added
 * @return void
 * @throw std::out_of_range If the index is out of range
 * @time complexity O(n)
 * @space complexity O(1)
 */
template <class T>
void SinglyLinkedList<T>::push_at_index(const T &data, const size_t &index)
{
    if (index > size)
        throw std::out_of_range("Index out of range");

    if (index == 0)
    {
        push_front(data);
        return;
    }

    auto current = head;

    for (size_t i = 0; i < index - 1; i++)
        current = current->get_next();

    auto new_node = std::make_shared<Node<T>>(data, current->get_next());

    current->set_next(new_node);
    size++;
}

/**
 * @brief
 * Remove the first node of the list
 * @tparam T Type of node
 * @throw std::out_of_range If the list is empty
 * @return void
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void SinglyLinkedList<T>::pop_front()
{
    if (head == nullptr)
        throw std::out_of_range("List is empty");

    head = head->get_next();
    size--;
}

/**
 * @brief
 * Remove the last node of the list
 * @tparam T Type of node
 * @throw std::out_of_range If the list is empty
 * @return void
 * @time complexity O(n)
 * @space complexity O(1)
 */
template <class T>
void SinglyLinkedList<T>::pop_back()
{
    if (head == nullptr)
        throw std::out_of_range("List is empty");

    if (head->get_next() == nullptr)
    {
        head = nullptr;
        size--;
        return;
    }

    auto current = head;

    while (current->get_next()->get_next() != nullptr)
        current = current->get_next();

    current->set_next(nullptr);
    size--;
}

/**
 * @brief
 * Remove the node at the given index
 * @tparam T Type of node
 * @param index Index of the node to be removed
 * @throw std::out_of_range If the index is out of range
 * @return void
 * @time complexity O(n)
 * @space complexity O(1)
 */
template <class T>
void SinglyLinkedList<T>::pop_at_index(const T &index)
{
    if (index >= size)
        throw std::out_of_range("Index out of range");

    if (index == 0)
    {
        pop_front();
        return;
    }

    auto current = head;

    for (size_t i = 0; i < index - 1; i++)
        current = current->get_next();

    current->set_next(current->get_next()->get_next());
    size--;
}

/**
 * @brief
 * Remove the first node that contains the given data
 * @tparam T Type of node
 * @param data Data to be removed
 * @throw std::out_of_range If the list does not contain the given data
 * @return void
 * @time complexity O(n)
 * @space complexity O(1)
 */
template <class T>
void SinglyLinkedList<T>::remove_at(const T &data)
{
    if (head == nullptr)
        throw std::out_of_range("List is empty");

    if (head->get_data() == data)
    {
        pop_front();
        return;
    }

    auto current = head;

    while (current->get_next() != nullptr)
    {
        if (current->get_next()->get_data() == data)
        {
            current->set_next(current->get_next()->get_next());
            size--;
            return;
        }

        current = current->get_next();
    }

    throw std::out_of_range("Data not found");
}

/**
 * @brief
 * Reverses the list
 * @tparam T Type of node
 * @return void
 * @time complexity O(n)
 * @space complexity O(1)
 */
template <class T>
void SinglyLinkedList<T>::reverse()
{
    if (head == nullptr)
        return;

    auto current = head;
    auto previous = std::shared_ptr<Node<T>>(nullptr);
    auto next = std::shared_ptr<Node<T>>(nullptr);

    while (current != nullptr)
    {
        next = current->get_next();
        current->set_next(previous);
        previous = current;
        current = next;
    }

    head = previous;
}

/**
 * @brief
 * Shows the list as a string
 * @tparam T Type of node
 * @throw std::out_of_range If the list is empty
 * @time complexity O(n)
 * @space complexity O(1)
 * @return std::string List as a string
 */
template <class T>
std::string SinglyLinkedList<T>::to_string() const
{
    if (head == nullptr)
        throw std::out_of_range("List is empty");

    std::stringstream ss;

    auto current = head;

    while (current != nullptr)
    {
        ss << current->get_data() << " ";
        current = current->get_next();
    }

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
void SinglyLinkedList<T>::bubble_sort(const std::optional<bool> &order)
{
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
void SinglyLinkedList<T>::insertion_sort(const std::optional<bool> &order)
{
    if (order.value_or(true))
        insertion_sort_ascending();

    else
        insertion_sort_descending();
}

/**
 * @brief
 * Selection sort algorithm. A sorting algorithm that divides the input list
 * into two parts: the sublist of items already sorted, which is built up
 * from left to right at the front (left) of the list, and the sublist of
 * items remaining to be sorted that occupy the rest of the list. Initially,
 * the sorted sublist is empty and the unsorted sublist is the entire input
 * list. The algorithm proceeds by finding the smallest (or largest, depending
 * on sorting order) element in the unsorted sublist, exchanging (swapping) it
 * with the leftmost unsorted element (putting it in sorted order), and moving
 * the sublist boundaries one element to the right.
 * Allows the user to choose the sorting order
 * @tparam T Type of node
 * @param order Sorting order (true = ascending (default), false = descending)
 * @return void
 * @time complexity O(n^2)
 * @space complexity O(1)
 */
template <class T>
void SinglyLinkedList<T>::selection_sort(const std::optional<bool> &order)
{
    if (order.value_or(true))
        selection_sort_ascending();

    else
        selection_sort_descending();
}

/**
 * @brief
 * Quick sort algorithm. A sorting algorithm that divides the input list
 * into two parts: the sublist of items already sorted, which is built up
 * from left to right at the front (left) of the list, and the sublist of
 * items remaining to be sorted that occupy the rest of the list. Allows the
 * user to choose the sorting order
 * @tparam T Type of node
 * @param order Sorting order (true = ascending (default), false = descending)
 * @return void
 * @time complexity O(n log n)
 * @space complexity O(n)
 */
template <class T>
void SinglyLinkedList<T>::quick_sort(const std::optional<bool> &order)
{
    if (order.value_or(true))
        quick_sort_ascending();

    else
        quick_sort_descending();
}

/**
 * @brief
 * Merge sort algorithm. A sorting algorithm that divides the input list
 * into two parts: the sublist of items already sorted, which is built up
 * from left to right at the front (left) of the list, and the sublist of
 * items remaining to be sorted that occupy the rest of the list. Allows the
 * user to choose the sorting order
 * @tparam T Type of node
 * @param order Sorting order (true = ascending (default), false = descending)
 * @return void
 * @time complexity O(n log n)
 * @space complexity O(n)
 */
template <class T>
void SinglyLinkedList<T>::merge_sort(const std::optional<bool> &order)
{
    if (order.value_or(true))
        merge_sort_ascending();

    else
        merge_sort_descending();
}

// Private sorting algorithms
/**
 * @brief
 * Bubble sort algorithm. Ascending order.
 * @tparam T Type of node
 * @return void
 * @time complexity O(n^2)
 * @space complexity O(1)
 */
template <class T>
void SinglyLinkedList<T>::bubble_sort_ascending()
{
    if (head == nullptr)
        return;

    auto current = head;
    auto next = std::shared_ptr<Node<T>>(nullptr);

    while (current != nullptr)
    {
        next = current->get_next();

        while (next != nullptr)
        {
            if (current->get_data() > next->get_data())
            {
                auto temp = current->get_data();
                current->set_data(next->get_data());
                next->set_data(temp);
            }

            next = next->get_next();
        }

        current = current->get_next();
    }
}

/**
 * @brief
 * Bubble sort algorithm. Descending order.
 * @tparam T Type of node
 * @return void
 * @time complexity O(n^2)
 * @space complexity O(1)
 */
template <class T>
void SinglyLinkedList<T>::bubble_sort_descending()
{
    if (head == nullptr)
        return;

    auto current = head;
    auto next = std::shared_ptr<Node<T>>(nullptr);

    while (current != nullptr)
    {
        next = current->get_next();

        while (next != nullptr)
        {
            if (current->get_data() < next->get_data())
            {
                auto temp = current->get_data();
                current->set_data(next->get_data());
                next->set_data(temp);
            }

            next = next->get_next();
        }

        current = current->get_next();
    }
}

/**
 * @brief
 * Insertion sort algorithm. Ascending order.
 * @tparam T Type of node
 * @return void
 * @time complexity O(n^2)
 * @space complexity O(1)
 */
template <class T>
void SinglyLinkedList<T>::insertion_sort_ascending()
{
    if (head == nullptr)
        return;

    auto current = head->get_next();

    while (current != nullptr)
    {
        auto next = current->get_next();
        auto temp = head;

        while (temp != current)
        {
            if (temp->get_data() > current->get_data())
            {
                auto temp_data = temp->get_data();
                temp->set_data(current->get_data());
                current->set_data(temp_data);
            }

            temp = temp->get_next();
        }

        current = next;
    }
}

/**
 * @brief
 * Insertion sort algorithm. Descending order.
 * @tparam T Type of node
 * @return void
 * @time complexity O(n^2)
 * @space complexity O(1)
 */
template <class T>
void SinglyLinkedList<T>::insertion_sort_descending()
{
    if (head == nullptr)
        return;

    auto current = head->get_next();

    while (current != nullptr)
    {
        auto next = current->get_next();
        auto temp = head;

        while (temp != current)
        {
            if (temp->get_data() < current->get_data())
            {
                auto temp_data = temp->get_data();
                temp->set_data(current->get_data());
                current->set_data(temp_data);
            }

            temp = temp->get_next();
        }

        current = next;
    }
}

/**
 * @brief
 * Selection sort algorithm. Ascending order.
 * @tparam T Type of node
 * @return void
 * @time complexity O(n^2)
 * @space complexity O(1)
 */
template <class T>
void SinglyLinkedList<T>::selection_sort_ascending()
{
    if (head == nullptr)
        return;

    auto current = head;

    while (current != nullptr)
    {
        auto next = current->get_next();
        auto temp = current;

        while (next != nullptr)
        {
            if (temp->get_data() > next->get_data())
                temp = next;

            next = next->get_next();
        }

        auto temp_data = temp->get_data();
        temp->set_data(current->get_data());
        current->set_data(temp_data);

        current = current->get_next();
    }
}

/**
 * @brief
 * Selection sort algorithm. Descending order.
 * @tparam T Type of node
 * @return void
 * @time complexity O(n^2)
 * @space complexity O(1)
 */
template <class T>
void SinglyLinkedList<T>::selection_sort_descending()
{
    if (head == nullptr)
        return;

    auto current = head;

    while (current != nullptr)
    {
        auto next = current->get_next();
        auto temp = current;

        while (next != nullptr)
        {
            if (temp->get_data() < next->get_data())
                temp = next;

            next = next->get_next();
        }

        auto temp_data = temp->get_data();
        temp->set_data(current->get_data());
        current->set_data(temp_data);

        current = current->get_next();
    }
}

/**
 * @brief
 * Quick sort algorithm. Ascending order.
 * @tparam T Type of node
 * @return void
 * @time complexity O(n log n)
 * @space complexity O(n)
 */
template <class T>
void SinglyLinkedList<T>::quick_sort_ascending()
{
    if (head == nullptr)
        return;

    auto current = head;
    auto next = std::shared_ptr<Node<T>>(nullptr);

    while (current != nullptr)
    {
        next = current->get_next();

        while (next != nullptr)
        {
            if (current->get_data() > next->get_data())
            {
                auto temp = current->get_data();
                current->set_data(next->get_data());
                next->set_data(temp);
            }

            next = next->get_next();
        }

        current = current->get_next();
    }
}

/**
 * @brief
 * Quick sort algorithm. Descending order.
 * @tparam T Type of node
 * @return void
 * @time complexity O(n log n)
 * @space complexity O(n)
 */
template <class T>
void SinglyLinkedList<T>::quick_sort_descending()
{
    if (head == nullptr)
        return;

    auto current = head;
    auto next = std::shared_ptr<Node<T>>(nullptr);

    while (current != nullptr)
    {
        next = current->get_next();

        while (next != nullptr)
        {
            if (current->get_data() < next->get_data())
            {
                auto temp = current->get_data();
                current->set_data(next->get_data());
                next->set_data(temp);
            }

            next = next->get_next();
        }

        current = current->get_next();
    }
}

/**
 * @brief
 * Merge sort algorithm. Ascending order.
 * @tparam T Type of node
 * @return void
 * @time complexity O(n log n)
 * @space complexity O(n)
 */
template <class T>
void SinglyLinkedList<T>::merge_sort_ascending()
{
    if (head == nullptr)
        return;

    auto current = head;
    auto next = std::shared_ptr<Node<T>>(nullptr);

    while (current != nullptr)
    {
        next = current->get_next();

        while (next != nullptr)
        {
            if (current->get_data() > next->get_data())
            {
                auto temp = current->get_data();
                current->set_data(next->get_data());
                next->set_data(temp);
            }

            next = next->get_next();
        }

        current = current->get_next();
    }
}

/**
 * @brief
 * Merge sort algorithm. Descending order.
 * @tparam T Type of node
 * @return void
 * @time complexity O(n log n)
 * @space complexity O(n)
 */
template <class T>
void SinglyLinkedList<T>::merge_sort_descending()
{
    if (head == nullptr)
        return;

    auto current = head;
    auto next = std::shared_ptr<Node<T>>(nullptr);

    while (current != nullptr)
    {
        next = current->get_next();

        while (next != nullptr)
        {
            if (current->get_data() < next->get_data())
            {
                auto temp = current->get_data();
                current->set_data(next->get_data());
                next->set_data(temp);
            }

            next = next->get_next();
        }

        current = current->get_next();
    }
}