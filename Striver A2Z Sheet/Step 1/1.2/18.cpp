#include <iostream>
using namespace std;

int main()
{
    int n,i,j;

    cout<<"Enter Value of n - ";
    cin>>n;

    for(i=0;i<n;i++)
    {
        //used char as we need the pattern
        for(char j ='E'-i;j<='E';j++)
        {
            cout<<j<<"  ";
            
        }
        cout<<endl;
    }

    return 0;
}