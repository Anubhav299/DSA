#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t) 
{
    if(s.length()!=t.length())
    {
        return false;
    }
    map<char, char> mpp1,mpp2;
    for (int i = 0; i < s.length(); i++)
    {
        if(mpp1.find(s[i])!=mpp1.end())
        {
            if(mpp1[s[i]]!=t[i])
            {
                return false;
            }
        }
        else
        {
            mpp1[s[i]] = t[i];
        }


        if(mpp2.find(t[i])!=mpp2.end())
        {
            if(mpp2[t[i]]!=s[i])
            {
                return false;
            }
        }
        else
        {
            mpp2[t[i]] = s[i];
        }
    }
    return true;
}

int main()
{
    string s = "bbbaaaba", t = "aaabbbba";    
    cout << isIsomorphic(s, t);
    
    return 0;
}