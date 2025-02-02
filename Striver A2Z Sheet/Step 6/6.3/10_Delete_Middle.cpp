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

//my method
ListNode *deleteMiddle(ListNode *head)
{
    if (!head || (!head->next))
    {
        return NULL;
    }
    ListNode *slow = head, *fast = head;
    if (!(fast->next->next))
    {
        slow->next = NULL;
        return slow;
    }

    while (fast->next->next && fast->next->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return head;
}

//striver's method
ListNode *deleteMidNode(ListNode *head)
{
    if(!head || (!head->next))
    {
        return NULL;
    }
    ListNode *slow = head, *fast = head;
    fast = fast->next->next;
    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return head;
}
int main()
{

    return 0;
}