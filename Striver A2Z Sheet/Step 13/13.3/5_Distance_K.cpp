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


//simply marks the parent of each node possible
void markParent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_track)
{
    queue<TreeNode *> q;
    q.push(root);
    while (q.empty() != true)
    {
        TreeNode *current = q.front();
        q.pop();
        if (current->left)
        {
            q.push(current->left);
            parent_track[current->left] = current;
        }
        if (current->right)
        {
            q.push(current->right);
            parent_track[current->right] = current;
        }
    }
}

/*
the main idea behind this is that we firstly reach the target node and then we start to move towards its parent, left and right child while pushing them in a queue and incrementing dist reached by 1 then we do the same for their respective parent, left and right child while maintaining a visited map where we keep track of which node is visited and in case we encounter that node again, we skip it and move to next.
Watch the intuition part of the video from Striver in case of confusion
*/
vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    unordered_map<TreeNode *, TreeNode *> parent_track; // node -> parent
    markParent(root, parent_track);

    unordered_map<TreeNode *, bool> visited;
    queue<TreeNode *> q;
    q.push(target);
    visited[target] = true;
    int curr_level = 0;
    while (q.empty() != true)
    {
        int size = q.size();
        if (curr_level == k)                //target distance is reached, so stop 
            break;
        curr_level++;
        for (int i = 0; i < size; i++)
        {
            TreeNode *current = q.front();
            q.pop();
            if (current->left && visited[current->left] != true)  //checks if left child exists and isn't visited, then push in queue and visit it
            {
                q.push(current->left);
                visited[current->left] = true;
            }
            if (current->right && visited[current->right] != true) // does the same but with right child
            {
                q.push(current->right);
                visited[current->right] = true;
            }
            if (parent_track[current] && visited[parent_track[current]] != true) //does the same with parent
            {
                q.push(parent_track[current]);
                visited[parent_track[current]] = true;
            }
        }
    }
    vector<int> result;
    while (q.empty() != true)       //in the end, the elements in queue are the required elements, so push them into a vector
    {
        TreeNode *curr = q.front();
        q.pop();
        result.push_back(curr->val);
    }
    return result;
}

int main()
{

    return 0;
}