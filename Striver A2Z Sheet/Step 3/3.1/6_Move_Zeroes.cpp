#include <bits/stdc++.h>
using namespace std;

void zeroes(vector<int> &nums)
{
    int n = nums.size();
    int j,k;

    if(n==1)
    {
    }
    else
    {
        j = 0;
        for (int i = 0; i < n; i++)
        {
            if(nums[i]!=0)
            {
                swap(nums[j],nums[i]);
                j++;
            }
        }
    }

    for(auto it:nums)
    {
        cout << it << " ";
    }
}


int main()
{
    vector<int> arr = {0, 0, 0, 1};
    zeroes(arr);
    return 0;
}