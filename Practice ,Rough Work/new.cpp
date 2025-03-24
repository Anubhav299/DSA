#include <bits/stdc++.h>
using namespace std;

int median(vector<vector<int>> &mat)
{
    vector<int> ans;
    int k = 0;
    for(auto itr:mat)
    {
        for(auto it: itr)
        {
            ans.push_back(it);
        }
    }
    sort(ans.begin(), ans.end());
    k = (ans.size()) / 2;
    return ans[k];
}

int main()
{
    vector<vector<int>> arr = {{1}, {2}, {3}};
    cout << median(arr);
    return 0;
}