#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int> &nums)
{
    int j = 0, size, n = nums.size();
    size = n;
    int row = (1 << n) - 1;
    vector<vector<int>> ans;
    while (j <= row)
    {
        int i = 0;
        int bit = 1;
        vector<int> arr;
        while (i < n)
        {
            int temp = j & bit;
            if (temp)
            {
                arr.push_back(nums[i]);
            }
            bit = bit << 1;
            i++;
        }
        ans.push_back(arr);
        j++;
    }
    return ans;
}

int main()
{

    return 0;
}