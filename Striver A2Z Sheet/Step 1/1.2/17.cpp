#include <iostream>
using namespace std;

int main()
{
    int n,i,j;
    

    cout<<"Enter Value of n - ";
    cin>>n;

    for(i=0;i<n;i++)
    {
        int breakpoint = ((2*i)+1)/2;
        char k='A';
        for(int j=0;j<n-i-1;j++)
        {
            cout << " ";
        }
        for(int j=1;j<=((2*i)+1);j++)
        {
            cout << k;
            if(j<=breakpoint)
            {k++;}
            else 
            {k--;}
        }
        for(int j=0;j<n-i-1;j++)
        {
            cout << "  ";
        }
        cout<<endl;
    }

    return 0;
}