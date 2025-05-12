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

// optimal where TC : O(N)
//logic here is that we maintain an upper bound and check whether element comes under that bound
TreeNode *bstFromPreorder(vector<int> &preorder)
{
    int i = 0;
    return insertTree(preorder, i, INT_MAX);
}

TreeNode *insertTree(vector<int> &preorder, int &i, int bound)
{
    if (i == preorder.size() || preorder[i] > bound)
        return NULL;
    TreeNode *root = new TreeNode(preorder[i++]);
    root->left = insertTree(preorder, i, root->val);
    root->right = insertTree(preorder, i, bound);
    return root;
}

// Brute Force where Worst Case TC : O(N^2)
/*
TreeNode *insertTree(TreeNode *root, int x)
{
    if (root == NULL)
    {
        return new TreeNode(x);
    }
    if (root->val < x)
        root->right = insertTree(root->right, x);
    else if (root->val > x)
        root->left = insertTree(root->left, x);
    return root;
}

TreeNode *bstFromPreorder(vector<int> &preorder)
{
    TreeNode *root = new TreeNode(preorder[0]);
    for (int i = 1; i < preorder.size(); i++)
    {
        root = insertTree(root, preorder[i]);
    }
    return root;
}
*/

int main()
{

    return 0;
}