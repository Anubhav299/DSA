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

/*
so the main intuition behind the right view of a binary tree is that we traverse from the root node and traverse the left node then right node and upon meeting a new row we update the value in map and 
since here left child and right child are both at row = 'r+1' from the parent which is at row 'r'we update the value and since this is right view so we visit left first so that later right values can get updated if needed.
*/
vector<int> rightSideView(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    map<int, int> mpp;
    int row;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    while (q.empty() != true)
    {
        auto it = q.front();
        q.pop();
        row = it.second;
        TreeNode *temp = it.first;
        mpp[row] = temp->val;

        if (temp->left != NULL)
        {
            q.push({temp->left, row + 1});
        }
        if (temp->right != NULL)
        {
            q.push({temp->right, row + 1});
        }
    }
    for (auto it : mpp)
    {
        ans.push_back(it.second);
    }
    return ans;
}

int main()
{
    vector<int> ans;
    TreeNode *root = new TreeNode(1);
    // root->right = new TreeNode(22);
    // root->left = new TreeNode(8);
    // root->left->left = new TreeNode(5);
    // root->left->right = new TreeNode(3);
    // root->left->right->left = new TreeNode(10);
    // root->right->left = new TreeNode(4);
    // root->right->left->right = new TreeNode(14);
    // root->right->right = new TreeNode(25);

    root->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(4);


    ans = rightSideView(root);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}