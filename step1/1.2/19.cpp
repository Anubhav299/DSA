#include <iostream>
using namespace std;

int main()
{
    int n,i,j,k,spaces=0;
    cout<<"Enter Value of n - ";
    cin>>n;
    
    for(i=0;i<n;i++)
    {   
        //stars
        for(j=0;j<n-i;j++)
        {
            cout<<"*";
        }

        //spaces
        for(k=0;k<spaces;k++)
        {
            cout<<" ";
        }

        //stars
        for(j=n-i;j>0;j--)
        {
            cout<<"*";
        }
        spaces+=2;
        if(i<n-1)
        {
            cout<<endl;
        }
    }

    for(i=0;i<=n;i++)
    {   
        //stars
        for(j=0;j<i;j++)
        {
            cout<<"*";
        }

        //spaces
        for(k=spaces;k>0;k--)
        {
            cout<<" ";
        }

        //stars
        for(j=0;j<i;j++)
        {
            cout<<"*";
        }
        spaces-=2;
        cout<<endl;
    }

    return 0;
}