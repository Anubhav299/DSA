#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Optimal Approach
/*
Intuition : We traverse the tree bottom-up (post-order) so we can: First solve for the left and right subtrees. Then decide whether the current node forms a BST with those subtrees.

Striver's Video Solution for more clarity,
this solution isn't exactly the same as striver's as he did the solution for leetcode whereas we solved it in gfg
*/
class NodeVal
{
public:
    int minNode, maxNode, maxSize;
    bool isBST;
    NodeVal(int minNode, int maxNode, int maxSize, bool isBST)
    {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
        this->isBST = isBST;
    }
};

class Solution
{
public:
    NodeVal largestBSTHelper(Node *root)
    {
        if (!root)
            return NodeVal(INT_MAX, INT_MIN, 0, true);

        NodeVal left = largestBSTHelper(root->left);
        NodeVal right = largestBSTHelper(root->right);

        if (left.isBST && right.isBST && left.maxNode < root->data && root->data < right.minNode)
        {
            return NodeVal(
                min(left.minNode, root->data),
                max(right.maxNode, root->data),
                left.maxSize + right.maxSize + 1,
                true);
        }

        return NodeVal(0, 0, max(left.maxSize, right.maxSize), false);
    }

    int largestBst(Node *root)
    {
        return largestBSTHelper(root).maxSize;
    }
};

// Brute Force
/*
int countNodes(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

bool isBST(Node *root, int &prev)
{
    if (!root)
        return true;

    // Recursively check the left subtree
    if (!isBST(root->left, prev))
        return false;

    // Check the current node value against the previous value
    if (prev >= root->data)
        return false;

    // Update the previous value to the current node's value
    prev = root->data;

    // Recursively check the right subtree
    return isBST(root->right, prev);
}

int largestBst(Node *root)
{
    int ans = 0;
    if (root == NULL)
        return 0;

    Node *curr = root;
    stack<Node *> st;
    while (st.empty() != true || curr != NULL)
    {
        if (curr)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            Node *temp = st.top();
            st.pop();
            int prev = INT_MIN;
            bool check = isBST(temp, prev);
            if (check)
            {
                ans = max(ans, countNodes(temp));
            }
            curr = temp->right;
        }
    }
    return ans;
}
*/

int main()
{

    return 0;
}