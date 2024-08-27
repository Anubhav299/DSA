#include <bits/stdc++.h>
using namespace std;

long long facto(long long n)
    {
    if(n==1||n==0)
    {
        return 1;
    }
    return n*facto(n-1);
    }


vector<long long> factorialNumbers(long long n) 
    {
        vector <long long> v;
        long long x,i=1;
        while(i!=n)
        {
            x=facto(i);
            if(x>n)
            {
                return v;
            }
            else
            {
                v.push_back(x);
                i++;
            }
            
        }
    }
    

    


int main()
{
    int N;
    cout<<"Enter N = ";
    cin>>N;
    cout<<" is = ";
    for(auto it : factorialNumbers(N))
    {
        cout<<it<<" ";
    }
    
    return 0;
}