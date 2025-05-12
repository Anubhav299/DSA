#include <bits/stdc++.h>
using namespace std;

void findSubset(int ind, vector<int> &nums, vector<int> &arr, vector<vector<int>> &ans)
{
    ans.push_back(arr);
    for (int i = ind; i < nums.size(); i++)
    {
        if (i != ind && nums[i] == nums[i - 1])
        /*checking if current element is same as previously picked one and i!=ind makes sure that we do get the first occurence like [1,2,2] so we get [2,2]*/
            continue;
        arr.push_back(nums[i]);
        findSubset(i + 1, nums, arr, ans);
        arr.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> arr;
    findSubset(0, nums, arr, ans);
    return ans;
}

int main()
{

    return 0;
}