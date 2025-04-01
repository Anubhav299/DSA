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

vector<vector<int>> PreInPost(TreeNode *root)
{
    vector<int> pre, in, post;
    vector<vector<int>> ans;
    stack<pair<TreeNode *, int>> st;
    st.push({root, 1});
    while(st.empty() != true)
    {
        auto it = st.top();
        st.pop();
        if(it.second == 1)
        {
            pre.push_back(it.first->val);
            it.second++;
            st.push(it);
            if (it.first->left != NULL)
            {
                st.push({it.first->left, 1});
            }
        }
        else if(it.second == 2)
        {
            in.push_back(it.first->val);
            it.second++;
            st.push(it);
            if (it.first->right != NULL)
            {
                st.push({it.first->right, 1});
            }
        }
        else 
        {
            post.push_back(it.first->val);             
        }
    }
    ans.push_back(pre);
    ans.push_back(in);
    ans.push_back(post);
    
    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(8);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->right->left = new TreeNode(9);
    root->right->right->right = new TreeNode(10);
    

    vector<vector<int>> ans;
    ans = PreInPost(root);
    for (auto it : ans)
    {
        for(auto itr : it)
        {
            cout << itr << " ";
        }
        cout << endl;
    }
    return 0;
}