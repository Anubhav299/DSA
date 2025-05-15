#include <bits/stdc++.h>
using namespace std;

vector<int> replaceWithRank(vector<int> &arr, int N)
{
    vector<int> ranks(N, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < arr.size(); i++)
    {
        pq.push({arr[i], i});
    }

    int value, rank = 0, prev = INT_MIN, index;
    while (pq.empty() != true)
    {
        value = pq.top().first;
        index = pq.top().second;

        if (value != prev)
        {
            ++rank;
        }
        ranks[index] = rank;
        prev = value;
        pq.pop();
    }

    return ranks;
}

int main()
{
    vector<int> arr = {2, 20, 10, 3, 14, 16, 14};
    vector<int> res;
    res = replaceWithRank(arr, arr.size());
    for (auto it : res)
    {
        cout << it << " ";
    }
    return 0;
}