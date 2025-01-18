#include <bits/stdc++.h>
using namespace std;

int shipWithinDays(vector<int> &weights, int days)
{
    long long int low = INT_MIN, high = 0, mid, ans = 0;
    for (auto it : weights)
    {
        if (low < it)
        {
            low = it;
        }
        high += it;
    }
    if (days == 1)
    {
        return high;
    }

    while (low <= high)
    {
        long long int scap = 0, d = 1;
        mid = (low + high) / 2;
        for (auto it : weights)
        {
            if (scap + it <= mid)
            {
                scap += it;
            }
            else
            {
                d++;
                scap = it;
            }
        }
        if (d <= days)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> weights = {1, 2, 3, 1, 1};
    int d = 4;
    cout << shipWithinDays(weights, d);
    return 0;
}