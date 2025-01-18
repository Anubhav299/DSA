#include <bits/stdc++.h>
using namespace std;

// brute approach - 3 loops, i = 0, j = i + 1, k = j + 1 then if sum = 0 add in vector and sort it then store in a set

// better approach - 2 loops and the formula that nums[i]+nums[j]+nums[k]=0,
// so we'll find nums[k] = -(nums[i]+nums[j]) and then
vector<vector<int>> threeSumBetter(vector<int> &nums)
{
}

// optimal approach
vector<vector<int>> threeSumOPTIMAL(vector<int> &nums)
{
    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                while (j < k && nums[j] == nums[j - 1])
                {
                    j++;
                }
                while (j < k && nums[k] == nums[k + 1])
                {
                    k--;
                }
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = threeSumOPTIMAL(arr);
    for (auto it : res)
    {
        for (auto itr : it)
        {
            cout << itr << " ";
        }
        cout << endl;
    }
    return 0;
}