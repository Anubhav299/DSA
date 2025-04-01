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
    stack<TreeNode *> st;
    vector<int> postorder;
    TreeNode *temp = NULL, *curr = root;
    while (curr != nullptr || !st.empty())
    {
        if (curr != nullptr)
        {
            st.push(curr);
            curr = curr->left;                  // reach the left most node
        }
        else
        {
            temp = st.top()->right;             //check the right node of the left most node
            if (temp == nullptr)                //if it doesn't exist, print the nodes
            {
                temp = st.top();
                st.pop();
                postorder.push_back(temp->val);
                while (!st.empty() && temp == (st.top()->right))        // done for right skewed pattern
                {
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->val);
                }
            }
            else
            {
                curr = temp;
            }
        }
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