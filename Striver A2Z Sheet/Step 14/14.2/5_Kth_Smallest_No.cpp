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

//for k smallest, we used inorder traversal and a counter
void findKth(TreeNode *root, int &cnt, int k, int &ans)
{
    if (root == NULL || cnt >= k)
    {
        return;
    }
    findKth(root->left, cnt, k, ans);
    cnt++;
    if (cnt == k)
    {
        ans = root->val;
        return;
    }
    findKth(root->right, cnt, k, ans);
}

int kthSmallest(TreeNode *root, int k)
{
    int cnt = 0, ans = -1;
    findKth(root, cnt, k, ans);
    return ans;
}


//for k largest, we use reverse inorder traversal and a counter
void findKthlargest(TreeNode *root, int &cnt, int k, int &ans)
{
    if (root == NULL || cnt >= k)
    {
        return;
    }
    findKthlargest(root->right, cnt, k, ans);
    cnt++;
    if(cnt == k)
    {
        ans = root->val;
        return;
    }
    findKthlargest(root->left, cnt, k, ans);
}

int kthLargest(TreeNode *root, int k)
{
    int ans = -1, cnt = 0;
    findKthlargest(root, cnt, k, ans);
    return ans;
}

int main()
{
    
    return 0;
}