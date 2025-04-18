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

void makeGST(TreeNode *root, int &sum)
{
    if (root == NULL)
        return;
    makeGST(root->right, sum);
    sum += root->val;
    root->val = sum;
    makeGST(root->left, sum);
}

TreeNode *bstToGst(TreeNode *root)
{
    int sum = 0;
    makeGST(root, sum);
    return root;
}

TreeNode *insertIntoBST(TreeNode *root, int val)
{
    if (root == NULL)
    {
        return new TreeNode(val);
    }
    if (val < root->val)
    {
        root->left = insertIntoBST(root->left, val);
    }
    else if (val > root->val)
    {
        root->right = insertIntoBST(root->right, val);
    }
    return root;
}

void inTrav(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    inTrav(root->left);
    cout << root->val << " ";
    inTrav(root->right);
}

vector<vector<int>> levelOrder(TreeNode *root)
{
    queue<TreeNode *> q;
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return ans;
    }

    q.push(root);

    while (q.empty() != true)
    {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
            level.push_back(temp->val);
        }
        ans.push_back(level);
    }
    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(4);
    insertIntoBST(root, 1);
    insertIntoBST(root, 6);
    insertIntoBST(root, 0);
    insertIntoBST(root, 2);
    insertIntoBST(root, 5);
    insertIntoBST(root, 7);
    insertIntoBST(root, 3);
    insertIntoBST(root, 8);
    vector<vector<int>>ans = levelOrder(root);
    for(auto itr:ans)
    {
        for(auto it:itr)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    cout << endl;
    root = bstToGst(root);
    ans = levelOrder(root);
    for(auto itr:ans)
    {
        for(auto it:itr)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}