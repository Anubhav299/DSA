#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> result;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    int k = 2;

    minHeap.push({4, 1});
    minHeap.push({3, 2});
    minHeap.push({3, 4});

    if (minHeap.size() > k)
    {
        minHeap.pop();
    }

    for (int i = 0; i < k; i++)
    {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }

    for(auto it:result)
    {
        cout << it << " ";
    }
    return 0;
}