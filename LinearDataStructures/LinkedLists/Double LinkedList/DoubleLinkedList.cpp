/**
 * @file DoubleLinkedList.cpp
 * @author Carlos Salguero
 * @brief Implementation of the DoubleLinkedList.h file
 * @version 0.1
 * @date 2022-12-18
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "DoubleLinkedList.h"

// Constructor
/**
 * @brief
 * Construct a new DoubleLinkedList< T>:: DoubleLinkedList object
 * @tparam T Type of node
 * @param data Data to be stored in the node
 */
template <class T>
DoubleLinkedList<T>::DoubleLinkedList(const T &data)
{
    head = std::make_shared<Node<T>>(data);
    tail = head;
    size = 1;
}

/**
 * @brief
 * Construct a new Double Linked List< T>:: Double Linked List object
 * @tparam T Type of node
 * @param data Data to be stored in the node
 * @param next Pointer to the next node
 * @param prev Pointer to the previous node
 */
template <class T>
DoubleLinkedList<T>::DoubleLinkedList(const T &data,
                                      std::shared_ptr<Node<T>> next, std::shared_ptr<Node<T>> prev)
{
    head = std::make_shared<Node<T>>(data, next, prev);
    tail = head;
    size = 1;
}

// Getters
/**
 * @brief
 * Get the size of the list
 * @tparam T Type of node
 * @return size_t Size of the list
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
size_t DoubleLinkedList<T>::get_size() const
{
    return size;
}

/**
 * @brief
 * Get the head of the list
 * @tparam T Type of node
 * @throw std::runtime_error if the list is empty
 * @return std::shared_ptr< Node< T>> Pointer to the head of the list
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
std::shared_ptr<Node<T>> DoubleLinkedList<T>::get_head() const
{
    if (is_empty())
        throw std::runtime_error("List is empty");

    return head;
}

/**
 * @brief
 * Get the tail of the list
 * @tparam T Type of node
 * @throw std::runtime_error if the list is empty
 * @return std::shared_ptr< Node< T>> Pointer to the tail of the list
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
std::shared_ptr<Node<T>> DoubleLinkedList<T>::get_tail() const
{
    if (is_empty())
        throw std::runtime_error("List is empty");

    return tail;
}

/**
 * @brief
 * Gets the data from a previous node
 * @tparam T Type of node
 * @param node Node to get the data from
 * @throw std::runtime_error if the node is the head
 * @return T Data from the node
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
T DoubleLinkedList<T>::get_before(std::shared_ptr<Node<T>> node) const
{
    if (node == head)
        throw std::runtime_error("Node is the head");

    return node->get_prev()->get_data();
}

/**
 * @brief
 * Gets the data from a next node
 * @tparam T Type of node
 * @param node Node to get the data from
 * @throw std::runtime_error if the node is the tail
 * @return T Data from the node
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
T DoubleLinkedList<T>::get_after(std::shared_ptr<Node<T>> node) const
{
    if (node == tail)
        throw std::runtime_error("Node is the tail");

    return node->get_next()->get_data();
}

// Operator overloads
/**
 * @brief
 * Overload the << operator to print the list.
 * @tparam ostream_t Type of node
 * @param os Output stream
 * @param list List to be printed
 * @return std::ostream_t& Output stream
 * @time complexity O(n)
 * @space complexity O(1)
 */
template <class ostream_t>
std::ostream &operator<<(std::ostream &os,
                         const DoubleLinkedList<ostream_t> &list)
{
    std::shared_ptr<Node<ostream_t>> current = list.get_head();

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
bool DoubleLinkedList<T>::is_empty() const
{
    return (head == nullptr);
}

/**
 * @brief
 * Checks if an item is in the list
 * @tparam T Type of node
 * @param data Data to be searched
 * @return true If the data is in the list
 * @return false If the data is not in the list
 * @time complexity O(n)
 * @space complexity O(1)
 */
template <class T>
bool DoubleLinkedList<T>::contains(const T &data) const
{
    std::shared_ptr<Node<T>> current = head;

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
 * @time complexity O(n)
 * @space complexity O(1)
 */
template <class T>
void DoubleLinkedList<T>::clear()
{
    while (!is_empty())
        pop_front();
}

/**
 * @brief
 * Adds a node to the front of the list
 * @tparam T Type of node
 * @param data Data to be stored in the node
 * @return void
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void DoubleLinkedList<T>::push_front(const T &data)
{
    if (is_empty())
    {
        head = std::make_shared<Node<T>>(data);
        tail = head;
    }

    else
    {
        std::shared_ptr<Node<T>> new_node = std::make_shared<Node<T>>(data, head, nullptr);
        head->set_prev(new_node);
        head = new_node;
    }

    size++;
}

/**
 * @brief
 * Adds a node to the end of the list
 * @tparam T Type of node
 * @param data Data to be stored in the node
 * @return void
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void DoubleLinkedList<T>::push_back(const T &data)
{
    if (is_empty())
    {
        head = std::make_shared<Node<T>>(data);
        tail = head;
    }

    else
    {
        std::shared_ptr<Node<T>> new_node = std::make_shared<Node<T>>(data, nullptr, tail);
        tail->set_next(new_node);
        tail = new_node;
    }

    size++;
}

/**
 * @brief
 * Removes the first node in the list
 * @tparam T Type of node
 * @throw std::runtime_error if the list is empty
 * @return void
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void DoubleLinkedList<T>::pop_front()
{
    if (is_empty())
        throw std::runtime_error("List is empty");

    if (head == tail)
    {
        head = nullptr;
        tail = nullptr;
    }

    else
    {
        head = head->get_next();
        head->set_prev(nullptr);
    }

    size--;
}

/**
 * @brief
 * Removes the last node in the list
 * @tparam T Type of node
 * @throw std::runtime_error if the list is empty
 * @return void
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void DoubleLinkedList<T>::pop_back()
{
    if (is_empty())
        throw std::runtime_error("List is empty");

    if (head == tail)
    {
        head = nullptr;
        tail = nullptr;
    }

    else
    {
        tail = tail->get_prev();
        tail->set_next(nullptr);
    }

    size--;
}

/**
 * @brief
 * Removes a node from the list
 * @tparam T Type of node
 * @param index Index of the node to be removed
 * @throw std::runtime_error if the list is empty
 * @return void
 * @time complexity O(n)
 * @space complexity O(1)
 */
template <class T>
void DoubleLinkedList<T>::remove_at(const T &index)
{
    if (is_empty())
        throw std::runtime_error("List is empty");

    if (index == 0)
        pop_front();

    else if (index == size - 1)
        pop_back();

    else
    {
        std::shared_ptr<Node<T>> current = head;

        for (int i = 0; i < index; i++)
            current = current->get_next();

        current->get_prev()->set_next(current->get_next());
        current->get_next()->set_prev(current->get_prev());
        size--;
    }
}

/**
 * @brief
 * Inserts a node at a given index
 * @tparam T Type of node
 * @param index Index of the node to be inserted
 * @param data Data to be stored in the node
 * @throw std::runtime_error if the list is empty
 * @return void
 * @time complexity O(n)
 * @space complexity O(1)
 */
template <class T>
void DoubleLinkedList<T>::insert_at(const T &index, const T &data)
{
    if (is_empty())
        throw std::runtime_error("List is empty");

    if (index == 0)
        push_front(data);

    else if (index == size - 1)
        push_back(data);

    else
    {
        std::shared_ptr<Node<T>> current = head;

        for (int i = 0; i < index; i++)
            current = current->get_next();

        std::shared_ptr<Node<T>> new_node = std::make_shared<Node<T>>(data, current, current->get_prev());
        current->get_prev()->set_next(new_node);
        current->set_prev(new_node);
        size++;
    }
}

/**
 * @brief
 * Replaces the data of a node at a given index
 * @tparam T Type of node
 * @param index Index of the node to be replaced
 * @param data Data to be stored in the node
 * @throw std::runtime_error if the list is empty
 * @return void
 * @time complexity O(n)
 * @space complexity O(1)
 */
template <class T>
void DoubleLinkedList<T>::replace_at(const T &index, const T &data)
{
    if (is_empty())
        throw std::runtime_error("List is empty");

    std::shared_ptr<Node<T>> current = head;

    for (int i = 0; i < index; i++)
        current = current->get_next();

    current->set_data(data);
}

/**
 * @brief
 * Reverses the list.
 * @tparam T Type of node
 * @throw std::runtime_error if the list is empty
 * @return void
 * @time complexity O(n)
 * @space complexity O(1)
 */
template <class T>
void DoubleLinkedList<T>::reverse()
{
    if (is_empty())
        throw std::runtime_error("List is empty");

    std::shared_ptr<Node<T>> current = head;
    std::shared_ptr<Node<T>> temp = nullptr;

    while (current != nullptr)
    {
        temp = current->get_next();
        current->set_next(current->get_prev());
        current->set_prev(temp);
        current = temp;
    }

    temp = head;
    head = tail;
    tail = temp;
}

/**
 * @brief
 * Prints the list
 * @tparam T Type of node
 * @throw std::runtime_error if the list is empty
 * @return std::string String representation of the list
 * @time complexity O(n)
 * @space complexity O(1)
 */
template <class T>
std::string DoubleLinkedList<T>::to_string() const
{
    if (is_empty())
        throw std::runtime_error("List is empty");

    std::string result = "";
    std::shared_ptr<Node<T>> current = head;

    while (current != nullptr)
    {
        result += std::to_string(current->get_data()) + " ";
        current = current->get_next();
    }

    return result;
}

// Sorting algorithms
/**
 * @brief
 * Bubble sort algorithm. This algorithm is not efficient for large lists.
 * A sorting algorithm that repeatedly steps through the list, compares
 * adjacent elements and swaps them if they are in the wrong order.
 * The pass through the list is repeated until the list is sorted.
 * @tparam T Type of node
 * @param order Optional parameter to specify the order of the sorting.
 *            If true, the list will be sorted in ascending order.
 *             (default behaviour)
 *            If false, the list will be sorted in descending order.
 * @throw std::runtime_error if the list is empty
 * @return void
 * @time complexity O(n^2)
 * @space complexity O(1)
 */
template <class T>
void DoubleLinkedList<T>::bubble_sort(const std::optional<bool> &order)
{
    if (is_empty())
        throw std::runtime_error("List is empty");

    if (order.value_or(true))
        bubble_sort_ascending();

    else
        bubble_sort_descending();
}

/**
 * @brief
 * Selection sort algorithm. This algorithm is not efficient for large lists.
 * The algorithm divides the input list into two parts: the sublist of items
 * already sorted, which is built up from left to right at the front (left)
 * of the list, and the sublist of items remaining to be sorted that occupy
 * the rest of the list. Initially, the sorted sublist is empty and the
 * unsorted sublist is the entire input list. The algorithm proceeds by
 * finding the smallest (or largest, depending on sorting order) element in
 * the unsorted sublist, exchanging (swapping) it with the leftmost unsorted
 * element (putting it in sorted order), and moving the sublist boundaries
 * one element to the right.
 * @tparam T Type of node
 * @param order Optional parameter to specify the order of the sorting.
 *            If true, the list will be sorted in ascending order.
 *             (default behaviour)
 *            If false, the list will be sorted in descending order.
 * @throw std::runtime_error if the list is empty
 * @return void
 * @time complexity O(n^2)
 * @space complexity O(1)
 */
template <class T>
void DoubleLinkedList<T>::selection_sort(const std::optional<bool> &order)
{
    if (is_empty())
        throw std::runtime_error("List is empty");

    if (order.value_or(true))
        selection_sort_ascending();

    else
        selection_sort_descending();
}

/**
 * @brief
 * Insertion sort algorithm. This algorithm is not efficient for large lists.
 * The algorithm iterates, consuming one input element each repetition, and
 * growing a sorted output list. At each iteration, insertion sort removes
 * one element from the input data, finds the location it belongs within
 * the sorted list, and inserts it there. It repeats until no input elements
 * remain.
 * @tparam T Type of node
 * @param order Optional parameter to specify the order of the sorting.
 *            If true, the list will be sorted in ascending order.
 *             (default behaviour)
 *            If false, the list will be sorted in descending order.
 * @throw std::runtime_error if the list is empty
 * @return void
 * @time complexity O(n^2)
 * @space complexity O(1)
 */
template <class T>
void DoubleLinkedList<T>::insertion_sort(const std::optional<bool> &order)
{
    if (is_empty())
        throw std::runtime_error("List is empty");

    if (order.value_or(true))
        insertion_sort_ascending();

    else
        insertion_sort_descending();
}

/**
 * @brief
 * Quick sort algorithm. This algorithm is not efficient for large lists.
 * The algorithm picks an element as pivot and partitions the given array
 * around the picked pivot. There are many different versions of quickSort
 * that pick pivot in different ways.
 * @tparam T Type of node
 * @param order Optional parameter to specify the order of the sorting.
 *           If true, the list will be sorted in ascending order.
 *           (default behaviour)
 *          If false, the list will be sorted in descending order.
 * @throw std::runtime_error if the list is empty
 * @return void
 * @time complexity O(n^2)
 * @space complexity O(1)
 */
template <class T>
void DoubleLinkedList<T>::quick_sort(const std::optional<bool> &order)
{
    if (is_empty())
        throw std::runtime_error("List is empty");

    if (order.value_or(true))
        quick_sort_ascending();

    else
        quick_sort_descending();
}

/**
 * @brief
 * Merge sort algorithm. This algorithm is not efficient for large lists.
 * The algorithm divides the input array into two halves, calls itself for
 * the two halves, and then merges the two sorted halves. The merge() function
 * is used for merging two halves. The merge(arr, l, m, r) is a key process
 * that assumes that arr[l..m] and arr[m+1..r] are sorted and merges the
 * two sorted sub-arrays into one.
 * @tparam T Type of node
 * @param order Optional parameter to specify the order of the sorting.
 *           If true, the list will be sorted in ascending order.
 *           (default behaviour)
 *          If false, the list will be sorted in descending order.
 * @throw std::runtime_error if the list is empty
 * @return void
 * @time complexity O(n^2)
 * @space complexity O(1)
 */
template <class T>
void DoubleLinkedList<T>::merge_sort(const std::optional<bool> &order)
{
    if (is_empty())
        throw std::runtime_error("List is empty");

    if (order.value_or(true))
        merge_sort_ascending();

    else
        merge_sort_descending();
}

// Private Sorting algorithms
/**
 * @brief
 * Bubble sort. Ascending order.
 * @tparam T Type of node
 * @return void
 * @time complexity O(n^2)
 * @space complexity O(1)
 */
template <class T>
void DoubleLinkedList<T>::bubble_sort_ascending()
{
    std::shared_ptr<Node<T>> current = head;
    std::shared_ptr<Node<T>> next = nullptr;

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
 * Bubble sort. Descending order.
 * @tparam T Type of node
 * @return void
 * @time complexity O(n^2)
 * @space complexity O(1)
 */
template <class T>
void DoubleLinkedList<T>::bubble_sort_descending()
{
    std::shared_ptr<Node<T>> current = head;
    std::shared_ptr<Node<T>> next = nullptr;

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
 * Selection sort. Ascending order.
 * @tparam T Type of node
 * @return void
 * @time complexity O(n^2)
 * @space complexity O(1)
 */
template <class T>
void DoubleLinkedList<T>::selection_sort_ascending()
{
    std::shared_ptr<Node<T>> current = head;
    std::shared_ptr<Node<T>> next = nullptr;
    std::shared_ptr<Node<T>> min = nullptr;

    while (current != nullptr)
    {
        next = current->get_next();
        min = current;

        while (next != nullptr)
        {
            if (min->get_data() > next->get_data())
                min = next;

            next = next->get_next();
        }

        auto temp = current->get_data();
        current->set_data(min->get_data());
        min->set_data(temp);

        current = current->get_next();
    }
}

/**
 * @brief
 * Selection sort. Descending order.
 * @tparam T Type of node
 * @return void
 * @time complexity O(n^2)
 * @space complexity O(1)
 */
template <class T>
void DoubleLinkedList<T>::selection_sort_descending()
{
    std::shared_ptr<Node<T>> current = head;
    std::shared_ptr<Node<T>> next = nullptr;
    std::shared_ptr<Node<T>> max = nullptr;

    while (current != nullptr)
    {
        next = current->get_next();
        max = current;

        while (next != nullptr)
        {
            if (max->get_data() < next->get_data())
                max = next;

            next = next->get_next();
        }

        auto temp = current->get_data();
        current->set_data(max->get_data());
        max->set_data(temp);

        current = current->get_next();
    }
}

/**
 * @brief
 * Insertion sort. Ascending order.
 * @tparam T Type of node
 * @return void
 * @time complexity O(n^2)
 * @space complexity O(1)
 */
template <class T>
void DoubleLinkedList<T>::insertion_sort_ascending()
{
    std::shared_ptr<Node<T>> current = head;
    std::shared_ptr<Node<T>> next = nullptr;
    std::shared_ptr<Node<T>> temp = nullptr;

    while (current != nullptr)
    {
        next = current->get_next();

        while (next != nullptr)
        {
            if (current->get_data() > next->get_data())
            {
                temp = next->get_next();

                next->set_next(current);
                next->set_prev(current->get_prev());

                current->set_next(temp);
                current->set_prev(next);

                // For next node
                if (next->get_prev() != nullptr)
                    next->get_prev()->set_next(next);

                else
                    head = next;

                // For temp node
                if (temp != nullptr)
                    temp->set_prev(current);

                else
                    tail = current;

                next = temp;
            }

            else
                next = next->get_next();
        }

        current = current->get_next();
    }
}

/**
 * @brief
 * Insertion sort. Descending order.
 * @tparam T Type of node
 * @return void
 * @time complexity O(n^2)
 * @space complexity O(1)
 */
template <class T>
void DoubleLinkedList<T>::insertion_sort_descending()
{
    std::shared_ptr<Node<T>> current = head;
    std::shared_ptr<Node<T>> next = nullptr;
    std::shared_ptr<Node<T>> temp = nullptr;

    while (current != nullptr)
    {
        next = current->get_next();

        while (next != nullptr)
        {
            if (current->get_data() < next->get_data())
            {
                temp = next->get_next();

                next->set_next(current);
                next->set_prev(current->get_prev());

                current->set_next(temp);
                current->set_prev(next);

                // For next node
                if (next->get_prev() != nullptr)
                    next->get_prev()->set_next(next);

                else
                    head = next;

                // For temp node
                if (temp != nullptr)
                    temp->set_prev(current);

                else
                    tail = current;

                next = temp;
            }

            else
                next = next->get_next();
        }

        current = current->get_next();
    }
}

/**
 * @brief
 * Quick sort. Ascending order.
 * @tparam T Type of node
 * @return void
 * @time complexity O(n^2)
 * @space complexity O(1)
 */
template <class T>
void DoubleLinkedList<T>::quick_sort_ascending()
{
    if (head == nullptr)
        return;

    std::shared_ptr<Node<T>> current = head;
    std::shared_ptr<Node<T>> next = nullptr;
    std::shared_ptr<Node<T>> temp = nullptr;

    while (current != nullptr)
    {
        next = current->get_next();

        while (next != nullptr)
        {
            if (current->get_data() > next->get_data())
            {
                temp = next->get_next();

                next->set_next(current);
                next->set_prev(current->get_prev());

                current->set_next(temp);
                current->set_prev(next);

                // For next node
                if (next->get_prev() != nullptr)
                    next->get_prev()->set_next(next);

                else
                    head = next;

                // For temp node
                if (temp != nullptr)
                    temp->set_prev(current);

                else
                    tail = current;

                next = temp;
            }

            else
                next = next->get_next();
        }

        current = current->get_next();
    }
}

/**
 * @brief
 * Quick sort. Descending order.
 * @tparam T Type of node
 * @return void
 * @time complexity O(n^2)
 * @space complexity O(1)
 * @todo Fix quick sort descending
 */
template <class T>
void DoubleLinkedList<T>::quick_sort_descending()
{
    if (head == nullptr)
        return;

    auto current = head;
    std::shared_ptr<Node<T>> next = nullptr;
    std::shared_ptr<Node<T>> temp = nullptr;

    while (current != nullptr)
    {
        next = current->get_next();

        while (next != nullptr)
        {
            if (current->get_data() < next->get_data())
            {
                temp = next->get_next();

                next->set_next(current);
                next->set_prev(current->get_prev());

                current->set_next(temp);
                current->set_prev(next);

                // For next node
                if (next->get_prev() != nullptr)
                    next->get_prev()->set_next(next);

                else
                    head = next;

                // For temp node
                if (temp != nullptr)
                    temp->set_prev(current);

                else
                    tail = current;

                next = temp;
            }

            else
                next = next->get_next();
        }

        current = current->get_next();
    }
}

/**
 * @brief
 * Merge sort. Ascending order.
 * @tparam T Type of node
 * @return void
 * @time complexity O(n^2)
 * @space complexity O(1)
 */
template <class T>
void DoubleLinkedList<T>::merge_sort_ascending()
{
    if (head == nullptr)
        return;

    std::shared_ptr<Node<T>> current = head;
    std::shared_ptr<Node<T>> next = nullptr;
    std::shared_ptr<Node<T>> temp = nullptr;

    while (current != nullptr)
    {
        next = current->get_next();

        while (next != nullptr)
        {
            if (current->get_data() > next->get_data())
            {
                temp = next->get_next();

                next->set_next(current);
                next->set_prev(current->get_prev());

                current->set_next(temp);
                current->set_prev(next);

                // For next node
                if (next->get_prev() != nullptr)
                    next->get_prev()->set_next(next);

                else
                    head = next;

                // For temp node
                if (temp != nullptr)
                    temp->set_prev(current);

                else
                    tail = current;

                next = temp;
            }

            else
                next = next->get_next();
        }

        current = current->get_next();
    }
}

/**
 * @brief
 * Merge sort. Descending order.
 * @tparam T Type of node
 * @return void
 * @time complexity O(n^2)
 * @space complexity O(1)
 */
template <class T>
void DoubleLinkedList<T>::merge_sort_descending()
{
    if (head == nullptr)
        return;

    std::shared_ptr<Node<T>> current = head;
    std::shared_ptr<Node<T>> next = nullptr;
    std::shared_ptr<Node<T>> temp = nullptr;

    while (current != nullptr)
    {
        next = current->get_next();

        while (next != nullptr)
        {
            if (current->get_data() < next->get_data())
            {
                temp = next->get_next();

                next->set_next(current);
                next->set_prev(current->get_prev());

                current->set_next(temp);
                current->set_prev(next);

                // For next node
                if (next->get_prev() != nullptr)
                    next->get_prev()->set_next(next);

                else
                    head = next;

                // For temp node
                if (temp != nullptr)
                    temp->set_prev(current);

                else
                    tail = current;

                next = temp;
            }

            else
                next = next->get_next();
        }

        current = current->get_next();
    }
}