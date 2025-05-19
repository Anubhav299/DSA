#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n)
{
    if (x == 0 || x == 1)
        return x;
    double ans = 1;

    if (n < 0)
    {
        x = 1 / x;
        ans *= x;
        n = -(n + 1);
    }
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            ans *= x;
            n = n - 1;
        }
        else
        {
            x *= x;
            n /= 2;
        }
    }

    return ans;
}

int main()
{

    return 0;
}