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

class Solution
{
public:
    void markParent(Node *root, unordered_map<Node *, Node *> &parent_track)
    {
        queue<Node *> q;
        q.push(root);
        while (q.empty() != true)
        {
            Node *curr = q.front();
            q.pop();
            if (curr->left)
            {
                parent_track[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right)
            {
                parent_track[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    Node *findTarget(Node *root, int target)
    {
        if (root == NULL)
            return nullptr; // Base case: empty subtree, target not found

        if (root->data == target)
        {
            return root; // Found the target node
        }

        // Recursively search in the left subtree
        Node *leftSearch = findTarget(root->left, target);
        if (leftSearch)
            return leftSearch; // Found in left subtree

        // If not found in left, search in right subtree
        return findTarget(root->right, target);
    }

    int minTime(Node *root, int target)
    {
        unordered_map<Node *, Node *> parent_track;
        markParent(root, parent_track);

        unordered_map<Node *, bool> visited;
        queue<Node *> q;

        Node *tar = findTarget(root, target);
        q.push(tar);
        visited[tar] = true;

        int result = -1;

        while (q.empty() != true)
        {
            int size = q.size();
            result++;
            for (int i = 0; i < size; i++)
            {
                Node *current = q.front();
                q.pop();
                if (current->left && visited[current->left] != true) // checks if left child exists and isn't visited, then push in queue and visit it
                {
                    q.push(current->left);
                    visited[current->left] = true;
                }
                if (current->right && visited[current->right] != true) // does the same but with right child
                {
                    q.push(current->right);
                    visited[current->right] = true;
                }
                if (parent_track[current] && visited[parent_track[current]] != true) // does the same with parent
                {
                    q.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
        }
        return result;
    }
};

int main()
{

    return 0;
}