#include <bits/stdc++.h>
using namespace std;

// find XOR from 1 to x
// based on observation
int XOR(int x)
{
    if (x % 4 == 1)
        return 1;
    else if (x % 4 == 2)
        return x + 1;
    else if (x % 4 == 3)
        return 0;
    else
        return x;
}

/*
XOR of L to R is equivalent to finding XOR of left and right where left is XOR from 1 to l-1 
whereas right is XOR from 1 to r
then final answer is left ^ right.
*/
int findXOR(int l, int r)
{
    //XOR from L TO R is equivalent to finding left = XOR from 1 to left
    int leftXOR = XOR(l - 1);
    
    //and this is XOR from 1 to R
    int rightXOR = XOR(r);
    return leftXOR ^ rightXOR;
}

int main()
{

    return 0;
}