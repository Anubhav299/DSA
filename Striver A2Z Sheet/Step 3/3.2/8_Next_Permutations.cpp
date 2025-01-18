#include <bits/stdc++.h>
using namespace std;

vector<int> next_perm(vector<int> &nums)
{
    int index = -1, n = nums.size();
    for (int i = n - 2; i >= 0; i--)
    {
        if(nums[i]<nums[i+1])
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        sort(nums.begin(), nums.end());
        return nums;
    }
    for (int i = n - 1; i >= index; i--)
    {
        if(nums[index]<nums[i])
        {
            swap(nums[index], nums[i]);
            break;
        }
    }

    reverse(nums.begin() + index + 1, nums.end());
    return nums;
}

int main()
{
    vector<int> arr = {1, 6,4,5, 3, 2};
    for(auto it:next_perm(arr))
    {
        cout << it << " ";
    }
    return 0;
}