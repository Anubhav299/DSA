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

// Striver's Method
TreeNode *findLastRight(TreeNode *root)
{
    if(root->right == NULL)
    {
        return root;
    }
    return findLastRight(root->right);
}

TreeNode *helper(TreeNode *root)
{
    if(root->left == NULL)
    {
        return root->right;
    }
    else if(root->right == NULL)
    {
        return root->left;
    }
    TreeNode *rightChild = root->right;
    TreeNode *lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}


TreeNode *deleteNode(TreeNode *root, int key)
{
    if(root == NULL)
        return root;
    if(root->val == key)
    {
        return helper(root);
    }
    TreeNode *dummy = root;
    while(root != NULL)
    {
        if(root->val > key)
        {
            if(root->left != NULL && root->left->val == key)
            {
                root->left = helper(root->left);
                break;
            }
            else
            {
                root = root->left;
            }
        }
        else
        {
            if(root->right != NULL && root->right->val == key)
            {
                root->right = helper(root->right);
                break;
            }
            else
            {
                root = root->right;
            }
        }
    }
    return dummy;
}

/*
MY METHOD
//searching if the node exists first
bool search(TreeNode *root, int key)
{
    while (root != NULL && root->val != key)
    {
        root = (key < root->val) ? root->left : root->right;
    }
    if (root == NULL)
    {
        return false;
    }
    return true;
}

//delete helper function
TreeNode *helperDelete(TreeNode *root, int key)
{
    TreeNode *parent = root, *temp = root;
    TreeNode *curr, *currParent;
    while (temp->val != key)
    {
        parent = temp;
        temp = (key < temp->val) ? temp->left : temp->right;
    }

    // if key is leaf node
    if (temp->left == NULL && temp->right == NULL)
    {
        if (parent->left == temp)
        {
            parent->left = NULL;
            delete temp;
            return root;
        }
        else
        {
            parent->right = NULL;
            delete temp;
            return root;
        }
    }

    // internal node
    // case 1 : node has only right child
    else if (temp->left == NULL && temp->right != NULL)
    {
        currParent = temp;
        curr = temp->right;
        //if node is root
        if (parent == temp)
        {
            root->right = NULL;
            return curr;
        }
        while (curr->left != NULL)
        {
            currParent = curr;
            curr = curr->left;
        }
        if (curr != temp->right)
        {
            swap(temp->val, curr->val);
            if (curr->right != NULL)
            {
                currParent->left = curr->right;
            }
            else
            {
                currParent->left = NULL;
            }
            delete curr;
            return root;
        }
        else
        {
            if (temp == parent->left)
                parent->left = curr;
            else
                parent->right = curr;
            delete temp;
            return root;
        }
    }

    // case 2 : node has only left child
    else if (temp->left != NULL && temp->right == NULL)
    {
        currParent = temp;
        curr = temp->left;
        //if node is root
        if (parent == temp)
        {
            root->left = NULL;
            return curr;
        }
        while (curr->right != NULL)
        {
            currParent = curr;
            curr = curr->right;
        }
        if (curr != temp->left)
        {
            swap(temp->val, curr->val);
            if (curr->left != NULL)
            {
                currParent->right = curr->left;
            }
            else
            {
                currParent->right = NULL;
            }
            delete curr;
            return root;
        }
        else
        {
            if (temp == parent->left)
                parent->left = curr;
            else
                parent->right = curr;
            delete temp;
            return root;
        }
    }

    // case 3 : has both children
    else
    {
        currParent = temp;
        curr = temp->left;
        if (parent != temp)
        {
            while (curr->right != NULL)
            {
                currParent = curr;
                curr = curr->right;
            }
            if (curr != temp->left)
            {
                swap(temp->val, curr->val);
                if (curr->left != NULL)
                {
                    currParent->right = curr->left;
                }
                else
                {
                    currParent->right = NULL;
                }
                delete curr;
                return root;
            }
            else
            {
                if (temp == parent->left)
                {
                    parent->left = curr;
                }
                else
                {
                    parent->right = curr;
                }
                curr->right = temp->right;
                delete temp;
                return root;
            }
        }

        // node to be deleted is root which has both children
        else
        {
            while (curr->right != NULL)
            {
                currParent = curr;
                curr = curr->right;
            }
            if (curr != temp->left)
            {
                swap(temp->val, curr->val);
                currParent->right = NULL;
                delete curr;
                return root;
            }
            else
            {
                curr->right = root->right;
                root->right = NULL;
                delete temp;
                return curr;
            }
        }
    }
    return root;
}

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == NULL)
        return root;
    if (root->left == NULL && root->right == NULL && root->val == key)
        return NULL;
    if (search(root, key))
    {
        root = helperDelete(root, key);
    }
    return root;
}
*/

int main()
{

    return 0;
}