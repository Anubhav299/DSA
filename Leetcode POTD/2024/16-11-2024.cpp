#include <bits/stdc++.h>
using namespace std;

vector<int> resultsArray(vector<int>& nums, int k) 
    {
        vector<int> res;
        int i, mx = 0, flag = 1, start = 0, end = 0;
        while (end < nums.size()) 
        {
            flag = 1;
            if ((end - start + 1) < k) 
            {
                end++;
            } 
            else if ((end - start + 1) == k) 
            {
                for (i = start; i < (start + k); i++) 
                {
                    if (nums[i] >= nums[i + 1] && i<end-1)
                    {
                        flag = 0;
                        break;
                    }
                    // mx = max(mx, nums[i]);
                    //cout << nums[i] << "     " <<;
                }
                //cout << endl;
                if(flag == 1)
                {
                    res.push_back(nums[end]);
                }
                else
                {
                    res.push_back(-1);
                }
                // cout << start << "  " << end;
                start++;
                end++;
            }
        }
        return res;
    }

int main()
{
    vector<int> res;
    vector<int> nums = {3,2,3,2,3,2};
    int k = 2;
    res = resultsArray(nums, k);
    for(auto it: res)
    {
        cout << it << " ";
    }
}