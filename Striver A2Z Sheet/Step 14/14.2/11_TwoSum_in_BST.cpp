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

TreeNode *searchBST(TreeNode *root, int x)
{
    while (root != NULL && root->val != x)
    {
        root = (x < root->val) ? root->left : root->right;
    }
    return root;
}

bool findTarget(TreeNode *root, int k)
{
    stack<TreeNode *> st;
    TreeNode *node = root;
    while (st.empty() != true || node != NULL)
    {
        if (node)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            TreeNode *temp, *curr = st.top();
            st.pop();
            temp = searchBST(root, (k - (curr->val)));
            if (temp != NULL && temp != curr)
            {
                return true;
            }
            node = curr->right;
        }
    }
    return false;
}

int main()
{

    return 0;
}