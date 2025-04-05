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



void setVerticalLevel(Node *root, int vertical, map<int, int> &nodes)
{
    if (root == NULL)
        return;
    if (nodes.find(vertical) == nodes.end() )
    {
        nodes[vertical] = root->data;
    }
    setVerticalLevel(root->left, vertical - 1, nodes);
    setVerticalLevel(root->right, vertical + 1, nodes);
}

vector<int> topView(Node *root)
{
}

int main()
{
    map<int, int> nodes;
    Node *root = new Node(1);
    // root->left = new Node(2);
    root->right = new Node(2);
    root->right->left = new Node(3);
    root->right->right = new Node(4);
    root->right->right->left = new Node(5);
    root->right->right->right = new Node(6);
    root->right->right->right->left = new Node(7);
    root->right->right->right->right = new Node(8);
    root->right->right->right->left->left = new Node(9);
    root->right->right->right->left->right = new Node(10);
    root->right->right->right->left->right->left = new Node(11);
    root->right->right->right->left->right->right = new Node(12);
    root->right->right->right->left->right->right->left = new Node(13);
    root->right->right->right->left->right->right->right = new Node(14);

    setVerticalLevel(root, 0, nodes);
    for(auto it:nodes)
    {
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}