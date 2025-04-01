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

void postTrav(TreeNode *root, vector<int> &arr)
{
    if (root == NULL)
    {
        return;
    }
    postTrav(root->left, arr);
    postTrav(root->right, arr);
    arr.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> ans;
    postTrav(root, ans);
    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);
    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(9);

    vector<int> ans;
    ans = postorderTraversal(root);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}