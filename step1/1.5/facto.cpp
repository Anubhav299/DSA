#include <bits/stdc++.h>
using namespace std;

long long facto(long long n)
{
    if(n==1||n==0)
    {
        return 1;
    }
    return n*facto(n-1);
}

int main()
{
    int N;
    cout<<"Enter N = ";
    cin>>N;
    cout<<"Factorial is = ";
    cout<<facto(N);
    
    return 0;
}