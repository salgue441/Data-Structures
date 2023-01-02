# Documentation of Data Structures

This repository contains implementations in C++20 of the following data structures: Single Linked Lists, Double Linked Lists, Circular Linked Lists, Stacks, Queues, Binary Trees, Binary Search Trees, AVL Trees, Splay Trees, Heaps, Hash Tables, and Graphs.

Every data structure is implemented as template classes and are stored in their own folder. A brief documentation of each can be found inside the markdown files inside Linear, Non Linear, and Abstract Data Structures folders.

Each class uses smart pointers to manage memory. Also, each class has a `to_string()` method (as well as overloading the `<<` operator or equivalent menthods) that prints the data structure in a human readable format. Lastly, each function has a brief description of what it does, the time complexity and space complexity of the function.

The documentation is written in Markdown and the source code is written in C++20. The documentation is generated using [Doxygen](https://www.doxygen.nl/index.html) and the source code is compiled using [GCC](https://gcc.gnu.org/).

## Table of Contents

- [Documentation of Data Structures](#documentation-of-data-structures)
  - [Table of Contents](#table-of-contents)
  - [Data Structures](#data-structures)
    - [Linear Data Structures](#linear-data-structures)
    - [Non Linear Data Structures](#non-linear-data-structures)
    - [Abstract Data Types](#abstract-data-types)

## Data Structures

### Linear Data Structures

Implementation of the linear data structures is in the `LinearDataStructures` folder.

[Linear Data Structures](LinearDataStructures/LinearDataStructures.md)

### Non Linear Data Structures

Implementation of the non linear data structures is in the `NonLinearDataStructures` folder.

[Non Linear Data Structures](NonLinearDataStructures/NonLinearDataStructures.md)

### Abstract Data Types

Implementation of the abstract data types is in the `AbstractDataStructures` folder.

[Abstract Data Types](AbstractDataTypes/AbstractDataTypes.md)
