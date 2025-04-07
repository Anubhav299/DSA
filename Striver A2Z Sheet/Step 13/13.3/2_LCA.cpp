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

/*check register, video and 
the main intuition behind this is that we keep checking every node and either the node returns a null or p or q node 
so what we end up having is that as we go down in levels we encounter our p and q and where-ever we find p and q combined as in both are returned as not null by a node then that node will be the LCA
*/
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL || root == p || root == q)
    {
        return root;
    }

    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    if (left == NULL)
        return right;
    else if (right == NULL)
        return left;
    else
        return root;
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    TreeNode *LCA = root, *p = root->left->right->left, *q = root->left;
    LCA = lowestCommonAncestor(root, p, q);
    cout << LCA->val;
}

/*
The main intuition behind the brute force is that we find out the path for both nodes and since that path will contain the parent node(if exists) then we can find the last intersection of path and that will be LCA
*/

/*

bool traversal(TreeNode *root, vector<TreeNode *> &ans, TreeNode *x)
{
    // If the current node is null, return false
    if (root == NULL)
    return false;

    // add current node to path vector(ans vector)
    ans.push_back(root);

    // if node is found return true
    if (root == x)
    return true;

    // recursively search for target x in left , right sub tree
    if (traversal(root->left, ans, x) || traversal(root->right, ans, x))
    {
        return true;
    }

    // if node is not found backtrack and return false
    ans.pop_back();
    return false;
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    vector<TreeNode *> ans1, ans2;
    traversal(root, ans1, p);
    traversal(root, ans2, q);
    int size = (ans1.size() >= ans2.size()) ? ans2.size() : ans1.size();
    TreeNode *LCA = root;
    for (int i = 0; i < size; i++)
    {
        if (ans1[i] == ans2[i])
        {
            LCA = ans1[i];
        }
        else
        {
            break;
        }
    }
    return LCA;
}

//check out the LeetCode Code in case you don't understand the main function of the program.
int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    TreeNode *LCA = root, *p = root->right, *q = root->right->left;

    vector<TreeNode *> ans1, ans2;
    LCA = lowestCommonAncestor(root, p, q);
    // traversal(root, ans2, q);
    // int size = (ans1.size() >= ans2.size()) ? ans2.size() : ans1.size();

    // for (int i = 0; i < size; i++)
    // {
    //     if (ans1[i] == ans2[i])
    //     {
    //         LCA = ans1[i];
    //     }
    //     else
    //     {
    //         break;
    //     }
    // }
    cout << LCA->val;
    return 0;
}
*/