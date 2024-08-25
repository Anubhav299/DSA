#include <bits/stdc++.h>
using namespace std;

long long printSum(int n)
    {
        long long x=0;
        if(n==0)
        {
            return x;
        }
        x=(n*n*n)+printSum(n-1);
    }


int main()
{
    int N;
    cout<<"Enter N = ";
    cin>>N;
    cout<<printSum(N);
    return 0;
}