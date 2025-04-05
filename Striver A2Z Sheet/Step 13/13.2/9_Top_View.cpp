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

vector<int> topView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    map<int, int> mpp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (q.empty() != true)
    {
        auto it = q.front();
        q.pop();
        Node *temp = it.first;
        int vertical = it.second;

        if (mpp.find(vertical) == mpp.end())
        {
            mpp[vertical] = temp->data;
        }

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

    ans = topView(root);
    for (auto it : ans)
    {
        cout << it << endl;
    }
    return 0;
}