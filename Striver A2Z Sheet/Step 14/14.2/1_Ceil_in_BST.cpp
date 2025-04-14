#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// striver's approach
int findCeil(Node *root, int input)
{
    int ceil = -1;
    while (root)
    {
        if (root->data == input)
        {
            ceil = root->data;
            return ceil;
        }
        if (root->data < input)
        {
            root = root->right;
        }
        else
        {
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}

// recursive method
/*void helperCeil(Node *root, int x, int &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data >= x)
    {
        ans = root->data;
        if (root->data == x)
        {
            ans = x;
            return;
        }
        helperCeil(root->left, x, ans);
    }
    else
    {
        helperCeil(root->right, x, ans);
    }
    return;
}

int findCeil(Node *root, int input)
{
    if (root == NULL)
        return -1;
    int ans = -1;
    helperCeil(root, input, ans);
    return ans;
}*/

int main()
{

    return 0;
}