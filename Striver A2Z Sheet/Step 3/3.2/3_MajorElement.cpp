#include <bits/stdc++.h>
using namespace std;

// Better Approach
// TC = O(n log n) and SC = O(n)
int majorElement(vector<int> &nums)
{
    int n = nums.size();
    map<int, int> hash;
    for(auto it:nums)
    {
        hash[it]++;
        if(hash[it]>(n/2))
            return it;
    }
    return -1;
}


//more efficient but needs confirmation that there exists a majority element
//TC = O(n) and SC = O(1)
int majorEleOptimised(vector<int> &nums) 
{
    int n = nums.size();
    int cnt = 0, el;
    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
        {
            cnt = 1;
            el = nums[i];
        }
        else if (nums[i] == el)
        {
            ++cnt;
        }
        else
        {
            --cnt;
        }
    }

    //extra step and therefore only used when we don't know whether there exists a majority element or not.

    // int cnt2 = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     if(el==nums[i])
    //     {
    //         ++cnt2;
    //     }
    // }
    // if(cnt2>(n/2))
    // {
    //     return el;
    // }
    return el;
}

int main()
{
    vector<int> arr = {-1, 1, 1, 1, 2, 1};
    cout << majorEleOptimised(arr);
    return 0;
}