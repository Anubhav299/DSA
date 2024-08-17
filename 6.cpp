#include <iostream>
using namespace std;

int main()
{
    int n,i,j,k=1;

    cout<<"Enter Value of n - ";
    cin>>n;
    
    for(i = 1; i <= 5 ; i++)
    {
        for(j = 1; j <=i ; j++)
        {
            if(k%2==0)
            cout<<"0";
            else
            cout<<"1";
            k++;
        }
        cout<<endl;
    }
    return 0;
}