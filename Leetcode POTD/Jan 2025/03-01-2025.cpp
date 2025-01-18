#include <bits/stdc++.h>
using namespace std;

int waysToSplitArray(vector<int>& nums) 
{
    long long tsum=0;
    long long lsum = 0,n=nums.size(),splits=0;
    for(auto it:nums)
    {
        tsum+=it;
    }
    for(int i=0;i<n-1;i++)
    {

        lsum += nums[i];
        
        if(lsum>= tsum-lsum)
        {
            ++splits;
        }
    }
    return splits;   
}

int main()
{
    vector<int> arr = {10, 4, -8, 7};
    cout << waysToSplitArray(arr);
    return 0;
}