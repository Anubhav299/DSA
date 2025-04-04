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


vector<vector<int>> zigzaglevelOrder(TreeNode *root)
{
    queue<TreeNode *> q;
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return ans;
    }
    q.push(root);
    int i = 0;
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
        if(i%2 == 1)
        {
            reverse(level.begin(), level.end());
        }
        ans.push_back(level);
        i++;
    }
    return ans;
}

int main()
{
    TreeNode *r1 = NULL;
    r1->left = new TreeNode(9);
    r1->right = new TreeNode(20);
    r1->right->left = new TreeNode(15);
    r1->right->right = new TreeNode(7);
    
    for (auto it : zigzaglevelOrder(r1))
    {
        for(auto itr : it)
        {
            cout << itr << " ";
        }
        cout << endl;
    }
    return 0;
}