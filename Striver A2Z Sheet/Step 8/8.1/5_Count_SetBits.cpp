#include <bits/stdc++.h>
using namespace std;

int countSetBits(int n)
{
    if (n == 0)
        return 0;

    int x = log2(n);                                // highest power of 2 upto n
    int tillHighestPow = x * (1 << (x - 1));        // one cycle contains
                                                    // if highest power is x then, one cycle contains x*(2^(x-1)) set bits.

    int msbton = n - (1 << x) + 1;                  // set bits from highest power till n = n - 2^x + 1;
    int rest = n - (1 << x);

    int ans = tillHighestPow + msbton + countSetBits(rest);
    return ans;
}

int main()
{

    return 0;
}