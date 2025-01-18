#include <bits/stdc++.h>
using namespace std;

//better approach
//use hashing and check n/3 frequency

//optimal approach
vector<int> majority(vector<int> nums)
{
    vector<int> ans;
    int cnt1 = 0, cnt2 = 0, el1=INT_MIN, el2=INT_MIN;
    for(auto it:nums)
    {
        if(cnt1==0 && it!=el2)
        {
            cnt1 = 1;
            el1 = it;
        }
        else if(cnt2==0 && it!=el1)
        {
            cnt2 = 1;
            el2 = it;
        }
        else if(it==el1)
        {
            cnt1++;
        }
        else if(it==el2)
        {
            cnt2++;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }

    cnt1 = 0, cnt2 = 0;
    for(auto it:nums)
    {
        if (el1 == it)
            cnt1++;
        if (el2 == it)
            cnt2++;
    }

    int mini = (int)(nums.size()/3) + 1;
    if (cnt1 >= mini)
        ans.push_back(el1);
    if (cnt2 >= mini)
        ans.push_back(el2);
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 2, 3, 2};
    for(auto it:majority(arr))
    {
        cout << it << " ";
    }
    return 0;
}