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

void changeTree(TreeNode *root)
{
    if (root == NULL)
        return;
    int lval = 0, rval = 0;
    // left child value calculation
    if (root->left)
        lval = root->left->val;

    // right child value calculation
    if (root->right)
        rval = root->right->val;

    if (root->val > (lval + rval))
    {
        if (root->left != NULL)
        {
            root->left->val = root->val;
        }
        if (root->right != NULL)
        {
            root->right->val = root->val;
        }
    }
    
    changeTree(root->left);
    changeTree(root->right);

    //calculation of root value
    int tot = 0;
    if (root->left)
        tot += root->left->val;
    if (root->right)
        tot += root->right->val;
    if (root->left || root->right)
        root->val = tot;
}

int main()
{

    return 0;
}