#include <bits/stdc++.h>
using namespace std;

vector<int> leader(vector<int> nums)
{
    vector <int> ans;
    int leader=INT_MIN,n=nums.size();
    for (int i = n-1; i >= 0;i--)
    {
        if(nums[i]>leader)
        {
            leader = nums[i];
            ans.push_back(leader);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    vector<int> arr = {10, 22, 12, 3, 0, 6};
    for(auto it: leader(arr))
    {
        cout << it << " ";
    }
    return 0;
}