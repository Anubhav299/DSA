#include <bits/stdc++.h>
using namespace std;
class Node 
{
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) 
    {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

Node *deleteNode(Node *head, int x)
{
    Node *temp = head;
    int i = 1;
    if (x == 1)
    {
        head->next->prev = NULL;
        head = head->next;
        return head;
    }
    else
    {
        while (i != (x) && temp != NULL)
        {
            temp = temp->next;
            i++;
        }
        if (temp->next == NULL)
        {
            temp->prev->next = NULL;
            temp->prev = NULL;
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
        }
    }
    return head;
}

int main()
{
    
    return 0;
}

