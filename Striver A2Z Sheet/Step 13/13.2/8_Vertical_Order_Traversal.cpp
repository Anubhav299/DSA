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

void setRowColumn(TreeNode *root, int level, int vertical, map<int, map<int, multiset<int>>> &nodes)
{
    if(root == NULL)
    {
        return;
    }
    nodes[vertical][level].insert(root->val);
    setRowColumn(root->left, level + 1, vertical - 1, nodes);
    setRowColumn(root->right, level + 1, vertical + 1, nodes);
    
}

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    map<int, map<int, multiset<int>>> nodes;
    int level, vertical;
    level = vertical = 0;
    vector<vector<int>> ans;
    setRowColumn(root, level, vertical, nodes);
    for(auto itr: nodes)
    {
        vector<int> col;
        for(auto it: itr.second)
        {
            col.insert(col.end(), it.second.begin(), it.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}

int main()
{

    return 0;
}