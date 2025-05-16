#include <bits/stdc++.h>
using namespace std;

/*
Intuition :
*/

vector<vector<int>> subsets(vector<int> &nums)
{
    int n = nums.size();
    int totalSub = 1 << n;
    vector<vector<int>> ans;
    for (int num = 0; num < totalSub; num++)
    {
        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
            if (num & (1 << i))
            {
                arr.push_back(nums[i]);
            }
        }
        ans.push_back(arr);
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    for (auto itr : subsets(nums))
    {
        for (auto it : itr)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}