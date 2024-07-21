#ifndef BST_H
#define BST_H

#include <iostream>
#include "Date.h"

/**
 * @brief Binary Search Tree (BST) class template
 *
 * @tparam T The type of the data stored in the BST nodes
 */
template <class T>
class Bst {
private:
    /**
     * @brief Node struct to represent each node in the BST
     *
     * @tparam U The type of the data stored in the node
     */
    template <class U>
    struct Node {
        U data;       ///< The data stored in the node
        Node* left;   ///< Pointer to the left child
        Node* right;  ///< Pointer to the right child

        /**
         * @brief Construct a new Node object
         *
         * @param value The data to be stored in the node
         */
        Node(U value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node<T>* root;  ///< Root node of the BST

    /**
     * @brief Insert a value into the BST
     *
     * @param node The current node
     * @param value The value to be inserted
     * @return Node<T>* The updated node
     */
    Node<T>* Insert(Node<T>* node, T value);

    /**
     * @brief Recursively delete all nodes in the BST
     *
     * @param node The current node
     */
    void DeleteTree(Node<T>* node);

    /**
     * @brief Search for a value in the BST
     *
     * @param node The current node
     * @param value The value to be searched
     * @return Node<T>* The node containing the value or nullptr if not found
     */
    Node<T>* Search(Node<T>* node, T value);

    /**
     * @brief Perform in-order traversal of the BST
     *
     * @param node The current node
     */
    void InOrder(Node<T>* node);

    /**
     * @brief Perform pre-order traversal of the BST
     *
     * @param node The current node
     */
    void PreOrder(Node<T>* node);

    /**
     * @brief Perform post-order traversal of the BST
     *
     * @param node The current node
     */
    void PostOrder(Node<T>* node);

public:
    /**
     * @brief Construct a new Bst object
     */
    Bst();

    /**
     * @brief Destroy the Bst object
     */
    ~Bst();

    /**
     * @brief Insert a value into the BST
     *
     * @param value The value to be inserted
     */
    void Insert(T value);

    /**
     * @brief Delete all nodes in the BST
     */
    void DeleteTree();

    /**
     * @brief Search for a value in the BST
     *
     * @param value The value to be searched
     * @return true If the value is found
     * @return false If the value is not found
     */
    bool Search(T value);

    /**
     * @brief Perform in-order traversal of the BST
     */
    void InOrder();

    /**
     * @brief Perform pre-order traversal of the BST
     */
    void PreOrder();

    /**
     * @brief Perform post-order traversal of the BST
     */
    void PostOrder();
};

// Constructor initializes the root to nullptr
template <class T>
Bst<T>::Bst() : root(nullptr) {}

// Destructor calls DeleteTree to clean up all nodes
template <class T>
Bst<T>::~Bst() {
    DeleteTree();
}

// Private method to insert a value starting from the given node
template <class T>
typename Bst<T>::template Node<T>* Bst<T>::Insert(Node<T>* node, T value) {
    if (node == nullptr) {
        // Create a new node if the current node is null
        return new Node<T>(value);
    }
    if (value < node->data) {
        // Recursively insert into the left subtree
        node->left = Insert(node->left, value);
    } else if (value > node->data) {
        // Recursively insert into the right subtree
        node->right = Insert(node->right, value);
    }
    // Return the updated node (no duplicates allowed)
    return node;
}

// Public method to insert a value into the BST
template <class T>
void Bst<T>::Insert(T value) {
    root = Insert(root, value);
}

// Private method to recursively delete all nodes starting from the given node
template <class T>
void Bst<T>::DeleteTree(Node<T>* node) {
    if (node == nullptr) return;
    // Recursively delete the left and right subtrees
    DeleteTree(node->left);
    DeleteTree(node->right);
    // Delete the current node
    delete node;
}

// Public method to delete all nodes in the BST
template <class T>
void Bst<T>::DeleteTree() {
    DeleteTree(root);
    root = nullptr;
}

// Private method to search for a value starting from the given node
template <class T>
typename Bst<T>::template Node<T>* Bst<T>::Search(Node<T>* node, T value) {
    if (node == nullptr || node->data == value) {
        // Return the node if found or null if not found
        return node;
    }
    if (value < node->data) {
        // Recursively search in the left subtree
        return Search(node->left, value);
    } else {
        // Recursively search in the right subtree
        return Search(node->right, value);
    }
}

// Public method to search for a value in the BST
template <class T>
bool Bst<T>::Search(T value) {
    return Search(root, value) != nullptr;
}

// Private method to perform in-order traversal starting from the given node
template <class T>
void Bst<T>::InOrder(Node<T>* node) {
    if (node == nullptr) return;
    // Traverse the left subtree
    InOrder(node->left);
    // Print the current node's data
    std::cout << node->data << " ";
    // Traverse the right subtree
    InOrder(node->right);
}

// Public method to perform in-order traversal
template <class T>
void Bst<T>::InOrder() {
    InOrder(root);
    std::cout << std::endl;
}

// Private method to perform pre-order traversal starting from the given node
template <class T>
void Bst<T>::PreOrder(Node<T>* node) {
    if (node == nullptr) return;
    // Print the current node's data
    std::cout << node->data << " ";
    // Traverse the left subtree
    PreOrder(node->left);
    // Traverse the right subtree
    PreOrder(node->right);
}

// Public method to perform pre-order traversal
template <class T>
void Bst<T>::PreOrder() {
    PreOrder(root);
    std::cout << std::endl;
}

// Private method to perform post-order traversal starting from the given node
template <class T>
void Bst<T>::PostOrder(Node<T>* node) {
    if (node == nullptr) return;
    // Traverse the left subtree
    PostOrder(node->left);
    // Traverse the right subtree
    PostOrder(node->right);
    // Print the current node's data
    std::cout << node->data << " ";
}

// Public method to perform post-order traversal
template <class T>
void Bst<T>::PostOrder() {
    PostOrder(root);
    std::cout << std::endl;
}

#endif // BST_H

