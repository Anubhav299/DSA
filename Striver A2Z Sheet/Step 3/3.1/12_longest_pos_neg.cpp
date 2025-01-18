#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> &nums, int k)
{
    long long left = 0, right = 0;
    long long sum = nums[0];
    int maxlen;
    int n = nums.size();
    while (right < n)
    {
        while (left <= right && sum > k)
        {
            sum -= nums[left];
            left++;
        }
        if (sum == k)
        {
            maxlen = max(maxlen, right - left + 1);
        }
        right++;
        if (right < n)
        {
            sum += nums[right];
        }
    }
    return maxlen;
}


int main()
{
    vector<int> arr = {};
    cout << longestSubarray(arr, 1);
}