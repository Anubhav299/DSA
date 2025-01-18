#include <iostream>
using namespace std;

int main()
{
    int n,i,j,k,spaces;
    cout<<"Enter Value of n - ";
    cin>>n;
    spaces = 2*(n-1);
    
    for(i=1;i<=n;i++)
    {   
        //stars
        for(j=0;j<i;j++)
        {
            cout<<"*";
        }

        //spaces
        for(k=0;k<spaces;k++)
        {
            cout<<" ";
        }

        //stars
        for(j=i;j>0;j--)
        {
            cout<<"*";
        }
        spaces -= 2;
            cout<<endl;
    }
    
    spaces=2;

    for(i=n;i>1;i--)
    {   
        //stars
        for(j=1;j<i;j++)
        {
            cout<<"*";
        }

        //spaces
        for(k=1;k<=spaces;k++)
        {
            cout<<" ";
        }

        //stars
        for(j=1;j<i;j++)
        {
            cout<<"*";
        }
        spaces+=2;
        cout<<endl;
    }

    return 0;
}