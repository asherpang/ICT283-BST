# Binary Search Tree (BST)

This project demonstrates the concepts of Binary Search Trees (BSTs) by constructing a simple BST and implementing various tree traversal methods. The project also explores the differences between recursive and iterative approaches to tree operations.

## Objectives

- Learn BST concepts.
- Construct a simple Binary Search Tree (BST).
- Demonstrate recursive vs iterative approaches.

## Project Structure

The project includes the following files:

- `main.cpp`: The main driver file that demonstrates the BST operations.
- `BST.h`: The header file defining the BST class template.
- `Date.h`: The header file defining the Date class.
- `Date.cpp`: The implementation file for the Date class.

## Prerequisites

- Code::Blocks IDE (or any C++ compiler that supports C++11 or later).

## How to Compile and Run

1. Open Code::Blocks IDE.
2. Create a new project and add `main.cpp`, `BST.h`, `Date.h`, and `Date.cpp` to the project.
3. Make sure to configure the project settings to include all the necessary files.
4. Compile and run the project.

## Files Description

### `main.cpp`

This file contains the main function, which demonstrates the following operations on the BST:

- Loading dates from a file into the BST.
- Performing in-order, pre-order, and post-order traversals.
- Searching for a specific date in the BST.
- Deleting the entire BST.

### `BST.h`

This header file defines the `Bst` class template, which implements the following BST operations:

- Insertion of a value.
- Deletion of all nodes.
- Searching for a value.
- In-order traversal.
- Pre-order traversal.
- Post-order traversal.

### `Date.h` and `Date.cpp`

These files define and implement the `Date` class, which represents a date with day, month, and year components. The class provides methods for setting and getting these components, as well as overloaded operators for comparison and input/output operations.

## Example Usage

Here is an example of how the BST is used in the `main.cpp` file:

```cpp
#include "BST.h"
#include "Date.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>

// Function to load dates from a single file into the BST
void LoadDates(const std::string& filename, Bst<Date>& dateTree) {
    std::ifstream infile(filename);
    std::string line;

    while (std::getline(infile, line)) {
        std::istringstream dateStream(line);
        Date date;
        dateStream >> date;
        dateTree.Insert(date);
    }
}

int main() {
    Bst<Date> dateTree;

    // Load dates from date.txt file into the BST
    LoadDates("date.txt", dateTree);

    // Demonstrate tree operations
    std::cout << "In-Order Traversal: ";
    dateTree.InOrder();

    std::cout << "Pre-Order Traversal: ";
    dateTree.PreOrder();

    std::cout << "Post-Order Traversal: ";
    dateTree.PostOrder();

    // Search for a specific date
    Date searchDate(1, 1, 2022);
    if (dateTree.Search(searchDate)) {
        std::cout << "Date " << searchDate << " found in the tree." << std::endl;
    } else {
        std::cout << "Date " << searchDate << " not found in the tree." << std::endl;
    }

    // Delete the tree
    dateTree.DeleteTree();

    return 0;
}
