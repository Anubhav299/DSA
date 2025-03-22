#include <iostream>
using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    
    // Constructor to initialize a new node
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Function to insert a new node into the Binary Search Tree
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);  // Create a new node if the tree is empty or a position is found
    }

    if (value < root->data) {
        root->left = insert(root->left, value);  // Insert into the left subtree
    } else if (value > root->data) {
        root->right = insert(root->right, value);  // Insert into the right subtree
    }
    return root;
}

// In-order traversal (Left, Root, Right)
void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);  // Traverse left subtree
    cout << root->data << " ";      // Visit the root
    inorderTraversal(root->right); // Traverse right subtree
}

// Pre-order traversal (Root, Left, Right)
void preorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";      // Visit the root
    preorderTraversal(root->left);  // Traverse left subtree
    preorderTraversal(root->right); // Traverse right subtree
}

// Post-order traversal (Left, Right, Root)
void postorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    postorderTraversal(root->left);  // Traverse left subtree
    postorderTraversal(root->right); // Traverse right subtree
    cout << root->data << " ";       // Visit the root
}

int main() {
    Node* root = nullptr;

    // Insert nodes into the binary search tree
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Perform tree traversals
    cout << "In-order traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Pre-order traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Post-order traversal: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}
