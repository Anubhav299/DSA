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

//striver's method
bool isSameTree(TreeNode *node1, TreeNode *node2)
{
    // If both nodes are NULL,
    // they are identical
    if (node1 == NULL && node2 == NULL)
    {
        return true;
    }
    // If only one of the nodes is
    // NULL, they are not identical
    if (node1 == NULL || node2 == NULL)
    {
        return false;
    }
    // Check if the current nodes
    // have the same data value
    // and recursively check their
    // left and right subtrees
    return ((node1->val == node2->val) && isSameTree(node1->left, node2->left) && isSameTree(node1->right, node2->right));
}

//my method
// void checkIdentical(TreeNode *p, TreeNode *q, int &check)
// {
//     if (p == NULL || q == NULL)
//     {
//         if (p != q)
//         {
//             check = -1;
//         }
//         return;
//     }
//     if (p->val != q->val)
//     {
//         check = -1;
//     }
//     checkIdentical(p->left, q->left, check);
//     checkIdentical(p->right, q->right, check);
// }

// bool isSameTree(TreeNode *p, TreeNode *q)
// {
//     if (p == NULL || q == NULL)
//     {
//         if (p == NULL && q == NULL)
//             return true;
//         return false;
//     }
//     if (p->val != q->val)
//         return false;

//     int check = 0;
//     checkIdentical(p, q, check);
//     if (check == 0)
//         return true;
//     return false;
// }

int main()
{
    TreeNode *r1 = new TreeNode(1);
    r1->left = new TreeNode(2);
    r1->right = new TreeNode(3);
    // r1->left->right = new TreeNode(2);
    // r1->left->right->left = new TreeNode(2);

    TreeNode *r2 = new TreeNode(1);
    r2->left = new TreeNode(2);
    r2->right = new TreeNode(3);
    // r2->left->left = new TreeNode(2);
    // r2->right->left = new TreeNode(2);

    cout << isSameTree(r1, r2);
    return 0;
}