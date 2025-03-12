#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &candidates, int target, int i, vector<int> &arr, vector<vector<int>> &ans)
{
    if (i == candidates.size())
    {
        if (target == 0)
        {
            ans.push_back(arr);
        }
        return;
    }
    if (candidates[i] <= target)
    {
        arr.push_back(candidates[i]);
        solve(candidates, target - candidates[i], i, arr, ans);
        arr.pop_back();
    }
    solve(candidates, target, i + 1, arr, ans);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> arr;
    solve(candidates, target, 0, arr, ans);
    return ans;
}

int main()
{

    return 0;
}