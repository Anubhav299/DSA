#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;

    Node()
    {
        prev = NULL;
        data = 0;
        next = NULL;
    }

    Node(int value)
    {
        prev = NULL;
        data = value;
        next = NULL;
    }
};

Node *constructDLL(vector<int> &arr)
{
    
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};

    return 0;
}