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

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> inorder;
    stack<TreeNode *> st;
    if (root == NULL)
    {
        return inorder;
    }
    TreeNode *node = root;
    while(st.empty()!=true || node != NULL)
    {
        if(node != NULL)
        {
            st.push(node);
            node = node->left;          // reach the left most node
        }
        else
        {
            node = st.top();
            st.pop();
            inorder.push_back(node->val);
            node = node->right;         //move to the right child
        }
    }
    return inorder;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(5);
    root->left->right->right = new TreeNode(6);

    vector<int> ans;
    ans = inorderTraversal(root);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}