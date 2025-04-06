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
the intuition behind this is so we can create a grid like structure with root as (0,0) as in(row, col)
and its left child will have (1,-1) while right child is (1,1)
We use preorder here(but can choose any other traversal to set Row,Column)
we take multiset to ensure that entries that are at the same coordinate are sorted and taken care of
*/
void setRowColumn(TreeNode *root, int level, int vertical, map<int, map<int, multiset<int>>> &nodes)
{
    if (root == NULL)
    {
        return;
    }
    nodes[vertical][level].insert(root->val);
    setRowColumn(root->left, level + 1, vertical - 1, nodes);
    setRowColumn(root->right, level + 1, vertical + 1, nodes);
}

/*
this function takes care of printing the nodes according to the question as we've already stored them in above function onto a map
Now we only take Vertical Levels and make sure that order is maintained according to the question

See Striver Diagram for map visualisation
*/
vector<vector<int>> verticalTraversal(TreeNode *root)
{
    map<int, map<int, multiset<int>>> nodes;
    int level, vertical;
    level = vertical = 0;
    vector<vector<int>> ans;

    setRowColumn(root, level, vertical, nodes); // getting the row, col for each node

    
    // Traverse the map (starting with the leftmost column)
    for (auto p : nodes) // Iterate over the vertical levels from left to right
    {
        vector<int> col; // Vector to store node values for the current vertical level

        // Iterate over the levels at the current vertical line
        for (auto q : p.second) // p.second is a map representing levels at the current vertical
        {
            // Insert all nodes in the current level (multiset ensures sorted order)
            col.insert(col.end(), q.second.begin(), q.second.end());
        }

        // Add the collected values for the current vertical level to the result
        ans.push_back(col);
    }
    return ans;
}

int main()
{

    return 0;
}