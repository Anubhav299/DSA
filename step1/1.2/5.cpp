#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter Number - ";
    cin>>n;
    for(int i=n;i>=0;i--)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}
