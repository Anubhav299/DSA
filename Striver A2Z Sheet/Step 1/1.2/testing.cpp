#include <iostream>
using namespace std;

int main()

{
    int n,i,j,k;
    cout<<"Enter Value of n - ";
    cin>>n;
    
    //for number of rows
    for(i=1;i<=n;i++)
    {
        char x='A';
        //for spaces
        for(j=0;j<n-i;j++)
        {
            cout<<" ";
        }

        //for stars
        for(k=0;k<((2*i)-1);k++)
        {
            cout<<x;
            x++;
        }
        cout<<endl;
    }
    return 0;
}