#include <iostream>
using namespace std;

int main()
{
    int n,i,j;
    char k='A';

    cout<<"Enter Value of n - ";
    cin>>n;

    for(i=1;i<=n;i++)
    {
        char k='A';

        for(j=1;j<=i;j++)
        {
            cout<<k<<"  ";
            k++;
        }
        cout<<endl;
    }

    return 0;
}