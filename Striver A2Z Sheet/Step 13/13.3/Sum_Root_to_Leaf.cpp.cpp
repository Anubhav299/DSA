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

// optimal
void traversal(TreeNode *root, int pathSum, int &finalSum)
{
    if (root->left == NULL && root->right == NULL)
    {
        pathSum = (pathSum * 10) + root->val;
        finalSum += pathSum;
        return;
    }

    pathSum = (pathSum * 10) + root->val;
    if (root->left != NULL)
    {
        traversal(root->left, pathSum, finalSum);
    }
    if (root->right != NULL)
    {
        traversal(root->right, pathSum, finalSum);
    }
}

int sumNumbers(TreeNode *root)
{
    int pSum = 0, fSum = 0;
    traversal(root, pSum, fSum);
    return fSum;
}
// brute force
/*void traversal(TreeNode *root, vector<int> path, vector<vector<int>> &ans)
{
    if (root->left == NULL && root->right == NULL)
    {
        path.push_back(root->val);
        ans.push_back(path);
        return;
    }

    path.push_back(root->val);
    if (root->left != NULL)
    {
        traversal(root->left, path, ans);
    }
    if (root->right != NULL)
    {
        traversal(root->right, path, ans);
    }
}
int sumNumbers(TreeNode *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return root->val;
    vector<vector<int>> ans;
    vector<int> path;
    traversal(root, path, ans);
    int res = 0, final = 0;
    for (auto itr : ans)
    {
        res = 0;
        for (auto it : itr)
        {
            res = (res * 10) + it;
        }
        final += res;
        cout << final << endl;
    }
    return final;
}*/

int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(9);
    root->right = new TreeNode(0);
    root->left->right = new TreeNode(1);
    root->left->left = new TreeNode(5);
    cout << sumNumbers(root);
    return 0;
}