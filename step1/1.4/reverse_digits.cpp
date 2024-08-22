#include <bits/stdc++.h>
using namespace std;

int main()
{

    int x;
    cout<<"Enter X = ";
    cin>>x;
        int c=0;
        int d,n=0;
        while(x!=0)
        {
            d=x%10;
            n=n*10+d;
            x/=10;
        }
        cout<<n;
    }