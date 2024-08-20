#include <iostream>
using namespace std;

int main()
{
    int n,i,j;

    cout<<"Enter Value of n - ";
    cin>>n;
    
    for(i = 1; i <=(2*n)-1 ; i++)
    {
        int stars = i;
        if(i>n) 
        stars = (2*n)-i;
        for(j = 1; j<=stars ; j++)
        {
            cout<<"*";
        }

        cout<<endl;
    }

    return 0;
}