#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int getCount(struct Node *head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp)
    {
        ++cnt;
        temp = temp->next;
    }
    return cnt;
}

int main()
{
    
    return 0;
}