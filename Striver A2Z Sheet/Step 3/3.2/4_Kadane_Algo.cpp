#include <bits/stdc++.h>
using namespace std;

//better approach
// int maxSum(vector<int> &nums)
// {
//     int i, j,n=nums.size(),sum,mxsum=INT_MIN;
//     for (i = 0; i < n; i++)
//     {
//         sum = 0;
//         for (j = i ; j < n; j++)
//         {
//             sum += nums[j];
//             mxsum = max(mxsum, sum);
//         }
//     }
//     return mxsum;
// }

//Kadane's Algo (Optimised Approach)
int maxSumKadane(vector<int> &nums)
{
    int sum = 0, maxi = nums[0];
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if(maxi<sum)
        {
            maxi = sum;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxi;
}

//to find the subarray itself which has the max sum
pair<int, int> maxSumSubarrayKadane(vector<int> &nums)
{
    int sum = 0, start = 0, maxi = nums[0],substart=-1,subend=-1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (sum == 0)
        {
            start = i;
        }
        sum += nums[i];
        if(maxi<sum)
        {
            maxi = sum;
            substart = start;
            subend = i;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return {substart,subend};
} 

int main()
{
    pair<int, int> p;
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    p = maxSumSubarrayKadane(arr);
    for (int i = p.first; i <= p.second; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
