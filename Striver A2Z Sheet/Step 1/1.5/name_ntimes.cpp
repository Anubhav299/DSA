#include <bits/stdc++.h>
using namespace std;

void printGfg(int N) 
    {

        if(N==0)
        {
            return;
        }
        cout<<"GFG"<<" ";

        printGfg(N-1);
    }


int main()
{
    int N;
    cout<<"Enter N = ";
    cin>>N;
    printGfg(N);
    return 0;
}