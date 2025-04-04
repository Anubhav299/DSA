#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor to initialize a new node
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// stores all the leaves in a tree
void findLeaf(Node *root, vector<int> &ans)
{
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }
    if (root->left)
        findLeaf(root->left, ans);
    if (root->right)
        findLeaf(root->right, ans);
}

vector<int> boundaryTraversal(Node *root)
{
    vector<int> ans, rTemp;
    Node *rightTemp = root->right, *leftTemp = root->left;

    if (root == NULL)
        return ans;

    ans.push_back(root->data);

    if (root->left == NULL && root->right == NULL) // only one node
        return ans;

    //stores the left boundary elements
    while (leftTemp != NULL)
    {
        if (leftTemp->left || leftTemp->right)
        {
            ans.push_back(leftTemp->data);
        }
        if (leftTemp->left)
        {
            leftTemp = leftTemp->left;
        }
        else
        {
            leftTemp = leftTemp->right;
        }
    }

    //stores the leaf elements
    findLeaf(root, ans);

    //stores the right boundary elements
    while (rightTemp != NULL)
    {
        if (rightTemp->left || rightTemp->right)
        {
            rTemp.push_back(rightTemp->data);
        }
        if (rightTemp->right)
        {
            rightTemp = rightTemp->right;
        }
        else
        {
            rightTemp = rightTemp->left;
        }
    }
    reverse(rTemp.begin(), rTemp.end());
    copy(rTemp.begin(), rTemp.end(), std::back_inserter(ans));
    return ans;
}

int main()
{
    Node *root = new Node(1);
    // root->left = new Node(5);
    root->right = new Node(2);
    // root->left->left = new Node(3);
    // root->left->right = new Node(8);
    // root->left->right->left = new Node(7);
    root->right->left = new Node(3);
    root->right->right = new Node(4);

    vector<int> arr;
    arr = boundaryTraversal(root);
    for (auto it : arr)
    {
        cout << it << " ";
    }
    return 0;
}