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

bool traversal(TreeNode *root, vector<TreeNode *> &ans, int x)
{
    // If the current node is null, return false
    if (root == NULL)
        return false;

    // add current node to path vector(ans vector)
    ans.push_back(root);

    // if node is found return true
    if (root->val == x)
        return true;

    // recursively search for target x in left , right sub tree
    if (traversal(root->left, ans, x) || traversal(root->right, ans, x))
    {
        return true;
    }

    // if node is not found backtrack and return false
    ans.pop_back();
    return false;
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    vector<TreeNode *> ans1, ans2;
    traversal(root, ans1, 5);
    traversal(root, ans2, 1);
    int size = (ans1.size() >= ans2.size()) ? ans2.size() : ans1.size();
    TreeNode *LCA = root;

    for (int i = 0; i < size; i++)
    {
        if (ans1[i] == ans2[i])
        {
            LCA = ans1[i];
        }
        else
        {
            break;
        }
    }
    cout << LCA->val;
    return 0;
}