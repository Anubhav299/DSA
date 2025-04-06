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

/*
the main intuition is the same as before only now we just keep on updating the levels with the new value instead of checking if 
it already exists like in top view
*/

vector<int> bottomView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    map<int, int> mpp;
    int vertical;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (q.empty() != true)
    {
        auto it = q.front();
        q.pop();
        vertical = it.second;
        Node *temp = it.first;
        mpp[vertical] = temp->data;

        if (temp->left != NULL)
        {
            q.push({temp->left, vertical - 1});
        }
        if (temp->right != NULL)
        {
            q.push({temp->right, vertical + 1});
        }
    }
    for (auto it : mpp)
    {
        ans.push_back(it.second);
    }
    return ans;
}

int main()
{
    vector<int> ans;
    Node *root = new Node(20);
    root->right = new Node(22);
    root->left = new Node(8);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->left->right->left = new Node(10);
    root->right->left = new Node(4);
    root->right->left->right = new Node(14);
    root->right->right= new Node(25);

    ans = bottomView(root);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}