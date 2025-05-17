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

class Solution
{
private:
    TreeNode *first;
    TreeNode *prev;
    TreeNode *middle;
    TreeNode *last;

public:
    void inOrderTrav(TreeNode *root)
    {
        if (!root)
            return;
        inOrderTrav(root->left);

        if (root->val < prev->val) // violation found
        {
            if (first == NULL) // first doesn't exist so, this would be the
                               // first violation
            {
                first = prev;
                middle = root;
            }
            else // second violation
            {
                last = root;
            }
        }
        prev = root;
        inOrderTrav(root->right);
    }

    void recoverTree(TreeNode *root)
    {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inOrderTrav(root);
        if (first && last)
            swap(first->val, last->val);
        else
            swap(first->val, middle->val);
    }
};

int main()
{

    return 0;
}