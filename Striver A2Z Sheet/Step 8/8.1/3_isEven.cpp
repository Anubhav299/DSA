#include <bits/stdc++.h>
using namespace std;

bool isEven(int n)
{

    int LSB = n%2;
    return 1^LSB;
    
    //or
    //return !(n & 1);
}

int main()
{

    return 0;
}