#include <bits/stdc++.h>
using namespace std;

// brute approach - 4 loops, i = 0, j = i + 1, k = j + 1, l = k + 1 then if sum = 0 add in vector and sort it then store in a set

// better approach 

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> ans;
    int k, l, n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        

        for (int j = i + 1; j < nums.size(); j++)
        {
            if(j>(i+1) && nums[j]==nums[j-1])
                continue;
            k = j + 1;
            l = n - 1;
            while (k < l)
            {
                long long sum = nums[i] + nums[j];
                     +nums[k] + nums[l];
                if (sum < target)
                {
                    k++;
                }
                else if (sum > target)
                {
                    l--;
                }
                else
                {
                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    k++;
                    l--;
                    while (k < l && nums[k] == nums[k - 1])
                    {
                        k++;
                    }
                    while (k < l && nums[l] == nums[l + 1])
                    {
                        l--;
                    }
                }
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    for(auto it:fourSum(arr,target))
    {
        for(auto itr : it)
        {
            cout << itr << " ";
        }
        cout << endl;
    }
    return 0;
}