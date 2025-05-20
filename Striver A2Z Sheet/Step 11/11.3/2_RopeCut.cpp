#include <bits/stdc++.h>
using namespace std;

int minCost(vector<int> &arr)
{
    int ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto it : arr)
    {
        pq.push(it);
    }
    while (pq.size() != 1)
    {
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();

        ans += (x + y);

        pq.push(x + y);
    }
    return ans;
}

int main()
{

    return 0;
}