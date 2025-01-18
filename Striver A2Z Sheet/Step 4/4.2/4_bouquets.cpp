#include <bits/stdc++.h>
using namespace std;

int minDays(vector<int> &bloomDay, int m, int k)
{
    long long int ans = 0, bqts = 0, mid, n, cnt = 0;
    long long int low = INT_MAX;
    long long int high = INT_MIN;
    n = bloomDay.size();
    if (((long)m * (long)k) > n)
    {
        return -1;
    }

    for (auto it : bloomDay)
    {
        if (low > it)
        {
            low = it;
        }
        if (high < it)
        {
            high = it;
        }
    }

    while (low <= high)
    {
        cnt = 0;
        bqts = 0;
        mid = (low + high) / 2;
        for (auto it : bloomDay)
        {
            if (it <= mid)
            {
                cnt++;
            }

            else
            {
                bqts += (cnt / k);
                cnt = 0;
            }
        }
        bqts += (cnt / k);

        if (bqts >= m)
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
    vector<int> bloomDay = {7, 7, 7, 7, 12, 7, 7};
    int m = 2, k = 3;
    cout << minDays(bloomDay, m, k);
}