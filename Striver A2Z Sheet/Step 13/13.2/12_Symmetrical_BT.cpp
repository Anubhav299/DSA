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

//using recursive DFS
//helper function recursively checks for symmetric nodes and if values are same, if not then stores in check as false 
void SymmetricHelper(TreeNode *temp1, TreeNode *temp2, bool &check)
{
    if((temp1 == NULL && temp2 == NULL) || check != true)
    {
        return;
    }
    if ((temp1 == NULL && temp2 != NULL) || (temp2 == NULL && temp1 != NULL))
    {
        check = false;
        return;
    }    
    if(temp1->val != temp2->val)
    {
        check = false;
        return;
    }
    SymmetricHelper(temp1->left, temp2->right, check);
    SymmetricHelper(temp1->right, temp2->left, check);
}

bool isSymmetric(TreeNode *root)
{
    bool check = true;
    SymmetricHelper(root->left, root->right, check);
    return check;
}

//using 2 queues, can be reduced to 1 but still
// bool isSymmetric(TreeNode *root)
// {
//     queue<TreeNode *> q1, q2;
//     if (root == NULL || (root->left == NULL && root->right == NULL))
//         return true;
//     q1.push(root->left);
//     q2.push(root->right);
//     while (q1.empty() != true || q2.empty() != true)
//     {
//         TreeNode *temp1 = q1.front();
//         TreeNode *temp2 = q2.front();
//         q1.pop();
//         q2.pop();

//         if ((temp1 == NULL && temp2 != NULL) || (temp2 == NULL && temp1 != NULL))
//             return false;
//         if (temp1->val != temp2->val)
//         {
//             return false;
//         }
//         if (temp1->left != NULL || temp2->right != NULL)
//         {
//             q1.push(temp1->left);
//             q2.push(temp2->right);
//         }
//         if (temp1->right != NULL || temp2->left != NULL)
//         {
//             q1.push(temp1->right);
//             q2.push(temp2->left);
//         }
//     }
//     if (q1.empty() == q2.empty() && q1.empty() == true)
//     {
//         return true;
//     }
//     return false;
// }


int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(3);
    root->right->right->right = new TreeNode(3);
    root->left->left->right = new TreeNode(6);
    root->right->right->left = new TreeNode(6);

    cout << isSymmetric(root);
    return 0;
}