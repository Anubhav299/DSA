#include <bits/stdc++.h>
using namespace std;

// Better Method with TC : O(n*log n + n/3)
//here we sort the array 
int singleNumber(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 1; i < n; i += 3)
    {
        if (nums[i] != nums[i - 1])
        {
            return nums[i - 1];
        }
    }
    return nums[n - 1];
}

// Brute Force with TC : O(32*N)
int singleNumber(vector<int> &nums)
{
    int cnt, ans = 0;
    for (int i = 0; i <= 31; i++)           //checking each bit that could be
    {
        cnt = 0;
        for (auto it : nums)
        {
            if (it & (1 << i))
            {
                cnt++;
            }
        }
        if (cnt % 3 == 1)
        {
            ans = ans | (1 << i);
        }
    }
    return ans;
}

int main()
{

    return 0;
}