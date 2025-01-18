#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    Node(int x)
    {
        data = x;
        next = prev = NULL;
    }
};

Node *addNode(Node *head, int pos, int data)
{
    Node *temp = head;
    Node *newNode = new Node(data);
    int i = 0;
    while (i != pos && temp != NULL)
    {
        i++;
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        newNode->prev = temp;
        temp->next = newNode;
    }
    else
    {
        newNode->prev = temp;
        temp->next->prev = newNode;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    return head;
}

int main()
{

    return 0;
}