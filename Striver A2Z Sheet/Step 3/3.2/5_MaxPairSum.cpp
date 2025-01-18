#include <bits/stdc++.h>
using namespace std;

int maxPairSum(vector<int> &nums)
{
    int left = 0, right = 0;
    int sum = 0, mxsum = 0;
    while (right < nums.size())
    {
        sum += nums[right];
        if (right - left + 1 < 2)
        {
            right++;
        }
        else if (right - left + 1 == 2)
        {
            mxsum = max(sum, mxsum);
            sum -= nums[left];
            left++;
            right++;
        }
    }
    return mxsum;
}

int main()
{
    vector<int> arr = {4, 3, 1, 5, 6};
    cout << maxPairSum(arr);
    return 0;
}