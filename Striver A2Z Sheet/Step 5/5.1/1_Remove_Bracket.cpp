#include <bits/stdc++.h>
using namespace std;

string removeOuterParentheses(string s)
{
    string ans = "";
    int depth = 0;
    for (char i : s)
    {
        if (i == '(')
        {
            ++depth;
            if (depth >= 2)
            {
                ans += "(";
            }
        }
        else
        {
            --depth;
            if (depth > 0)
            {
                ans += ")";
            }
        }
    }
    return ans;
}

int main()
{
    string s = "(()())(())((()))";
    cout << removeOuterParentheses(s);
    return 0;
}