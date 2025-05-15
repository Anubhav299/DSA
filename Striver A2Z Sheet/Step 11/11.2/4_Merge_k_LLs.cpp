#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//custom comparator
class compare
{
public:
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int k = lists.size();

        if (k == 0)
            return nullptr;
        priority_queue<ListNode *, vector<ListNode *>, compare> minHeap;
        for (int i = 0; i < k; i++)
        {
            if (lists[i] != NULL)
                minHeap.push(lists[i]);
        }

        ListNode *head = NULL;
        ListNode *tail = NULL;
        while (!minHeap.empty())
        {
            ListNode *top = minHeap.top();
            minHeap.pop();

            if (top->next != NULL)
            {
                minHeap.push(top->next);
            }

            if (head == NULL) // answer LL is empty
            {
                head = tail = top;
            }
            else // insert in answer LL
            {
                tail->next = top;
                tail = tail->next;
            }
        }
        return head;
    }
};

int main()
{

    return 0;
}