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
the main intuition is that we start by iterating over every node from the top and check if its the first node in its vertical level, if yes we insert it into a map along with its vertical level, if not we move on
*/
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

        if (mpp.find(vertical) == mpp.end())        //if there isn't an element in vertical level
                                                    //means that we insert it as it would be in top view
        {
            mpp[vertical] = temp->data;
        }

        if (temp->left != NULL)                     // now we go to the left child and check if 
                                                    //its the first node in its vertical level
        {
            q.push({temp->left, vertical - 1});
        }

        if (temp->right != NULL)                    // now we go to the right child and check if 
                                                    //its the first node in its vertical level
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