#include <bits/stdc++.h>
using namespace std;

/*
Intuition : Concept of Buckets is used here, We firstly do XOR of all elements
and since only 2 distinct number exist (others are in pairs so their XOR cancels out)
then we know that the final XOR that we have is the XOR of our 2 distinct numbers and they'll be distinct in at least one bit, so we then find the rightmost set bit and make 2 buckets, one where that bit in the element will be set and the other where it'll be unset
After that we traverse over the array and each element gets placed in either one of the buckets and since our 2 elements were distinct therefore they'll for sure be in different buckets, while there may be more than one element in each bucket but they'll always be in pairs so their XOR will cancel them out and we'll only we left with one number in bucket 1 and another in bucket 2. 
These 2 are answers.
*/

vector<int> singleNumber(vector<int> &arr)
{
    int n = arr.size();
    long long xorAll = 0, rightMost = 0;
    for (int i = 0; i < n; i++)
    {
        xorAll ^= arr[i];
    }

    rightMost = (xorAll & (xorAll - 1)) ^ xorAll;
    long long b1 = 0, b2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] & rightMost)
        {
            b1 ^= arr[i];
        }
        else
        {
            b2 ^= arr[i];
        }
    }
    return {(int)b2, (int)b1};
}

int main()
{

    return 0;
}