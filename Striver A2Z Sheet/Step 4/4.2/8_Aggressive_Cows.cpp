#include <bits/stdc++.h>
using namespace std;

bool canweplace(vector<int> &stalls, int dist, int k)
{
    int n = stalls.size(), last = stalls[0], count = 1;
    for (int i = 1; i < n; i++)
    {
        if ((stalls[i] - last) >= dist)
        {
            last = stalls[i];
            count++;
        }
        if (count >= k)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, x;
        vector<int> stalls;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            stalls.push_back(x);
        }
        int low, high, mid;
        sort(stalls.begin(), stalls.end());
        low = 1;
        high = stalls[n - 1] - stalls[0];
        if (k == 2)
        {
            cout << high;
        }
        else
        {
            while (low <= high)
            {
                mid = (low + high) / 2;

                if (canweplace(stalls, mid, k))
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
            cout << high << endl;
        }
    }

    return 0;
}