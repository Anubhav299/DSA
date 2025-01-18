#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long x,y,lcm,gcd=1;
    cout<<"Enter X = ";
    cin>>x;
    cout<<"Enter Y = ";
    cin>>y;
    cout<<endl<<"GCD of  "<<x<<" and "<<y<<" is = ";
    while(x!=y)
    {
        if(x>y)
        {
            x-=y;
        }
        else
        {
            y-=x;
        }
    }
    gcd=x;
    cout<<gcd<<endl;

    return 0;
}