#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

bool traversal(Node *root, vector<int> &ans, int x)
{
    // If the current node is null, return false
    if (root == NULL)
        return false;

    // add current node to path vector(ans vector)
    ans.push_back(root->data);

    // if node is found return true
    if (root->data == x)
        return true;

    // recursively search for target x in left , right sub tree
    if (traversal(root->left, ans, x) || traversal(root->right, ans, x))
    {
        return true;
    }

    // if node is not found backtrack and return false
    ans.pop_back();
    return false;
}

int main()
{
    Node *root = new Node(3);
    root->left = new Node(5);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);
    root->right = new Node(1);
    root->right->left = new Node(0);
    root->right->right = new Node(8);

    vector<int> ans1, ans2;
    traversal(root, ans1, 1);
    traversal(root, ans2, 0);
    int size = (ans1.size() >= ans2.size()) ? ans2.size() : ans1.size();
    int LCA = root->data;

    for (int i = 0; i < size; i++)
    {
        if(ans1[i] == ans2[i])
        {
            LCA = ans1[i];
        }
        else
        {
            break;
        }
    }
    cout << LCA;
    return 0;
}