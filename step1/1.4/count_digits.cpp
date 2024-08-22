#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cout<<"Enter N - ";
    cin>>N;
    int d=0;
        int num=N;
        int c = 0;
        while(N!=0)
        {
            d=N%10;
            if(d!=0 && num%d==0)
            {
                c++;
            }
            N=N/10;

        }
        cout<<c;
    return 0;
}