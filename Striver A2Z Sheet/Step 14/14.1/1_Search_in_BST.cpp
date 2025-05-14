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

TreeNode *searchBST(TreeNode *root, int val)
{
    while (root != NULL && root->val != val)
    {
        root = (val < root->val) ? root->left : root->right;
    }
    return root;
}

//recursive approach
/*TreeNode *searchBST(TreeNode *root, int val)
{
    if (root == NULL || root->val == val)
        return root;
    if (val < root->val)
    {
        return searchBST(root->left, val);
    }
    return searchBST(root->right, val);
}*/

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

    cout << searchBST(root, 3)->val;
    return 0;
}