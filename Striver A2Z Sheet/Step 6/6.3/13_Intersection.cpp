#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


//brute : can use hashing


//optimal : 
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (!headA || !headB)
    {
        return NULL;
    }
    ListNode *temp1 = headA, *temp2 = headB;
    while (temp1 || temp2)
    {

        if (!temp1)
        {
            temp1 = headB;
        }
        if (!temp2)
        {
            temp2 = headA;
        }
        if (temp1 == temp2)
        {
            return temp1;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return NULL;
}

int main()
{

    return 0;
}