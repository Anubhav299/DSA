#include <bits/stdc++.h>
using namespace std;

// better
int rowWithMax1s(vector<vector<int>> &nums)
{
    int maxi = 0, ans = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        vector<int> arr = nums[i];
        int ub = upper_bound(arr.begin(), arr.end(), 1) - arr.begin();
        int lb = lower_bound(arr.begin(), arr.end(), 1) - arr.begin();
        if (maxi < (ub - lb))
        {
            maxi = (ub - lb);
            ans = i;
        }
    }
    return ans;
}

// optimal
int rowWithMax1s(vector<vector<int>> &nums)
{
    int n = nums[0].size();
    int maxi = 0, ans = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        vector<int> arr = nums[i];
        int lb = lower_bound(arr.begin(), arr.end(), 1) - arr.begin();
        if (maxi < (n - lb))
        {
            maxi = (n - lb);
            ans = i;
        }
    }
    return ans;
}

int main()
{

    return 0;
}