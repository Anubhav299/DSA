#include <bits/stdc++.h>
using namespace std;

int minimumLength(string s)
{
    int ans=0;
    unordered_map<char,int> mpp;
    for(char c : s)
    {
        mpp[c]++;
    }

    for(auto it:mpp)
    {
        if(it.second>2)
        {
            if(it.second%2==0)
            {
                it.second = 2;
            }
            else
            {
                it.second = 1;
            }
        }
        else
        {
        }
        ans += it.second;
    }
    return ans;
}

int main()
{
    string s = "aa";
    cout << minimumLength(s);
    return 0;
}