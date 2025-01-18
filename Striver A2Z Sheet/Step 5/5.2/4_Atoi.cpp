#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s)
{
    auto pos = find_if_not(s.begin(), s.end(), ::isspace);
    s = string(pos,s.end());

    int i = 0, ans = 0, flag = 1;
    if (s[0]=='-')
    {
        flag = -1;
        i++;
    }
    else if(s[0]=='+')
    {
        flag = 1;
        i++;
    }
    while (s[i] != '\0' && s[i]>='0' && s[i]<='9')
    {
        if(s[i]>='0' && s[i]<='9')
        {
            ans = (ans*10) + (s[i]-'0');
        }
        i++;
    }
    return ans*flag;
}

int main()
{
    string s = "words and 987";
    cout << myAtoi(s);
    return 0;
}