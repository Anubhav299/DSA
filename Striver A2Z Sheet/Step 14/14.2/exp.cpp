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

class BSTIterator
{
    stack<TreeNode *> st;
    bool rev;
    void pushAll(TreeNode *node)
    {
        for (; node != NULL;)
        {
            st.push(node);
            if (rev == true)
                node = node->right;
            else
                node = node->left;
        }
    }

public:
    BSTIterator(TreeNode *root, bool r)
    {
        pushAll(root);
        rev = r;
    }

    int next()
    {
        TreeNode *topNode = st.top();
        st.pop();
        if (rev == true)
        {
            pushAll(topNode->left);
        }
        else
        {
            pushAll(topNode->right);
        }
        return topNode->val;
    }
};

class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        if (!root)
            return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int i = l.next();
        int j = r.next();

        while (i < j)
        {
            if (i + j > k)
            {
                j = r.next();
            }
            else if (i + j < k)
            {
                i = l.next();
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{

    return 0;
}