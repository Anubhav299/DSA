#include <bits/stdc++.h>
using namespace std;

bool solve(string s)
{
    int i = 0, j = s.length() - 1;
    while (i <= j)
    {
        if (s[i] == s[j])
        {
            i++;
            j--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

string longestPalindrome(string s)
{
    string ans = "";
    int n = s.length(), mxlen = 0;
    if (n == 0)
    {
        return ans;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (solve(s.substr(i, j - i + 1)))
            {
                if ((j - i + 1) > mxlen)
                {
                    ans = s.substr(i, (j - i + 1));
                    mxlen = j - i + 1;
                }
            }
        }
    }
    return ans;
}

int main()
{
    string s = "dbbc";
    cout << longestPalindrome(s);
    return 0;
}