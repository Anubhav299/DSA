#include <bits/stdc++.h>
using namespace std;

int numRabbits(vector<int> &answers)
{
    int ans = 0, cnt = 0;
    unordered_map<int, int> mpp;
    for (auto it : answers)
    {
        mpp[it]++;
    }
    for (auto it : mpp)
    {
        if (it.first == 0)
        {
            ans += it.second;
        }
        else
        {
            int grp = it.first + 1;
            ans += ((grp)*(ceil((float)it.second/(grp))));
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {};
    cout << numRabbits(arr);
    return 0;
}