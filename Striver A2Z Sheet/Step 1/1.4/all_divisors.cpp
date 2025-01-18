#include <bits/stdc++.h>
using namespace std;

void sumOfDivisors(int n) 
{
    long long ans = 0;
    
    for (int i = 1; i <= n; i += 1) 
    {
      ans = ans + ((n/i) * i);
      cout<<ans<<endl;
    }
    
    //return ans;
}

int main()


{
    int n;
    long long x=0;
    long long s=0;
    vector <long long> v;
    cout<<"Enter Positive N - ";
    cin>>n;
    // cout<<endl<<"Sum is : "<<x;

    sumOfDivisors(n);
    // if(n<=0)
    // {
    //     cout<<"Invalid Input";
    // }
    // else
    // {
    //     for(int i=1;i<=sqrt(n);i++)
    //     {
    //         if(n%i==0)
    //         {
    //             v.push_back(i);
                
    //             if((n/i)!=i)
    //             {
    //                 v.push_back(n/i);
    //             }
    //         }
    //     }
    // }
    // sort(v.begin(),v.end());
    // // for(int j=1;j<n;j++)
    // //     {
    //         for(auto it : v)
    //         {
    //             x+=it;
    //             cout<<it<<" ";
    //         }
    //         // s+=x;
    //     // }

    return 0;
}