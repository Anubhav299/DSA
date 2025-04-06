#include <bits/stdc++.h>
using namespace std;

void display(vector<int> &arr)
{
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
}

bool isNonDec(vector<int> &nums)
{
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            return false;
        }
    }
    return true;
}

int minimumPairRemoval(vector<int> &nums)
{
    int m = nums.size(), minSum, target = -1, ans = 0;
    if (m == 0 || m == 1 || isNonDec(nums))
        return 0;
    while (isNonDec(nums) != true)
    {
        ans++;
        minSum = INT_MAX;
        int n = nums.size();
        for (int i = n - 1; i > 0; i--)
        {
            if (nums[i] + nums[i - 1] <= minSum)
            {
                target = i;
                minSum = nums[i] + nums[i - 1];
            }
        }
        nums.erase(nums.begin() + target);
        nums.erase(nums.begin() + target - 1);
        nums.insert(nums.begin() + target - 1, minSum);
        display(nums);
    }
    return ans;
}

int main()
{
    vector<int> nums = {2,2,-1,3,-2,2,1,1,1,0,-1};
    cout << minimumPairRemoval(nums);

    // vector<int> arr = {5, 6, 6};
    // cout << isNonDec(arr);
    return 0;
}