 #include <bits/stdc++.h>
using namespace std;

void solve(int ind, vector<int> &candidates, int target, vector<int> &arr, vector<vector<int>> &ans)
{
    if (target == 0)
    {
        ans.push_back(arr);
        return;
    }
    for (int i = ind; i < candidates.size(); i++)
    {
        if (i > ind && candidates[i] == candidates[i - 1]) // i > ind so that it ignores all but first occurence and checking if candidates[i] == candidates[i - 1]
            continue;
        if (candidates[i] > target)
            break;
        arr.push_back(candidates[i]);
        solve(i + 1, candidates, target - candidates[i], arr, ans);
        arr.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> a;
    solve(0, candidates, target, a, ans);
    return ans;
}

int main()
{

    return 0;
}