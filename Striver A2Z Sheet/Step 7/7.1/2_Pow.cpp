#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n)
{
    double u = x;
    long long nn = n;
    if (nn == 1)        //base case
    {
        return u;
    }
    if (x == 1 || nn == 0)          //edge case
    {
        return 1;
    }
    if (nn < 0)                     //for negative powers
    {
        u = (double)(1 / x);
        nn *= -1;
    }
    if (nn % 2 == 0)                //2^10 gets reduced to 4^5 as (2^2)^5
    {
        u = u * u;
        nn = nn / 2;
    }
    return (double)(u * myPow(u, nn-1));        /*since we are multiplying u with result therefore
                                                reduce nn by one*/
}

int main()
{
    int x = 2, n = 10;
    cout << myPow(x, n);
    return 0;
}