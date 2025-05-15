#include <bits/stdc++.h>
using namespace std;



class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

int countNodes(Node *root)
{
    if (!root)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

bool isCBT(Node *root, int i, int n)
{
    if (root == NULL)
        return true;
    if (i >= n)
        return false;

    bool left = isCBT(root->left, 2 * i + 1, n);
    bool right = isCBT(root->right, 2 * i + 2, n);

    return (left && right);
}

bool isMaxHeap(Node *root)
{
    if (root == NULL)
        return true;

    // Leaf node
    if (root->left == NULL && root->right == NULL)
        return true;

    // Only left child
    if (root->right == NULL)
    {
        if (root->left->data > root->data)
            return false;
        return isMaxHeap(root->left);
    }

    // Both children exist
    if (root->left->data > root->data || root->right->data > root->data)
        return false;

    return isMaxHeap(root->left) && isMaxHeap(root->right);
}

bool isHeap(Node *tree)
{
    int n = countNodes(tree);
    return isCBT(tree, 0, n) && isMaxHeap(tree);
}

int main()
{

    return 0;
}