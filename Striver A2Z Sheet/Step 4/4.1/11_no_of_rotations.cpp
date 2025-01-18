#include <bits/stdc++.h>
using namespace std;

//Brute Force would be to Traverse throught the array and note index of minimum element, so TC : O(N).

//Optimal Appraoch
int findRotations(vector<int> &nums)
{
    int low, mid, high, ans,index=-1;
    low = 0;
    high = nums.size() - 1;
    ans = INT_MAX;
    while (low <= high)
    {
        mid = (high + low) / 2;

        if(nums[low]<=nums[high])
        {
            if(ans>nums[low])
            {
                ans = nums[low];
                index = low;
                break;
            }
        }

        // checking if left part is sorted
        if (nums[low] <= nums[mid])
        {
            if(ans>nums[low])
            {
                ans = nums[low];
                index = low;
            }
            low = mid + 1;
        }
        else
        {
            if(ans>nums[mid])
            {
                ans = nums[mid];
                index = mid;
            }
            high = mid - 1;
        }
    }
    return index;
}

int main()
{
    int ind;
    vector<int> nums = {4,5,6,7,0,1,2,3};
    ind = findRotations(nums);
    cout << "Number of Rotations are : " << ind;
    return 0;
}