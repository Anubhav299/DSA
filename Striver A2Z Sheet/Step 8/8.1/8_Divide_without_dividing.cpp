#include <bits/stdc++.h>
using namespace std;

/*
The main intuition behind this one is how we convert divisor into powers of 2 and then subtract the max power from the dividend and continue to do so in a loop updating the quotient each time
*/
int divide(int dividend, int divisor)
{
    if (dividend == divisor)
        return 1;
    if (divisor == 1)
        return dividend;

    // since the dividend and divisor can have negative signs, so we need to take care of that as well
    bool sign = true;                                      // true is for positive sign
    if (dividend >= 0 && divisor < 0)
        sign = false;
    else if (dividend <= 0 && divisor > 0)
        sign = false;

    long long n = abs((long long)dividend);
    long long d = abs((long long)divisor);
    unsigned int quotient = 0;

    divisor = d;
    while (n >= d)                      //while dividend is bigger than divisor
    {
        int cnt = 0;
        while (n >= (d << (cnt + 1)))  //getting the highest power of divisor which is smaller than dividend
        {
            cnt++;
        }
        quotient += (1 << cnt);        //quotient is updated each time we iterate
        n -= (d << cnt);               //updating dividend as we subtract highest power of divisor from it
    }

    if (quotient == (1 << 31) && sign == true)    //done because quotient could be larger than range allows
    {
        return INT_MAX;
    }
                                                
    if (quotient == (1 << 31) && sign == false)  //done because quotient could be smaller than range allows
    {
        return INT_MIN;
    }

    return sign ? quotient : -quotient;             //returning quotient according to the sign
}

int main()
{

    return 0;
}