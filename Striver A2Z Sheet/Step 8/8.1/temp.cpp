#include <bits/stdc++.h>
using namespace std;

int setBit(int num)
{
    int n = num, pos = 0;
    while (n)
    {
        if ((n & 1) == 1)
        {
            pos++;
            n = n >> 1;
        }
        else
        {
            break;
        }
    }

    int x = 1 << pos;
    num = num | x;
    return num;
}

int main()
{

    return 0;
}