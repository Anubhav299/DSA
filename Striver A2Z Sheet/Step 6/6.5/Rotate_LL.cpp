#include <bits/stdc++.h>
using namespace std;

struct ListNode 
{
int val;
ListNode *next;
ListNode() : val(0), next(nullptr) {}
ListNode(int x) : val(x), next(nullptr) {}
ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *rotateRight(ListNode *head, int k)
{
    if (!head || (!head->next))
    {
        return head;
    }
    ListNode *temp = head;
    int n = 0;
    while (temp)
    {
        n++;
        temp = temp->next;
    }
    k = k % n;
    while (k--)
    {
        ListNode *temp = head;
        while (temp->next->next)
        {
            temp = temp->next;
        }
        temp->next->next = head;
        head = temp->next;
        temp->next = NULL;
    }
    return head;
}

int main()
{

    return 0;
}