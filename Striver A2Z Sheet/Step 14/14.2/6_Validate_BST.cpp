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

void checkBST(TreeNode *root, long leftRange, long rightRange, bool &check)
{
    if (root == NULL)
    {
        return;
    }
    if (root->val <= leftRange || root->val >= rightRange)
    {
        check = false;
        return;
    }
    checkBST(root->left, leftRange, root->val, check);
    checkBST(root->right, root->val, rightRange, check);
}

bool isValidBST(TreeNode *root)
{
    if (root == NULL)
    {
        return true;
    }
    bool check = true;
    checkBST(root, LONG_MIN, LONG_MAX, check);
    return check;
}

int main()
{

    return 0;
}