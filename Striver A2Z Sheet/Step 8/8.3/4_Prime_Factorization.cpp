#include <bits/stdc++.h>
using namespace std;

/*
Just a bit different from Sieve, here we make a similar array but we find spf (smallest prime factor) for each element in the array

*/

vector<int> findPrimeFactors(int n)
{
    vector<int> spf(n + 1, 0);

    for (int i = 0; i <= n; i++)
    {
        spf[i] = i;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j <= n; j += i)
            {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }

    vector<int> ans;
    while (n != 1)
    {
        ans.push_back(spf[n]);
        n = n / spf[n];
    }

    return ans;
}

int main()
{

    return 0;
}