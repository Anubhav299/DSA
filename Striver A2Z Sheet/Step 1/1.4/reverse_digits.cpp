#include <bits/stdc++.h>
using namespace std;

int main()
{

    int x;
    cout<<"Enter X = ";
    cin>>x;
        long int rev;
        int r;
        while(x)
        {
            r=x%10;
            rev=rev*10+r;
            x/=10;
        }
        if(rev<=pow(-2,31)||rev>=(pow(2,31)-1))
        cout<<0;
        else 
        cout<<rev;
    }