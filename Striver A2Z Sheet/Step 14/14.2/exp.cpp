#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class NodeVal
{
    public:
        int maxNode, minNode, maxSize;
    NodeVal(int minNode, int maxNode, int maxSize)
    {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

NodeVal largestBSTHelper(Node *root)
{
    //Empty tree is a BST of size 0
    if(root == NULL)
        return NodeVal(INT_MIN, INT_MAX, 0);

    //Getting the values from left and right subtree of current tree
    auto left = largestBSTHelper(root->left);
    auto right = largestBSTHelper(root->right);

    //Current node is greater than max in left and smaller than min in right, then it is a BST
    if(left.maxNode < root->data && root->data < right.minNode)
    {
        return NodeVal(min(left.minNode, root->data), max(right.maxNode, root->data), 1 + left.maxSize + right.maxSize);
    }
    //otherwise return [-inf, inf] so that the parent can't be a BST
    return NodeVal(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
}

int largestBst(Node *root)
{
    return largestBSTHelper(root).maxSize;
}

int main()
{
}