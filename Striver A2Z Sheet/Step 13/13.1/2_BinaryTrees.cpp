#include <bits/stdc++.h>
using namespace std;

struct node 
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;

    node->left = NULL;
    node->right = NULL;
    return (node);
}

void create_tree(node *root0, vector<int> &vec)
{
    root0->left = newNode(vec[1]);         // 2
    root0->right = newNode(vec[2]);        // 3
    root0->left->left = newNode(vec[3]);   // 4
    root0->left->right = newNode(vec[4]);  // 5
    root0->right->left = newNode(vec[5]);  // 6
    root0->right->right = newNode(vec[6]); // 7
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    struct node *root = newNode(arr[0]);
    create_tree(root, arr);
    return 0;
}