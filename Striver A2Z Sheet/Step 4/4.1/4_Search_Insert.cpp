#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r, n, target;
    int ans, mid, high, low;
    vector<int> nums = {1, 3, 5, 6};
    target = 5;
    n = nums.size();
    low = 0;
    high = n - 1;
    ans = n;
    
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (nums[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout<<ans;
    return 0;
}