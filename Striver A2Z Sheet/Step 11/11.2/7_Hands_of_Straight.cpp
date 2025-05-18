#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        if (groupSize == 1)
            return true;
        if (hand.size() % groupSize != 0)
            return false;

        int currSize = 0;
        unordered_map<int, int> hashMap;
        for (auto it : hand)
        {
            hashMap[it]++;
        }

        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto it : hashMap)
        {
            minHeap.push(it.first);
        }

        while (minHeap.empty() != true)
        {
            // Skip cards that have already been used up
            while (!minHeap.empty() && hashMap[minHeap.top()] == 0)
            {
                minHeap.pop();
            }
            if (minHeap.empty())
                break;

            int first = minHeap.top();
            for (int i = 0; i < groupSize; i++)
            {
                int next = first + i;
                if (hashMap[next] == 0)
                {
                    return false;
                }
                hashMap[next]--;
            }
        }
        return true;
    }
};

int main()
{

    return 0;
}