#include <bits/stdc++.h>
using namespace std;

int maxScore(string s) 
{
    int ones=0,zeroes=0,res=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='1')
        {
            ones++;
        }
    }
    for(int i=0;i<s.length()-1;i++)
    {
        if(s[i]=='0')
        {
            zeroes+=1;
        }
        else
        {
            ones-=1;
        }
        res=max(zeroes+ones,res);
    }
    return res;
}

int main()
{
    string s = "00111";
    cout << maxScore(s);
    return 0;
}