#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &arr, int k)
    {

        // unordered_map 'mp' implemented as frequency hash
        // table
        unordered_map<int, int> mp;
        for (int val : arr)
            mp[val]++;

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>, greater<pair<int, int>>>
            pq;

        for (pair<int, int> entry : mp)
        {
            pq.push({entry.second, entry.first});
            if (pq.size() > k)
                pq.pop();
        }

        // store the result
        vector<int> res(k);

        for (int i = k - 1; i >= 0; i--)
        {
            res[i] = pq.top().second;
            pq.pop();
        }

        return res;
    }
};

int main()
{

    return 0;
}