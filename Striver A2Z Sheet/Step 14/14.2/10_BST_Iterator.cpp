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

    void pushAll(TreeNode *node)
    {
        for (; node != NULL; node = node->left)
        {
            st.push(node);
        }
    }

public:
    BSTIterator(TreeNode *root)
    {
        pushAll(root);
    }

    bool hasNext()
    {
        if (st.empty() != true)
        {
            return true;
        }
        return false;
    }

    int next()
    {
        TreeNode *topNode = st.top();
        st.pop();
        if (topNode->right)
        {
            pushAll(topNode->right);
        }
        return topNode->val;
    }
};

int main()
{

    return 0;
}