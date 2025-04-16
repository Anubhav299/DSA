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

void traversal(Node *root, vector<int> path, vector<vector<int>> &ans)
{
    if (root->left == NULL && root->right == NULL)
    {
        path.push_back(root->data);
        ans.push_back(path);
        return;
    }

    path.push_back(root->data);
    if (root->left != NULL)
    {
        traversal(root->left, path, ans);
    }
    if (root->right != NULL)
    {
        traversal(root->right, path, ans);
    }
}

vector<vector<int>> Paths(Node *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    vector<int> path;
    traversal(root, path, ans);
    return ans;
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(9);
    root->right = new Node(0);
    root->left->right = new Node(1);
    root->left->left = new Node(5);
    // root->left->right->left = new Node(6);
    // root->left->right->right = new Node(7);
    // root->right = new Node(3);

    vector<vector<int>> ans;
    ans = Paths(root);
    for (auto itr : ans)
    {
        for (auto it : itr)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}