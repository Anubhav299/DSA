#include <bits/stdc++.h>
using namespace std;

//Brute Force is Linear Search

//Better Method
int minElementBetter(vector<int> &nums)
{
    int low, mid, high, ans;
    low = 0;
    high = nums.size() - 1;
    ans = INT_MAX;
    while (low <= high)
    {
        mid = (high + low) / 2;
        if (nums[low] <= nums[mid])
        {
            ans = min(nums[low], ans);
            low = mid + 1;
        }
        else
        {
            ans = min(nums[mid], ans);
            high = mid - 1;
        }
    }
    return ans;
}

//Optimal Method
int minElementOptimal(vector<int> &nums)
{
    int low, mid, high, ans;
    low = 0;
    high = nums.size() - 1;
    ans = INT_MAX;
    while (low <= high)
    {
        mid = (high + low) / 2;

        if(nums[low]<nums[high])
        {
            ans = min(nums[low], ans);
            break;
        }

        if (nums[low] <= nums[mid])
        {
            ans = min(nums[low], ans);
            low = mid + 1;
        }
        else
        {
            ans = min(nums[mid], ans);
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int res;
    vector<int> nums = {4, 1, 2, 3, 4, 4, 4};
    res = minElementOptimal(nums);
    cout << endl;
    cout << "Minimum is : " << res;
    return 0;
}
