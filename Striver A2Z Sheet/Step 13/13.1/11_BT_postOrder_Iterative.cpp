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


vector<int> postorderTraversal(TreeNode *root)
{
    stack<TreeNode *> st1, st2; 
    vector<int> postorder;
    st1.push(root);
    while(st1.empty() != true)
    {
        TreeNode *node = st1.top();
        st1.pop();
        st2.push(node);
        if(node->left != NULL)
        {
            st1.push(node->left);
        }
        if(node->right != NULL)
        {
            st1.push(node->right);
        }
    }
    while(st2.empty()!=true)
    {
        postorder.push_back(st2.top()->val);
        st2.pop();
    }
    return postorder;
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


    vector<int> ans;
    ans = postorderTraversal(root);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}