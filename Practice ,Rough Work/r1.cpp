void findLeaf(Node *root, vector<int> &ans)
{
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }
    if(root->left)
        findLeaf(root->left, ans);
    if(root->right)
        findLeaf(root->right, ans);
}

vector<int> boundaryTraversal(Node *root)
{
    vector<int> ans, rTemp;
    Node *rightTemp = root->right, *leftTemp = root->left;

    if (root == NULL)
        return ans;
        
    ans.push_back(root->data);
    
    if(root->left == NULL && root->right == NULL)   // only one node
        return ans;

    while (leftTemp != NULL)
    {
        if (leftTemp->left || leftTemp->right)
        {
            ans.push_back(leftTemp->data);
        }
        if (leftTemp->left)
        {
            leftTemp = leftTemp->left;
        }
        else
        {
            leftTemp = leftTemp->right;
        }
    }

    findLeaf(root, ans);

    while (rightTemp != NULL)
    {
        if (rightTemp->left || rightTemp->right)
        {
            rTemp.push_back(rightTemp->data);
        }
        if (rightTemp->right)
        {
            rightTemp = rightTemp->right;
        }
        else
        {
            rightTemp = rightTemp->left;
        }
    }
    reverse(rTemp.begin(), rTemp.end());
    copy(rTemp.begin(), rTemp.end(), std::back_inserter(ans));
    return ans;
}
};