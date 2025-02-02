#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
long long myPow(long long x, long long n)
{
    if (n == 0)
        return 1;

    long long half = myPow(x, n / 2);
    half = (half * half) % MOD;
    return (n % 2 == 0) ? half : (x * half) % MOD;
}

int countGoodNumbers(long long n)
{
    long long x, y;
    long long e, o = n / 2;
    e = (n + 1) / 2;
    x = (myPow(5, e));
    y = (myPow(4, o));
    return (x * y) % MOD;
}

int main()
{
    int n = 50;
    cout << countGoodNumbers(n);
    return 0;
}