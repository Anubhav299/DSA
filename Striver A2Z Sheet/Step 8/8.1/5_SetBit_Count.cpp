#include <bits/stdc++.h>
using namespace std;

void bitManipulation(int num, int i)
{
    cout << ((num >> (i - 1)) & 1) << " ";      //checking ith bit (1-based indexing that's why (i-1))

    cout << ((num) | (1 << (i - 1))) << " ";    //setting the ith bit in the num
    
    cout << ((num) & (~(1 << (i - 1))));        //clearing the ith bit in the num
}

/*

void bitManipulation(int num, int i)
{
    cout << ((num >> (i - 1)) & 1);

    int n = 1 << (i - 1);
    num = num | n;
    cout << " " << num;

    n = ~(n);
    num = num & n;
    cout << " " << num;
}
*/

int main()
{

    return 0;
}