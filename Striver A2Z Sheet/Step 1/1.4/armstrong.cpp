#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,num,r,arm=0;
    cout<<"Enter Number = ";
    cin>>n;
        num=n;
        while(n!=0)
        {
            r=n%10;
            arm+=(pow(r,3));
            n/=10;
        }
        cout<<arm;
        if(arm==num)
        {
            cout<<"true";
        }
        else
        {
            cout<<"false";
        }
    return 0;
}   