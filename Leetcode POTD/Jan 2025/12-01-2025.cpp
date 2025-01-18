#include <bits/stdc++.h>
using namespace std;

//better using stack or vector as extra space

//optimal using constant space
bool canBeValid(string s, string locked) 
{
    int c = 1, n = s.length();
    if((s.length() % 2 == 1) || (locked[0] == 1 && s[0] != '(') || (locked[n - 1] == 1 && s[n - 1] != ')'))
    {
        return false;
    }
    for (int i = 1; i < n - 1; i++)
    {
        if(s[i]=='(')
        {
            ++c;
        }
        else
        {
            --c;
            if (c < 0 && locked[i]!=0)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    string s = "))()))", locked = "010100";
    cout << canBeValid(s, locked);
    return 0;
}