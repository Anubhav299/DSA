#include <bits/stdc++.h>
using namespace std;

//Brute Force 1 : Check before and after elements to get the result, TC:O(N)
//Brute Force 2 : Using XOR

//Optimal Approach
int singleNonDuplicate(vector<int>& nums) 
    {
        int n = nums.size(), low, high, mid;
        if (n == 1)                             //case with only one element in the array
            return nums[0];
        if (nums[0] != nums[1])                 //checking first two elements
            return nums[0];
        if (nums[n - 1] != nums[n - 2])         //checking last two elements
            return nums[n - 1];

        low = 1;                                //because first element already checked
        high = n - 2;                           //because last element already checked        
        while (low <= high) 
        {
            mid = (low + high) / 2;
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }
            if ((mid % 2 == 1 && nums[mid - 1] == nums[mid]) ||
                (mid % 2 == 0 && nums[mid] == nums[mid + 1]))
                {low = mid + 1;}
            else
            {
                high = mid - 1;
            }
        }
        return -1;
    }

int main()
{
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    cout << "Element that is single is : " << singleNonDuplicate(nums);
    return 0;
}