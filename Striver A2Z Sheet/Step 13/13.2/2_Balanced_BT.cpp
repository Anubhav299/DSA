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

int dfsHeight(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int lf = dfsHeight(root->left);
    int rf = dfsHeight(root->right);
    if (lf == -1 || rf == -1)
        return -1;
    if (abs(lf - rf) > 1)
        return -1;
    return max(lf, rf) + 1;
}

bool isBalanced(TreeNode *root)
{
    if (root == NULL)
        return true;
    if (dfsHeight(root) != -1)
    {
        return true;
    }
    return false;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(8);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->right->left = new TreeNode(9);
    root->right->right->right = new TreeNode(10);

    cout << isBalanced(root);
    return 0;
}