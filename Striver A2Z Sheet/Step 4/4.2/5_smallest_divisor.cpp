#include <bits/stdc++.h>
using namespace std;

int smallestDivisor(vector<int> &nums, int threshold)
{
    long long int mid, low, high = INT_MIN, ans = 0;
    low = 1;
    for (auto it : nums)
    {
        if (high < it)
        {
            high = it;
        }
    }
    while (low <= high)
    {
        long long int test = 0;
        mid = (low + high) / 2;
        for (auto it : nums)
        {
            test += ceil((float)it / mid);
        }
        if (test <= threshold)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {8, 4, 2, 3, 1};
    int thresh = 10;
    cout << smallestDivisor(nums, thresh);
}