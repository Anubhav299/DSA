#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
class Solution
{
    vector<int> dp;

public:
    long long int topDown(int n)
    {
        if (dp.size() < n)
        {
            dp.resize(n + 1, -1);
        }
        if (n <= 1)
            return n;

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = (topDown(n - 1) + topDown(n - 2)) % MOD;
    }

    long long int bottomUp(int n)
    {
        if (n <= 1)
            return n;

        long long int prev2 = 0, prev1 = 1, curr = 0;

        for (int i = 2; i <= n; i++)
        {
            curr = (prev1 + prev2) % MOD;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};

int main()
{

    return 0;
}