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

int maxSum(TreeNode *root, int &maxi)
{
    if (root == NULL)
        return 0;

    int leftTreeSum = max(0, maxSum(root->left, maxi));
    int rightTreeSum = max(0, maxSum(root->right, maxi));

    maxi = max(maxi, leftTreeSum + rightTreeSum + root->val);
    return root->val + max(leftTreeSum, rightTreeSum);    //doing this as we need a path that has more value
}                                                         //check register for this question

int maxPathSum(TreeNode *root)
{
    int maxi = INT_MIN;
    maxSum(root, maxi);
    return maxi;
}

int main()
{

    return 0;
}