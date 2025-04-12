#include <bits/stdc++.h>
using namespace std;

string preToInfix(string pre_exp)
{
    string c, s = pre_exp;
    stack<string> st;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        c = s[i];
        if ((c >= "a" && c <= "z") || (c >= "A" && c <= "Z"))
        {
            st.push(c);
        }
        else
        {
            string y = st.top();
            st.pop();
            string z = st.top();
            st.pop();
            string temp = "(" + y + c + z + ")";
            st.push(temp);
        }
    }
    return st.top();
}

int main()
{
    
    return 0;
}