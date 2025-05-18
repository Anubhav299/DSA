#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<int, int> hashMap;

    priority_queue<int> minHeap;
    minHeap.push(7);
    minHeap.push(7);
    minHeap.push(1);
    minHeap.pop();

    cout << minHeap.top();
    return 0;
}