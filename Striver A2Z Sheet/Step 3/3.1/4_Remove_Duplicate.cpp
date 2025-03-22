#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) 
{
    int i = 0,n=nums.size();
    for (int j = 1; j < n; j++) 
    {
        if (nums[i] != nums[j]) 
        {
            nums[i + 1] = nums[j];
            i++;
        }
    }
    return (i + 1);
}

int main()
{
    vector<int> nums = {2,2,3,4,4,4,5,6,6,6,7};
    cout << removeDuplicates(nums);
}