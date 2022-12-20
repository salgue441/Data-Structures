/**
 * @file AVL.cpp
 * @author Carlos Salguero
 * @brief Implementation of the AVL class
 * @version 0.1
 * @date 2022-12-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "AVL.h"

// Constructor
/**
 * @brief
 * Construct a new AVL< T>:: AVL object
 * @tparam T Type of the data
 * @param size Size of the AVL tree
 */
template <class T>
AVL<T>::AVL(size_t size) : size(size), root(nullptr) {}

/**
 * @brief
 * Construct a new AVL< T>:: AVL object
 * @tparam T Type of the data
 * @param root Pointer to the root of the AVL tree
 */
template <class T>
AVL<T>::AVL(const std::shared_ptr<Node<T>> &root) : size(0), root(root) {}

/**
 * @brief
 * Construct a new AVL< T>:: AVL object
 * @tparam T Type of the data
 * @param size Size of the AVL tree
 * @param root Pointer to the root of the AVL tree
 */
template <class T>
AVL<T>::AVL(size_t size, const std::shared_ptr<Node<T>> &root)
    : size(size), root(root) {}

// Getters
/**
 * @brief
 * Get the size of the AVL tree
 * @tparam T Type of the data
 * @return size_t Size of the AVL tree
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
size_t AVL<T>::get_size() const
{
    return size;
}

/**
 * @brief
 * Get the pointer to the root of the AVL tree
 * @tparam T Type of the data
 * @return std::shared_ptr<Node> Pointer to the root of the AVL tree
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
std::shared_ptr<Node<T>> AVL<T>::get_root() const
{
    return root;
}

// Operator overloading
/**
 * @brief
 * Overload the operator << for the AVL class
 * @tparam ostream_t Type of the data
 * @param os Output stream
 * @param avl AVL tree to be printed
 * @return std::ostream& Output stream
 * @time complexity O(n)
 * @space complexity O(n)
 */
template <class ostream_t>
std::ostream &operator<<(std::ostream &os, const AVL<ostream_t> &avl)
{
    os << avl.get_root();

    return os;
}

// Helper functions
/**
 * @brief
 * Checks if the AVL tree is balanced
 * @tparam T Type of the data
 * @param node Pointer to the node
 * @return true If the AVL tree is balanced
 * @return false If the AVL tree is not balanced
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
bool AVL<T>::is_balanced(const std::shared_ptr<Node<T>> &node) const
{
    if (node == nullptr)
        return true;

    return (abs(get_height(node->get_left()) -
                get_height(node->get_right())) <= 1);
}

/**
 * @brief
 * Get the height of a node
 * @tparam T Type of the data
 * @param node Pointer to the node
 * @return size_t Height of the node
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
size_t AVL<T>::get_height(const std::shared_ptr<Node<T>> &node) const
{
    if (node == nullptr)
        return 0;

    return node->get_height();
}

/**
 * @brief
 * Get the balance factor of a node
 * @tparam T Type of the data
 * @param node Pointer to the node
 * @return int Balance factor of the node
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
int AVL<T>::get_balance_factor(const std::shared_ptr<Node<T>> &node) const
{
    if (node == nullptr)
        return 0;

    return (get_height(node->get_left()) - get_height(node->get_right()));
}

/**
 * @brief
 * Rotates the AVL tree to the left
 * @tparam T Type of the data
 * @param node Pointer to the node
 * @return std::shared_ptr<Node> Pointer to the new root of the AVL tree
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
std::shared_ptr<Node<T>> AVL<T>::rotate_left(
    const std::shared_ptr<Node<T>> &node)
{
    std::shared_ptr<Node<T>> new_root = node->get_right();
    std::shared_ptr<Node<T>> new_left = new_root->get_left();

    new_root->set_left(node);
    node->set_right(new_left);

    node->set_height(std::max(get_height(node->get_left()),
                              get_height(node->get_right())) +
                     1);
    new_root->set_height(std::max(get_height(new_root->get_left()),
                                  get_height(new_root->get_right())) +
                         1);

    return new_root;
}

/**
 * @brief
 * Rotates the AVL tree to the right
 * @tparam T Type of the data
 * @param node Pointer to the node
 * @return std::shared_ptr<Node> Pointer to the new root of the AVL tree
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
std::shared_ptr<Node<T>> AVL<T>::rotate_right(
    const std::shared_ptr<Node<T>> &node)
{
    std::shared_ptr<Node<T>> new_root = node->get_left();
    std::shared_ptr<Node<T>> new_right = new_root->get_right();

    new_root->set_right(node);
    node->set_left(new_right);

    node->set_height(std::max(get_height(node->get_left()),
                              get_height(node->get_right())) +
                     1);
    new_root->set_height(std::max(get_height(new_root->get_left()),
                                  get_height(new_root->get_right())) +
                         1);

    return new_root;
}

// Methods
/**
 * @brief
 * Checks if the AVL tree is empty
 * @tparam T Type of the data
 * @return true If the AVL tree is empty
 * @return false If the AVL tree is not empty
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
bool AVL<T>::is_empty() const
{
    return (size == 0);
}

/**
 * @brief
 * Checks if the AVL tree contains a node with a specific data
 * @tparam T Type of the data
 * @param data Data to be searched
 * @return true If the AVL tree contains the data
 * @return false If the AVL tree does not contain the data
 * @time complexity O(log n)
 * @space complexity O(log n)
 */
template <class T>
bool AVL<T>::contains(const T &data) const
{
    std::shared_ptr<Node<T>> current = root;

    while (current != nullptr)
    {
        if (current->get_data() == data)
            return true;

        else if (current->get_data() > data)
            current = current->get_left();

        else
            current = current->get_right();
    }

    return false;
}

/**
 * @brief
 * Inserts a new node in the AVL tree
 * @tparam T Type of the data
 * @param data Data to be inserted
 * @time complexity O(log n)
 * @space complexity O(log n)
 */
template <class T>
void AVL<T>::insert(const T &data)
{
    auto new_node = std::make_shared<Node<T>>(data);

    if (root == nullptr)
    {
        root = new_node;
        size++;
        return;
    }

    std::shared_ptr<Node<T>> current = root;
    std::shared_ptr<Node<T>> parent = nullptr;

    while (current != nullptr)
    {
        if (current->get_data() == data)
            return;

        else if (current->get_data() > data)
        {
            parent = current;
            current = current->get_left();
        }

        else
        {
            parent = current;
            current = current->get_right();
        }
    }

    if (parent->get_data() > data)
        parent->set_left(new_node);

    else
        parent->set_right(new_node);

    size++;
}

/**
 * @brief
 * Removes a node from the AVL tree
 * @tparam T Type of the data
 * @param data Data to be removed
 * @time complexity O(log n)
 * @space complexity O(log n)
 */
template <class T>
void AVL<T>::remove(const T &data)
{
    std::shared_ptr<Node<T>> current = root;
    std::shared_ptr<Node<T>> parent = nullptr;

    while (current != nullptr)
    {
        if (current->get_data() == data)
            break;

        else if (current->get_data() > data)
        {
            parent = current;
            current = current->get_left();
        }

        else
        {
            parent = current;
            current = current->get_right();
        }
    }

    if (current == nullptr)
        return;

    if (current->get_left() == nullptr)
    {
        if (parent == nullptr)
            root = current->get_right();

        else if (parent->get_left() == current)
            parent->set_left(current->get_right());

        else
            parent->set_right(current->get_right());
    }

    else if (current->get_right() == nullptr)
    {
        if (parent == nullptr)
            root = current->get_left();

        else if (parent->get_left() == current)
            parent->set_left(current->get_left());

        else
            parent->set_right(current->get_left());
    }

    else
    {
        std::shared_ptr<Node<T>> successor = current->get_right();
        std::shared_ptr<Node<T>> successor_parent = current;

        while (successor->get_left() != nullptr)
        {
            successor_parent = successor;
            successor = successor->get_left();
        }

        if (successor_parent != current)
        {
            successor_parent->set_left(successor->get_right());
            successor->set_right(current->get_right());
        }

        if (parent == nullptr)
            root = successor;

        else if (parent->get_left() == current)
            parent->set_left(successor);

        else
            parent->set_right(successor);

        successor->set_left(current->get_left());
    }
}

/**
 * @brief
 * Clears the AVL tree
 * @tparam T Type of the data
 * @time complexity O(n)
 * @space complexity O(n)
 */
template <class T>
void AVL<T>::clear() const
{
    root = nullptr;
    size = 0;
}

/**
 * @brief
 * Finds a node with a specific data
 * @tparam T Type of the data
 * @param data Data to be searched
 * @return std::optional<std::shared_ptr<Node<T>>>
 *         If the AVL tree contains the data
 * @return std::nullopt
 *          If the AVL tree does not contain the data
 * @time complexity O(log n)
 * @space complexity O(log n)
 */
template <class T>
std::optional<std::shared_ptr<Node<T>>> AVL<T>::find(const T &data) const
{
    std::shared_ptr<Node<T>> current = root;

    while (current != nullptr)
    {
        if (current->get_data() == data)
            return current;

        else if (current->get_data() > data)
            current = current->get_left();

        else
            current = current->get_right();
    }

    return std::nullopt;
}

/**
 * @brief
 * Finds the parent of a node with a specific data
 * @tparam T Type of the data
 * @param data Data to be searched
 * @return std::optional<std::shared_ptr<Node<T>>>
 *        If the AVL tree contains the data
 * @return std::nullopt
 *        If the AVL tree does not contain the data
 * @time complexity O(log n)
 * @space complexity O(log n)
 */
template <class T>
std::optional<std::shared_ptr<Node<T>>> AVL<T>::find_parent(const T &data) const
{
    std::shared_ptr<Node<T>> current = root;
    std::shared_ptr<Node<T>> parent = nullptr;

    while (current != nullptr)
    {
        if (current->get_data() == data)
            return parent;

        else if (current->get_data() > data)
        {
            parent = current;
            current = current->get_left();
        }

        else
        {
            parent = current;
            current = current->get_right();
        }
    }

    return std::nullopt;
}

/**
 * @brief
 * Finds the minimum node in the AVL tree
 * @tparam T Type of the data
 * @return std::optional<std::shared_ptr<Node<T>>>
 *         If the AVL tree is not empty
 * @return std::nullopt
 *          If the AVL tree is empty
 * @time complexity O(log n)
 * @space complexity O(log n)
 */
template <class T>
std::optional<std::shared_ptr<Node<T>>> AVL<T>::find_min(
    const std::shared_ptr<Node<T>> &node) const
{
    if (node == nullptr)
        return std::nullopt;

    std::shared_ptr<Node<T>> current = node;

    while (current->get_left() != nullptr)
        current = current->get_left();

    return current;
}

/**
 * @brief
 * Finds the maximum node in the AVL tree
 * @tparam T Type of the data
 * @return std::optional<std::shared_ptr<Node<T>>>
 *         If the AVL tree is not empty
 * @return std::nullopt
 *          If the AVL tree is empty
 * @time complexity O(log n)
 * @space complexity O(log n)
 */
template <class T>
std::optional<std::shared_ptr<Node<T>>> AVL<T>::find_max(
    const std::shared_ptr<Node<T>> &node) const
{
    if (node == nullptr)
        return std::nullopt;

    std::shared_ptr<Node<T>> current = node;

    while (current->get_right() != nullptr)
        current = current->get_right();

    return current;
}

/**
 * @brief
 * Finds the successor of a node with a specific data
 * @tparam T Type of the data
 * @param data Data to be searched
 * @return std::optional<std::shared_ptr<Node<T>>>
 *         If the AVL tree contains the data
 * @return std::nullopt
 *          If the AVL tree does not contain the data
 * @time complexity O(log n)
 * @space complexity O(log n)
 */
template <class T>
std::optional<std::shared_ptr<Node<T>>> AVL<T>::find_successor(
    const std::shared_ptr<Node<T>> &node) const
{
    if (node == nullptr)
        return std::nullopt;

    if (node->get_right() != nullptr)
        return find_min(node->get_right());

    std::shared_ptr<Node<T>> current = node;
    std::shared_ptr<Node<T>> parent = find_parent(node->get_data()).value();

    while (parent != nullptr && current == parent->get_right())
    {
        current = parent;
        parent = find_parent(parent->get_data()).value();
    }

    return parent;
}

/**
 * @brief
 * Prints the AVL tree in level order
 * @tparam T Type of the data
 * @return std::string String representation of the AVL tree
 * @throw std::runtime_error If the tree is empty
 * @time complexity O(n)
 * @space complexity O(n)
 */
template <class T>
std::string AVL<T>::to_string() const
{
    std::stringstream ss;

    if (root == nullptr)
        throw std::runtime_error("The AVL tree is empty");

    std::queue<std::shared_ptr<Node<T>>> q;
    q.push(root);

    while (!q.empty())
    {
        std::shared_ptr<Node<T>> current = q.front();
        q.pop();

        ss << current->get_data() << " ";

        if (current->get_left() != nullptr)
            q.push(current->get_left());

        if (current->get_right() != nullptr)
            q.push(current->get_right());
    }

    return ss.str();
}