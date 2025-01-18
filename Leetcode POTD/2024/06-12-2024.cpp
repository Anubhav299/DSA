// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int maxCount(vector<int>& banned, int n, int maxSum) 
    {
        int sum=0,occ=0;
        if (banned.size() == 1 && banned[0] > n && (n * (n + 1)) / 2 <= maxSum) 
            {
            return n;
            } 
        else 
        {
        set <int> s;
        for(auto it:banned)
        {
            if(it<=n)
            {
                s.insert(it);
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(s.find(i)==s.end() && (sum+i <= maxSum))
            {
                sum += i;
                occ += 1;
            }
        }

        return occ;
        }
    }


int main() 
{
    vector <int> banned = {1,2,3,4,5,6,7};
    int mxsum = 1;
    int n = 8;
    int mx = 0,occ=0,sum=0;
    if(banned.size()==1 && banned[0]>n && (n*(n+1))/2 <= mxsum)
    {
        cout<<"Answer is : "<<n;
        
    }

    else 
    {
        set <int> s;
        for(auto it:banned)
        {
            if(it<n)
            {
                s.insert(it);
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(s.find(i)==s.end() && sum<=mxsum)
            {
                sum += i;
                occ += 1;
                mx = max(mx, occ);
            }
        }
        // int i = 0;
        // while(sum<=mxsum)
        // {
        //     sum += v[i++];
        // }
        
        cout << "Answer is ™: "<<mx-1;
        // for(auto it:s)
        // {
        //     cout << it << " ";
        // }
    }
    
    return 0;
}