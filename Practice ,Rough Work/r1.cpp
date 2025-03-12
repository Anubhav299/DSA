#include <bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int> &nums)
{
    int n = nums.size();
    vector<int> pre(n, 0);
    vector<int> suf(n, 0);
    int j = n - 1;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            pre[i] = nums[i];
        }
        else
        {
            pre[i] = pre[i - 1] + nums[i];
        }
        if (j == n - 1)
        {
            suf[j] = nums[j];
        }
        else
        {
            suf[j] = suf[j + 1] + nums[j];
        }
        j--;
    }
}

int main()
{
    vector<int> nums = {-1,-1,0,0,-1,-1};
    // cout << pivotIndex(arr);
    int n = nums.size();
    vector<int> pre(n, 0);
    vector<int> suf(n, 0);
    int j = n - 1;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            pre[i] = nums[i];
        }
        else
        {
            pre[i] = pre[i - 1] + nums[i];
        }
        if (j == n - 1)
        {
            suf[j] = nums[j];
        }
        else
        {
            suf[j] = suf[j + 1] + nums[j];
        }
        j--;
    }
    for(auto it:pre)
    {
        cout << it << " ";
    }
    cout << endl;
    for(auto it:suf)
    {
        cout << it << " ";
    }
    return 0;
}