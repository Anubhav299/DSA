#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *inOrderSucc(TreeNode *root, int x)
{
    TreeNode *successor = nullptr;

    TreeNode *curr = root;
    while(curr)
    {
        if(curr->val <= x)
        {
            curr = curr->right;
        }
        else
        {
            successor = curr;
            curr = curr->left;
        }
    }
    return successor;
}

//method
/*int inOrderSucc(TreeNode *root, int x)
{
    int succ = -1;
    TreeNode *temp = root;
    while (temp && temp->val != x)
    {
        if (temp->val < x)
        {
            temp = temp->right;
        }
        else
        {
            succ = temp->val;
            temp = temp->left;
        }
    }

    temp = temp->right;
    while (temp)
    {
        succ = temp->val;
        temp = temp->left;
    }

    return succ;
}
*/

int main()
{
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->left->right = new TreeNode(8);
    root->right->right = new TreeNode(12);

    // cout << inOrderSucc(root, 6);
    cout << (inOrderSucc(root, 4))->val;

    return 0;
}/*
int inOrderPred(TreeNode *root, int x)
{
    int pred = -1;
    TreeNode *temp = root;
    while (temp && temp->val != x)
    {
        if (temp->val < x)
        {
            pred = temp->val;
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }

    temp = temp->left;
    while (temp)
    {
        pred = temp->val;
        temp = temp->right;
    }

    return pred;
}
*/