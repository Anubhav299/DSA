#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

Node *findMinNode(Node *root)
{
    if (root->left == NULL)
    {
        return root;
    }
    return findMinNode(root->left);
}

int minValue(Node *root)
{
    if (root->left == NULL)
        return root->data;
    Node *min = findMinNode(root);
    return min->data;
}

int main()
{

    return 0;
}