#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *construct(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    Node *temp;
    for (int i = 1; i < arr.size(); i++)
    {
        temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
int main()
{
    vector<int> arr = {2, 5, 8, 7};
    Node *temp = construct(arr);
    while(temp!=NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}