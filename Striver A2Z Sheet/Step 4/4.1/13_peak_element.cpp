#include <bits/stdc++.h>
using namespace std;

//Brute Force 
int findPeakElement_Brute(vector<int> &arr)
{
    int n = arr.size(); // Size of array.

    for (int i = 0; i < n; i++)
    {
        // Checking for the peak:
        if ((i == 0 || arr[i - 1] < arr[i]) && (i == n - 1 || arr[i] > arr[i + 1]))
        {
            return i;
        }
    }
    // Dummy return statement
    return -1;
}

//Optimal Approach
int findPeakElement_Optimal(vector<int> &nums)
{
    int n, low, high, mid;
    n = nums.size();

    //Edge Cases
    if (nums[0] > nums[1])
        return 0;
    if (nums[n - 1] > nums[n - 2])
        return n - 1;
    
    low = 1;
    high = n - 2;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if ((nums[mid - 1] < nums[mid]) && (nums[mid] > nums[mid + 1]))     //checks if mid is peak.
        {
            return mid;
        }

        // if we are in left half  
        if (nums[mid - 1] < nums[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

}

int main()
{
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    cout << "Peak is at index : " << findPeakElement_Optimal(nums);
    return 0;
}