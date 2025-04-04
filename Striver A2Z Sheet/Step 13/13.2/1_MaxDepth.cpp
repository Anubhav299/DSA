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

// Recursive Way
// Disadvantage when tree is skewed
int maxDepth(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);
    return max(leftHeight, rightHeight) + 1;
}

// Level Order Way
int maxDepth2(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int height = 0;
    queue<TreeNode *> q;
    q.push(root);
    while (q.empty() != true)
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
        height++;
    }
    return height;
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

    cout << maxDepth(root);
    cout << endl << maxDepth2(root);

    return 0;
}