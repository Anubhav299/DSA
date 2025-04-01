#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

void inOrder(TreeNode *root, vector<int> &vec)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left, vec);
    vec.push_back(root->data);
    inOrder(root->right, vec);
}

void preOrder(TreeNode *root, vector<int> &vec)
{
    if (root == NULL)
    {
        return;
    }
    vec.push_back(root->data);
    preOrder(root->left, vec);
    preOrder(root->right, vec);
}

void postOrder(TreeNode *root, vector<int> &vec)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left, vec);
    postOrder(root->right, vec);
    vec.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(TreeNode *root)
{
    vector<int> inOrderTrav, preOrderTrav, postOrderTrav;
    vector<vector<int>> ans;

    inOrder(root, inOrderTrav);
    ans.push_back(inOrderTrav);

    preOrder(root, preOrderTrav);
    ans.push_back(preOrderTrav);

    postOrder(root, postOrderTrav);
    ans.push_back(postOrderTrav);
    return ans;
}

int main()
{

    return 0;
}