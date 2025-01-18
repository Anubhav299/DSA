#include <bits/stdc++.h>
using namespace std;

// used to find 
int findMaxConsecutiveOnes(vector<int> &nums)
{
    int mxcnt = 0, cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if(nums[i]==1)
        {
            ++cnt;
        }
        else
        {
            cnt = 0;
        }
        mxcnt = max(mxcnt, cnt);

    }
    return mxcnt;
}

int main()
{
    vector<int> arr = {1, 0, 1, 1, 0, 1};
    cout << "Max Consecutive 1s are : " << findMaxConsecutiveOnes(arr);
}