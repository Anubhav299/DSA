#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

//striver's approach
int findFloor(Node *root, int input)
{
    int floor = -1;
    while(root)
    {
        if(root->data == input)
        {
            floor = root->data;
            return floor;
        }
        if(root->data < input)
        {
            floor = root->data;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return floor;
}

//recursive approach
/*void helperFloor(Node *root, int x, int &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data <= x)
    {
        ans = root->data;
        if (root->data == x)
        {
            ans = x;
            return;
        }
        helperFloor(root->right, x, ans);
    }
    else
    {
        helperFloor(root->left, x, ans);
    }
    return;
}

int floor(Node *root, int x)
{
    if (root == NULL)
        return -1;
    int ans = -1;
    helperFloor(root, x, ans);
    return ans;
}*/

int main()
{

    return 0;
}