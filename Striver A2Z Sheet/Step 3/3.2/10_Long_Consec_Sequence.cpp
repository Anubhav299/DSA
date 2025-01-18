#include <bits/stdc++.h>
using namespace std;

int longestsequence(vector<int> &nums)
{
    int i = 0,n = nums.size(), ans=1, longest=0;
    set<int> tar(nums.begin(),nums.end());

    //auto itr = next(tar.begin());
    for (auto it = tar.begin(), itr = next(tar.begin()); itr != tar.end(); it++, itr++)
    {

        if(*(itr)-*(it)==1)
        {
            ans++;
        }
        else
        {
            longest = max(longest, ans);
            ans = 1;
        }
    }
    longest = max(longest, ans);
    return longest;
}
int main()
{
    vector<int> arr = {3, 8, 5, 7, 6};
    cout << longestsequence(arr);
    return 0;
}