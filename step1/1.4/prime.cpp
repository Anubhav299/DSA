#include <bits/stdc++.h>
using  namespace std;

int main()
{

    int N,i,c=0;
    cout<<"Enter Number = ";
    cin>>N;
        if(N>1)
        {
            for(i=2;i<=sqrt(N);i++)
            {
                if(N%i==0)
                {
                    ++c;
                }
            
            }
            if(c==0)
            {
                cout<<"Prime Number";
            }
            else
            {
                cout<<"Not a Prime Number";
            }
        }
        else
        cout<<"Invalid Input";
    return 0;
}
