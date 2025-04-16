#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void checkSum(Node *root, bool &check)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        return;
    int lval, rval;
    if (root->left == NULL)
    {
        lval = 0;
    }
    else
    {
        lval = root->left->data;
    }
    if (root->right == NULL)
    {
        rval = 0;
    }
    else
    {
        rval = root->right->data;
    }
    if (root->data != (lval + rval))
    {
        check = false;
        return;
    }
    checkSum(root->left, check);
    checkSum(root->right, check);
}

int isSumProperty(Node *root)
{
    bool check = true;
    checkSum(root, check);
    return check;
}

int main()
{

    return 0;
}