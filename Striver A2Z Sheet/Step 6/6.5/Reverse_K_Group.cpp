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

ListNode *reverse(ListNode *head)
{
    if (!head || !(head->next))
    {
        return head;
    }
    ListNode *newHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

ListNode *findKthNode(ListNode *head, int k)
{
    k -= 1;
    ListNode *temp = head;
    while (k > 0 && temp != NULL)
    {
        k--;
        temp = temp->next;
    }
    return temp;
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *temp = head;
    ListNode *newHead = head;
    ListNode *prevNode = NULL, *newNode;
    while (temp != NULL)
    {
        ListNode *kthNode = findKthNode(temp, k);
        if (kthNode == NULL)
        {
            if (prevNode)
            {
                prevNode->next = temp;
                break;
            }
        }
        newNode = kthNode->next;
        kthNode->next = NULL;
        newHead = reverse(temp);
        if (temp == head)
        {
            head = newHead;
        }
        else
        {
            prevNode->next = kthNode;
        }
        // temp->next = newNode;
        prevNode = temp;
        temp = newNode;
    }
    return head;
}

int main()
{

    return 0;
}