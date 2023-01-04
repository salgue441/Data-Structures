/**
 * @file SinglyCircularLinkedList.cpp
 * @author Carlos Salguero
 * @brief Implementation of a Singly Circular Linked List
 * @version 0.1
 * @date 2023-01-04
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "SinglyCircularLinkedList.h"

// Constructors
/**
 * @brief
 * Construct a new Singly Circular Linked List:: Singly Circular Linked List
 * object
 * @tparam T Type of data
 * @param data Data to be stored in the node
 */
template <class T>
SinglyCircularLinkedList<T>::SinglyCircularLinkedList(T data)
{
    this->data = data;
}

/**
 * @brief
 * Construct a new Singly Circular Linked List:: Singly Circular Linked
 * List object
 * @tparam T Type of data
 * @param data Data to be stored in the node
 * @param head Head of the list
 */
template <class T>
SinglyCircularLinkedList<T>::SinglyCircularLinkedList(T data,
                                                      std::shared_ptr<Node<T>> head)
{
    this->data = data;
    this->head = head;
}

// Getters
/**
 * @brief Get the head of the list
 * @tparam T Type of data
 * @return std::shared_ptr<Node<T>> Head of the list
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
std::shared_ptr<Node<T>> SinglyCircularLinkedList<T>::get_head() const
{
    return this->head;
}

/**
 * @brief Get the size of the list
 * @tparam T Type of data
 * @return unsigned int Size of the list
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
unsigned int SinglyCircularLinkedList<T>::get_size() const
{
    return this->size;
}

/**
 * @brief Get the data of the node
 * @tparam T Type of data
 * @return T Data of the node
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
T SinglyCircularLinkedList<T>::get_data() const
{
    return this->data;
}

// Operator overload
/**
 * @brief
 * Overload the << operator to print the list
 * @tparam ostream_t Type of data
 * @param os Output stream
 * @param list List to be printed
 * @return std::ostream& Output stream
 * @time complexity O(n)
 * @space complexity O(1)
 */
template <typename ostream_t>
std::ostream &operator<<(std::ostream &os,
                         const SinglyCircularLinkedList<ostream_t> &list)
{
    os << list.to_string();
    return os;
}

// Private methods
/**
 * @brief
 * Swaps two nodes in the list
 * @tparam T Type of data
 * @param node1 First node
 * @param node2 Second node
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void SinglyCircularLinkedList<T>::swap_nodes(
    std::shared_ptr<Node<T>> node1, std::shared_ptr<Node<T>> node2)
{
    T temp = node1->get_data();
    node1->set_data(node2->get_data());
    node2->set_data(temp);
}

// Methods
/**
 * @brief
 * Checks if the list is empty
 * @tparam T Type of data
 * @return true If the list is empty
 * @return false If the list is not empty
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
bool SinglyCircularLinkedList<T>::is_empty() const
{
    return this->head == nullptr;
}

/**
 * @brief
 * Search for a node in the list
 * @tparam T Type of data
 * @param data Data to be searched
 * @return std::optional<std::shared_ptr<Node<T>>> Node with the data
 * @return std::nullopt If the data is not found
 * @throw std::runtime_error If the list is empty
 * @time complexity O(n)
 * @space complexity O(1)
 */
template <class T>
std::optional<std::shared_ptr<Node<T>>>
SinglyCircularLinkedList<T>::search(T data) const
{
    if (this->is_empty())
        throw std::runtime_error("The list is empty");

    std::shared_ptr<Node<T>> current_node = this->head;

    do
    {
        if (current_node->get_data() == data)
            return current_node;

        current_node = current_node->get_next();
    } while (current_node != this->head);

    return std::nullopt;
}

/**
 * @brief
 * Push a node to the front of the list
 * @tparam T Type of data
 * @param data Data to be stored in the node
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void SinglyCircularLinkedList<T>::push_front(T data)
{
    std::shared_ptr<Node<T>> new_node = std::make_shared<Node<T>>(data);

    if (this->is_empty())
    {
        this->head = new_node;
        this->head->set_next(this->head);
    }

    new_node->set_next(this->head);

    std::shared_ptr<Node<T>> current_node = this->head;

    while (current_node->get_next() != this->head)
        current_node = current_node->get_next();

    current_node->set_next(new_node);
    this->head = new_node;

    this->size++;
}

/**
 * @brief
 * Push a node to the back of the list
 * @tparam T Type of data
 * @param data Data to be stored in the node
 * @time complexity O(n)
 * @space complexity O(1)
 */
template <class T>
void SinglyCircularLinkedList<T>::push_back(T data)
{
    std::shared_ptr<Node<T>> new_node = std::make_shared<Node<T>>(data);

    if (this->is_empty())
    {
        this->head = new_node;
        this->head->set_next(this->head);
    }

    std::shared_ptr<Node<T>> current_node = this->head;

    while (current_node->get_next() != this->head)
        current_node = current_node->get_next();

    current_node->set_next(new_node);
    new_node->set_next(this->head);

    this->size++;
}

/**
 * @brief
 * Insert a new node at a given location
 * @tparam T Type of data
 * @param data Data to be stored in the node
 * @param location Location to insert the node
 * @throw std::runtime_error If the list is empty
 * @throw std::runtime_error If the location is out of bounds
 * @time complexity O(n)
 * @space complexity O(1)
 */
template <class T>
void SinglyCircularLinkedList<T>::insert(T data, unsigned int location)
{
    if (this->is_empty())
        throw std::runtime_error("The list is empty");

    if (location > this->size)
        throw std::runtime_error("The location is out of bounds");

    if (location == 0)
    {
        this->push_front(data);
        return;
    }

    if (location == this->size)
    {
        this->push_back(data);
        return;
    }

    std::shared_ptr<Node<T>> new_node = std::make_shared<Node<T>>(data);
    std::shared_ptr<Node<T>> current_node = this->head;

    for (unsigned int i = 0; i < location - 1; i++)
        current_node = current_node->get_next();

    new_node->set_next(current_node->get_next());
    current_node->set_next(new_node);

    this->size++;
}

/**
 * @brief
 * Delete a node from the front of the list
 * @tparam T Type of data
 * @throw std::runtime_error If the list is empty
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void SinglyCircularLinkedList<T>::pop_front()
{
    if (this->is_empty())
        throw std::runtime_error("The list is empty");

    std::shared_ptr<Node<T>> current_node = this->head;

    while (current_node->get_next() != this->head)
        current_node = current_node->get_next();

    current_node->set_next(this->head->get_next());
    this->head = this->head->get_next();

    this->size--;
}

/**
 * @brief
 * Delete a node from the back of the list
 * @tparam T Type of data
 * @throw std::runtime_error If the list is empty
 * @time complexity O(n)
 * @space complexity O(1)
 */
template <class T>
void SinglyCircularLinkedList<T>::pop_back()
{
    if (this->is_empty())
        throw std::runtime_error("The list is empty");

    std::shared_ptr<Node<T>> current_node = this->head;

    while (current_node->get_next()->get_next() != this->head)
        current_node = current_node->get_next();

    current_node->set_next(this->head);

    this->size--;
}

/**
 * @brief
 * Delete a node at a given location
 * @tparam T Type of data
 * @param location Location to delete the node
 * @throw std::runtime_error If the list is empty
 * @throw std::runtime_error If the location is out of bounds
 * @time complexity O(n)
 * @space complexity O(1)
 */
template <class T>
void SinglyCircularLinkedList<T>::remove(unsigned int location)
{
    if (this->is_empty())
        throw std::runtime_error("The list is empty");

    if (location > this->size)
        throw std::runtime_error("The location is out of bounds");

    if (location == 0)
    {
        this->pop_front();
        return;
    }

    if (location == this->size)
    {
        this->pop_back();
        return;
    }

    std::shared_ptr<Node<T>> current_node = this->head;

    for (unsigned int i = 0; i < location - 1; i++)
        current_node = current_node->get_next();

    current_node->set_next(current_node->get_next()->get_next());

    this->size--;
}

/**
 * @brief
 * Reverses the list
 * @tparam T Type of data
 * @throw std::runtime_error If the list is empty
 * @time complexity O(n)
 * @space complexity O(1)
 */
template <class T>
void SinglyCircularLinkedList<T>::reverse()
{
    if (this->is_empty())
        throw std::runtime_error("The list is empty");

    if (this->size == 1)
        return;

    std::shared_ptr<Node<T>> previous_node = nullptr;
    std::shared_ptr<Node<T>> current_node = this->head;
    std::shared_ptr<Node<T>> next_node;

    do
    {
        next_node = current_node->get_next();
        current_node->set_next(previous_node);

        previous_node = current_node;
        current_node = next_node;
    } while (current_node != this->head);

    this->head = previous_node;

    std::shared_ptr<Node<T>> last_node = this->head;

    while (last_node->get_next() != nullptr)
        last_node = last_node->get_next();

    last_node->set_next(this->head);
}

/**
 * @brief
 * Prints the list in the console
 * @tparam T Type of data
 * @return std::string String with the list
 * @throw std::runtime_error If the list is empty
 * @time complexity O(n)
 * @space complexity O(1)
 */
template <class T>
std::string SinglyCircularLinkedList<T>::to_string() const
{
    if (this->is_empty())
        return "The list is empty";

    std::stringstream ss;
    std::shared_ptr<Node<T>> current_node = this->head;

    do
    {
        ss << current_node->get_data() << " ";
        current_node = current_node->get_next();
    } while (current_node != this->head);

    return ss.str();
}

// Sorts
/**
 * @brief
 * Bubble sort algorithm. Sorts the list in ascending order.
 * @tparam T Type of data
 * @throw std::runtime_error If the list is empty
 * @time complexity O(n^2)
 * @space complexity O(1)
 */
template <class T>
void SinglyCircularLinkedList<T>::ascending_bubble_sort()
{
    if (this->is_empty())
        throw std::runtime_error("The list is empty");

    if (this->size == 1)
        return;

    std::shared_ptr<Node<T>> current_node = this->head;
    std::shared_ptr<Node<T>> next_node;

    for (size_t i{}; i < this->size - 1; i++)
    {
        current_node = this->head;

        for (size_t j{}; j < this->size - i - 1; j++)
        {
            next_node = current_node->get_next();

            if (current_node->get_data() > next_node->get_data())
                swap_nodes(current_node, next_node);

            current_node = current_node->get_next();
        }
    }
}