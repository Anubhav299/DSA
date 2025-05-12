#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;
    if (n == INT_MIN)
        return false;
    return ((n & n - 1) == 0);

    // or bakwas tareeka
    /*
    if(num == 0)    return false;
    if(num == INT_MIN)  return false;
    long long n = log2(abs(num));
    if(num^((int)pow(2,n)))
        return false;
    return true;
    */
}

int main()
{

    return 0;
}