#include <bits/stdc++.h>
using namespace std;

bool rotateString(string s, string goal) 
{
    if(s.length()!=goal.length())       // if length is unequal then cannot be the same string
    {
        return false;
    }
    string ans = s+s;                       //
    if(ans.find(goal)==string::npos)        // checking if goal exists in s+s
    {
        return false;
    }
    return true;
}

int main()
{
    string s = "defdefdefabcabc", g = "defdefabcabcdef";
    cout << rotateString(s, g);
    return 0;
}