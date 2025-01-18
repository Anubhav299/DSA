#include <bits/stdc++.h>
using namespace std;

//Brute Force Approach
int stockBrute(vector<int> &nums)
{
    map<int, int> prof;
    int n = nums.size(),res=0,mx=0,best=0;
    for (int i = 0; i < n; i++)
    {
        mx = 0, res = 0;
        for (int j = i + 1; j < n; j++)
        {
            res = nums[j] - nums[i];
            mx = max(mx, res);
        }
        prof[nums[i]] = mx;
    }
    for(auto it:prof)
    {
        best = max(best, it.second);
    }
    return best;
}

//Optimised Approach
int stockOptimised(vector<int> &nums)
{
        int mini = nums[0], prof = 0, cost = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            cost = nums[i] - mini;
            prof = max(prof, cost);
            mini = min(nums[i], mini);
        }
        return prof;
}

int main()
{
    vector<int> arr = {47, 77, 14, 8, 0, 78, 42, 70, 67, 23 };
    cout << stockOptimised(arr);
    return 0;
}