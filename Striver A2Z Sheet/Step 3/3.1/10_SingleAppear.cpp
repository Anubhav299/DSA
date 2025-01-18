#include <bits/stdc++.h>
using namespace std;

int singleappear(vector <int> &nums)
{
    int ans = 0;
    for(auto it:nums)
    {
        ans ^= it;
    }
    return ans;
}


int main()
{
    vector<int> arr = {2, 2, 1, 1, 6, 6, 5, 7, 7};
    cout << singleappear(arr);
    return 0;
}