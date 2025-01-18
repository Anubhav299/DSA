#include <bits/stdc++.h>
using namespace std;

int minEatingSpeed(vector<int> &piles, int h)
{
    long long int low, high, mid, ans = 0;
    low = 1;
    high = 0;
    for (auto it : piles)
    {
        if (high < it)
            high = it;
    }
    if (piles.size() == 1)
    {
        if (piles[0] - h == 1)
        {
            return 2;
        }
    }
    while (low <= high)
    {
        long long int reqdtime = 0;

        mid = (low + high) / 2;
        for (auto it : piles)
        {

            reqdtime += ceil((double)it / mid);
        }
        if (reqdtime <= h)
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
    vector<int> piles = {30, 11, 23, 4, 20};
    cout << "Answer is " << minEatingSpeed(piles, 6);
}