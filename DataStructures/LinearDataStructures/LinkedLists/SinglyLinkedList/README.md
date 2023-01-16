# Singly Linked List

## Introduction

Singly linked lists consist of nodes where each node contains a data field as well as a `next` field, which points to the next node in line of nodes. The last node has a `next` field pointing to `nullptr`. The entry point into a linked list is called the `head` of the list. It should be noted that `head` is not a separate node, but the reference to the first node. If the list is empty then the head is a null reference.

The elements in a linked list are linked using pointers as shown in the below image:

![Linked List](../../../../ReadMeImages/Single%20linked%20list%20.png)

## Advantages

- Dynamic size
- Ease of insertion/deletion
- Can be used to implement other data structures like stacks, queues, heaps, etc.

## Disadvantages

- Random access is not allowed. We have to access elements sequentially starting from the first node. So we cannot do a binary search with linked lists efficiently with its default implementation. Read about it [here](https://www.geeksforgeeks.org/binary-search-on-singly-linked-list/).
- Extra memory space for a pointer is required with each element of the list.
- Not cache friendly. Since array elements are contiguous locations, there is locality of reference which is not there in case of linked lists.

## Applications

- Implementation of stack and queue
- Maintaining directory/file system
- Implementation of graph
- Implementation of hash table

## Operations

- Insertion
- Deletion
- Search
- Traversal

## Complexity

| Operation | Complexity |
| --------- | ---------- |
| Insertion | O(1)       |
| Deletion  | O(1)       |
| Search    | O(n)       |
| Traversal | O(n)       |

## References

- [GeeksforGeeks](https://www.geeksforgeeks.org/data-structures/linked-list/)
- [Wikipedia](https://en.wikipedia.org/wiki/Linked_list)
