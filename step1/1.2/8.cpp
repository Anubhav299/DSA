#include <iostream>
using namespace std;

int main()

{
    int n,i,j,k;
    cout<<"Enter Value of n - ";
    cin>>n;
    for(i=n;i>0;i--)
    {
        for(j=0;j<n-i;j++)
        {
            cout<<" ";
        }

        for(k=((2*i)-1);k>0;k--)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}