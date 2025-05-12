#include <bits/stdc++.h>
using namespace std;

bool checkKthBit(int n, int k)
{
    return (n>>k)&1;
    //or
    //return n & ((int)pow(2, k));
}

int main()
{

    return 0;
}