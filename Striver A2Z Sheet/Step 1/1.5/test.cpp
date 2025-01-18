#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long long x=0;
    long long s=0;
    vector <long long> v;
    cout<<"Enter Positive N - ";
    cin>>n;
    for(int j=1;j<=n;j++)
    {
        for(int i=1;i<=sqrt(j);i++)
        {
            if(j%i==0)
            {
                v.push_back(i);
                // x+=i;
                
                if((j/i)!=i)
                {
                    v.push_back(j/i);
                    // x+=(j/i);
                }
            }

        }
        for(auto it : v)
            {
                x+=it;
            }

        s+=x;
        cout<<x<<endl;
    }
    
    // sort(v.begin(),v.end());
    // for(int j=1;j<n;j++)
    //     {
    //         for(auto it : v)
    //         {
    //             x+=it;
    //         }
    //         s+=x;
    //     }
    cout<<endl<<"Sum is : "<<s;

    return 0;
}