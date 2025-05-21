#include <bits/stdc++.h>
using namespace std;

vector<int> maxCombinations(int n, int k, vector<int> &a, vector<int> &b)
{
    vector<int> ans;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    priority_queue<pair<int, pair<int, int>>> sumHeap;
    set<pair<int, int>> visited;

    sumHeap.push({a.back() + b.back(), {n - 1, n - 1}});
    visited.insert({n - 1, n - 1});

    while (k--)
    {
        auto top = sumHeap.top();
        int sum = top.first;
        int i = top.second.first;
        int j = top.second.second;

        ans.push_back(sum);
        sumHeap.pop();

        if (visited.find({i - 1, j}) == visited.end())
        {
            sumHeap.push({a[i - 1] + b[j], {i - 1, j}});
            visited.insert({i - 1, j});
        }

        if (visited.find({i, j - 1}) == visited.end())
        {
            sumHeap.push({a[i] + b[j - 1], {i, j - 1}});
            visited.insert({i, j - 1});
        }
    }
    return ans;
}

int main()
{

    return 0;
}