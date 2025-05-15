#include <bits/stdc++.h>
using namespace std;

int minBitFlips(int start, int goal)
{
    int count = 0;
    int x = start ^ goal;
    // counting number of set bits
    while (x)
    {
        x = x & (x - 1);
        count++;
    }
    return count;
}

int main()
{

    return 0;
}