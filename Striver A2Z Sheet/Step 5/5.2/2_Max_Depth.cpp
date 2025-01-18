#include <bits/stdc++.h>
using namespace std;

int maxDepth(string s) 
{
    int i = 0, c = 0, ans = -1;
    while(s[i]!='\0')
    {
        if(s[i]=='(')
        {
            ++c;
            ans = max(c, ans);
        }
        else if(s[i]==')')
        {
            --c;
        }
        i++;
    }
    return ans;
}

int main()
{
    string s = "()(())((()()))";
    cout << maxDepth(s);
    return 0;
}