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

// Function to read the list of data files from datasource.txt
std::vector<std::string> ReadDataFiles(const std::string& dataSource) {
    std::ifstream infile(dataSource);
    std::string line;
    std::vector<std::string> files;

    while (std::getline(infile, line)) {
        files.push_back(line);
    }

    return files;
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
    Date searchDate(1, 1, 2022);  // Change this date to test searching
    if (dateTree.Search(searchDate)) {
        std::cout << "Date " << searchDate << " found in the tree." << std::endl;
    } else {
        std::cout << "Date " << searchDate << " not found in the tree." << std::endl;
    }

    // Delete the tree
    dateTree.DeleteTree();

    return 0;
}
