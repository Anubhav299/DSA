#include <bits/stdc++.h>
using namespace std;

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string &s)
{
    string ans = "";
    stack<char> st;
    for (char c : s)
    {

        if (isalpha(c) || isdigit(c))
        {
            ans += c;
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && precedence(c) <= precedence(st.top()))
            {
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}

int main()
{
    string s = "a+b*(c/d)       ";
    cout << infixToPostfix(s);
    return 0;
}