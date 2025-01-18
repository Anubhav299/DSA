#include <bits/stdc++.h>
using namespace std;

struct Node 
{
  int data;
  struct Node * next;
  Node(int x) 
  {
    data = x;
    next = NULL;
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

Node *insertAtEnd(Node *head, int x) 
{
    Node *mover = head;
    Node *temp = new Node(x);
    while(mover->next!=NULL)
    {
        mover = mover->next;
    }
    mover->next = temp;
    return head;
}

int main()
{
    vector<int> arr = {2, 5, 8, 7};
    Node *head = construct(arr);
    Node *temp = insertAtEnd(head, 9);
    while(temp!=NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}