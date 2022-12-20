/**
 * @file SplayTree.cpp
 * @author Carlos Salguero
 * @brief Implementation of Splay Tree
 * @version 0.1
 * @date 2022-12-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "SplayTree.h"

// Constructor
/**
 * @brief Construct a new Splay Tree< T>:: Splay Tree object
 * @tparam T Type of the data stored in the tree
 * @param root Root of the tree
 */
template <class T>
SplayTree<T>::SplayTree(const std::shared_ptr<Node<T>> &root)
{
    this->root = root;
}

// Private Getter
/**
 * @brief Get the parent of a node
 * @tparam T Type of the data stored in the tree
 * @param node Node to get the parent
 * @return std::shared_ptr<Node<T>> Parent of the node
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
std::shared_ptr<Node<T>> SplayTree<T>::get_parent(
    const std::shared_ptr<Node<T>> &node) const
{
    auto left_child = get_left_child(node);
    auto right_child = get_right_child(node);

    while (left_child != nullptr || right_child != nullptr)
    {
        if (left_child != nullptr)
        {
            if (left_child->get_left() == node ||
                left_child->get_right() == node)
                return left_child;

            left_child = get_left_child(left_child);
        }

        if (right_child != nullptr)
        {
            if (right_child->get_left() == node ||
                right_child->get_right() == node)
                return right_child;

            right_child = get_right_child(right_child);
        }
    }

    return nullptr;
}

/**
 * @brief
 * Get the grandparent of a node
 * @tparam T Type of the data stored in the tree
 * @param node Node to get the grandparent
 * @return std::shared_ptr<Node<T>> Grandparent of the node
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
std::shared_ptr<Node<T>> SplayTree<T>::get_grandparent(
    const std::shared_ptr<Node<T>> &node) const
{
    return get_parent(get_parent(node));
}

/**
 * @brief
 * Get the left child of a node
 * @tparam T Type of the data stored in the tree
 * @param node Node to get the left child
 * @return std::shared_ptr<Node<T>> left child of the node
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
std::shared_ptr<Node<T>> SplayTree<T>::get_left_child(
    const std::shared_ptr<Node<T>> &node) const
{
    return node->get_left();
}

/**
 * @brief
 * Get the right child of a node
 * @tparam T Type of the data stored in the tree
 * @param node Node to get the right child
 * @return std::shared_ptr<Node<T>> Right child of the node
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
std::shared_ptr<Node<T>> SplayTree<T>::get_right_child(
    const std::shared_ptr<Node<T>> &node) const
{
    return node->get_right();
}

// Getter
/**
 * @brief
 * Get the root of the tree
 * @tparam T Type of the data stored in the tree
 * @return std::shared_ptr<Node<T>> Root of the tree
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
std::shared_ptr<Node<T>> SplayTree<T>::get_root() const
{
    return this->root;
}

// Operator overload
/**
 * @brief
 * Overload the operator << to print the tree
 * @tparam ostream_t Type of the data stored in the tree
 * @param os Output stream
 * @param tree Tree to print
 * @return std::ostream& Output stream
 * @time complexity O(n)
 * @space complexity O(n)
 */
template <class ostream_t>
std::ostream &operator<<(std::ostream &os,
                         const SplayTree<ostream_t> &tree)
{
    std::queue<std::shared_ptr<Node<ostream_t>>> queue;
    queue.push(tree.get_root());

    while (!queue.empty())
    {
        std::shared_ptr<Node<ostream_t>> node = queue.front();
        queue.pop();

        os << node->get_data() << " ";

        if (node->get_left() != nullptr)
            queue.push(node->get_left());

        if (node->get_right() != nullptr)
            queue.push(node->get_right());
    }

    return os;
}

// Private Methods
/**
 * @brief
 * Zig rotation of a node in the tree (left rotation)
 * @tparam T Type of the data stored in the tree
 * @param node Node to rotate
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void SplayTree<T>::zig_rotation(const std::shared_ptr<Node<T>> &node)
{
    std::shared_ptr<Node<T>> parent = get_parent(node);
    std::shared_ptr<Node<T>> grandparent = get_grandparent(node);

    if (grandparent == nullptr)
    {
        if (node == get_left_child(parent))
        {
            parent->set_left(node->get_right());
            node->set_right(parent);
        }

        else
        {
            parent->set_right(node->get_left());
            node->set_left(parent);
        }
    }

    else
    {
        if (node == get_left_child(parent))
        {
            parent->set_left(node->get_right());
            node->set_right(parent);

            if (parent == get_left_child(grandparent))
                grandparent->set_left(node);
            else
                grandparent->set_right(node);
        }

        else
        {
            parent->set_right(node->get_left());
            node->set_left(parent);

            if (parent == get_left_child(grandparent))
                grandparent->set_left(node);
            else
                grandparent->set_right(node);
        }
    }
}

/**
 * @brief
 * Zag rotation of a node in the tree (right rotation)
 * @tparam T Type of the data stored in the tree
 * @param node Node to rotate
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void SplayTree<T>::zag_rotation(const std::shared_ptr<Node<T>> &node)
{
    std::shared_ptr<Node<T>> parent = get_parent(node);
    std::shared_ptr<Node<T>> grandparent = get_grandparent(node);

    if (grandparent == nullptr)
    {
        if (node == get_left_child(parent))
        {
            parent->set_left(node->get_right());
            node->set_right(parent);
        }

        else
        {
            parent->set_right(node->get_left());
            node->set_left(parent);
        }
    }

    else
    {
        if (node == get_left_child(parent))
        {
            parent->set_left(node->get_right());
            node->set_right(parent);

            if (parent == get_left_child(grandparent))
                grandparent->set_left(node);
            else
                grandparent->set_right(node);
        }

        else
        {
            parent->set_right(node->get_left());
            node->set_left(parent);

            if (parent == get_left_child(grandparent))
                grandparent->set_left(node);
            else
                grandparent->set_right(node);
        }
    }
}

/**
 * @brief
 * Zig-Zig rotation of a node in the tree (left-left rotation)
 * @tparam T Type of the data stored in the tree
 * @param node Node to rotate
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void SplayTree<T>::zig_zig_rotation(const std::shared_ptr<Node<T>> &node)
{
    std::shared_ptr<Node<T>> parent = get_parent(node);
    std::shared_ptr<Node<T>> grandparent = get_grandparent(node);

    if (grandparent == nullptr)
    {
        if (node == get_left_child(parent))
        {
            parent->set_left(node->get_right());
            node->set_right(parent);
        }

        else
        {
            parent->set_right(node->get_left());
            node->set_left(parent);
        }
    }

    else
    {
        if (node == get_left_child(parent))
        {
            parent->set_left(node->get_right());
            node->set_right(parent);

            if (parent == get_left_child(grandparent))
            {
                grandparent->set_left(node->get_right());
                node->set_right(grandparent);
            }

            else
            {
                grandparent->set_right(node->get_left());
                node->set_left(grandparent);
            }
        }

        else
        {
            parent->set_right(node->get_left());
            node->set_left(parent);

            if (parent == get_left_child(grandparent))
            {
                grandparent->set_left(node->get_right());
                node->set_right(grandparent);
            }

            else
            {
                grandparent->set_right(node->get_left());
                node->set_left(grandparent);
            }
        }
    }
}

/**
 * @brief
 * Zag-Zag rotation of a node in the tree (right-right rotation)
 * @tparam T Type of the data stored in the tree
 * @param node Node to rotate
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void SplayTree<T>::zag_zag_rotation(const std::shared_ptr<Node<T>> &node)
{
    std::shared_ptr<Node<T>> parent = get_parent(node);
    std::shared_ptr<Node<T>> grandparent = get_grandparent(node);

    if (grandparent == nullptr)
    {
        if (node == get_left_child(parent))
        {
            parent->set_left(node->get_right());
            node->set_right(parent);
        }

        else
        {
            parent->set_right(node->get_left());
            node->set_left(parent);
        }
    }

    else
    {
        if (node == get_left_child(parent))
        {
            parent->set_left(node->get_right());
            node->set_right(parent);

            if (parent == get_left_child(grandparent))
            {
                grandparent->set_left(node->get_right());
                node->set_right(grandparent);
            }

            else
            {
                grandparent->set_right(node->get_left());
                node->set_left(grandparent);
            }
        }

        else
        {
            parent->set_right(node->get_left());
            node->set_left(parent);

            if (parent == get_left_child(grandparent))
            {
                grandparent->set_left(node->get_right());
                node->set_right(grandparent);
            }

            else
            {
                grandparent->set_right(node->get_left());
                node->set_left(grandparent);
            }
        }
    }
}

/**
 * @brief
 * Zig-Zag rotation of a node in the tree (left-right rotation)
 * @tparam T Type of the data stored in the tree
 * @param node Node to rotate
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void SplayTree<T>::zig_zag_rotation(const std::shared_ptr<Node<T>> &node)
{
    std::shared_ptr<Node<T>> parent = get_parent(node);
    std::shared_ptr<Node<T>> grandparent = get_grandparent(node);

    if (grandparent == nullptr)
    {
        if (node == get_left_child(parent))
        {
            parent->set_left(node->get_right());
            node->set_right(parent);
        }

        else
        {
            parent->set_right(node->get_left());
            node->set_left(parent);
        }
    }

    else
    {
        if (node == get_left_child(parent))
        {
            parent->set_left(node->get_right());
            node->set_right(parent);

            if (parent == get_left_child(grandparent))
            {
                grandparent->set_left(node->get_right());
                node->set_right(grandparent);
            }

            else
            {
                grandparent->set_right(node->get_left());
                node->set_left(grandparent);
            }
        }

        else
        {
            parent->set_right(node->get_left());
            node->set_left(parent);

            if (parent == get_left_child(grandparent))
            {
                grandparent->set_left(node->get_right());
                node->set_right(grandparent);
            }

            else
            {
                grandparent->set_right(node->get_left());
                node->set_left(grandparent);
            }
        }
    }
}

/**
 * @brief
 * Zag-Zig rotation of a node in the tree (right-left rotation)
 * @tparam T Type of the data stored in the tree
 * @param node Node to rotate
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void SplayTree<T>::zag_zig_rotation(const std::shared_ptr<Node<T>> &node)
{
    std::shared_ptr<Node<T>> parent = get_parent(node);
    std::shared_ptr<Node<T>> grandparent = get_grandparent(node);

    if (grandparent == nullptr)
    {
        if (node == get_left_child(parent))
        {
            parent->set_left(node->get_right());
            node->set_right(parent);
        }

        else
        {
            parent->set_right(node->get_left());
            node->set_left(parent);
        }
    }

    else
    {
        if (node == get_left_child(parent))
        {
            parent->set_left(node->get_right());
            node->set_right(parent);

            if (parent == get_left_child(grandparent))
            {
                grandparent->set_left(node->get_right());
                node->set_right(grandparent);
            }

            else
            {
                grandparent->set_right(node->get_left());
                node->set_left(grandparent);
            }
        }

        else
        {
            parent->set_right(node->get_left());
            node->set_left(parent);

            if (parent == get_left_child(grandparent))
            {
                grandparent->set_left(node->get_right());
                node->set_right(grandparent);
            }

            else
            {
                grandparent->set_right(node->get_left());
                node->set_left(grandparent);
            }
        }
    }
}

/**
 * @brief
 * Swap the data of two nodes
 * @tparam T Type of the data stored in the tree
 * @param node1 First node
 * @param node2 Second node
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
void SplayTree<T>::swap(const std::shared_ptr<Node<T>> &node1,
                        const std::shared_ptr<Node<T>> &node2)
{
    T temp = node1->get_data();
    node1->set_data(node2->get_data());
    node2->set_data(temp);
}

/**
 * @brief
 * Splay a node in the tree
 * @tparam T Type of the data stored in the tree
 * @param node Node to splay
 * @time complexity O(log n)
 * @space complexity O(1)
 */
template <class T>
void SplayTree<T>::splay(const std::shared_ptr<Node<T>> &node)
{
    while (node != root)
    {
        std::shared_ptr<Node<T>> parent = get_parent(node);
        std::shared_ptr<Node<T>> grandparent = get_grandparent(node);

        if (grandparent == nullptr)
        {
            if (node == get_left_child(parent))
                zig_rotation(node);

            else
                zag_rotation(node);
        }

        else
        {
            if (node == get_left_child(parent) &&
                parent == get_left_child(grandparent))
                zig_zig_rotation(node);

            else if (node == get_right_child(parent) &&
                     parent == get_right_child(grandparent))
                zag_zag_rotation(node);

            else if (node == get_left_child(parent) &&
                     parent == get_right_child(grandparent))
                zig_zag_rotation(node);

            else
                zag_zig_rotation(node);
        }
    }
}

// Public methods
/**
 * @brief
 * Checks if the tree is empty
 * @tparam T Type of the data stored in the tree
 * @return true if the tree is empty, false otherwise
 * @time complexity O(1)
 * @space complexity O(1)
 */
template <class T>
bool SplayTree<T>::is_empty() const
{
    return root == nullptr;
}

/**
 * @brief
 * Insert a new node in the tree
 * @tparam T Type of the data stored in the tree
 * @param data Data to insert
 * @time complexity O(log n)
 * @space complexity O(1)
 */
template <class T>
void SplayTree<T>::insert(const T &data)
{
    std::shared_ptr<Node<T>> new_node = std::make_shared<Node<T>>(data);

    if (root == nullptr)
    {
        root = new_node;
        return;
    }

    std::shared_ptr<Node<T>> current = root;
    std::shared_ptr<Node<T>> parent = nullptr;

    while (current != nullptr)
    {
        parent = current;

        if (data < current->get_data())
            current = current->get_left();

        else
            current = current->get_right();
    }

    if (data < parent->get_data())
        parent->set_left(new_node);

    else
        parent->set_right(new_node);

    splay(new_node);
}

/**
 * @brief
 * Removes a node from the tree
 * @tparam T Type of the data stored in the tree
 * @param data Data to remove
 * @time complexity O(log n)
 * @space complexity O(1)
 */
template <class T>
void SplayTree<T>::remove(const T &data)
{
    std::shared_ptr<Node<T>> node = search(data);

    if (node == nullptr)
        return;

    if (node->get_left() == nullptr)
    {
        if (node == root)
            root = node->get_right();

        else
        {
            std::shared_ptr<Node<T>> parent = get_parent(node);

            if (node == get_left_child(parent))
                parent->set_left(node->get_right());

            else
                parent->set_right(node->get_right());
        }
    }

    else if (node->get_right() == nullptr)
    {
        if (node == root)
            root = node->get_left();

        else
        {
            std::shared_ptr<Node<T>> parent = get_parent(node);

            if (node == get_left_child(parent))
                parent->set_left(node->get_left());

            else
                parent->set_right(node->get_left());
        }
    }

    else
    {
        std::shared_ptr<Node<T>> successor = get_successor(node);

        if (node == root)
            root = successor;

        else
        {
            std::shared_ptr<Node<T>> parent = get_parent(node);

            if (node == get_left_child(parent))
                parent->set_left(successor);

            else
                parent->set_right(successor);
        }

        successor->set_left(node->get_left());
    }
}

/**
 * @brief
 * Search for a node in the tree
 * @tparam T Type of the data stored in the tree
 * @param data Data to search for
 * @return std::shared_ptr<Node<T>> Node containing the data,
 *         nullptr if not found
 * @time complexity O(log n)
 * @space complexity O(1)
 */
template <class T>
std::optional<std::shared_ptr<Node<T>>>
SplayTree<T>::search(const T &data) const
{
    std::shared_ptr<Node<T>> current = root;

    while (current != nullptr)
    {
        if (data == current->get_data())
        {
            splay(current);
            return current;
        }

        else if (data < current->get_data())
            current = current->get_left();

        else
            current = current->get_right();
    }

    return std::nullopt;
}