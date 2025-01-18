#include <bits/stdc++.h>
using namespace std;

string largestOddNumber(string num) 
{
    int n = num.length();
    if (num[n - 1] % 2 != 0)
    {
        return num;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (num[i] % 2 != 0)
        {
            return num.substr(0, i + 1);
        }
    }
    return "";
}

int main()
{
    string s = "4026";
    cout << largestOddNumber(s);
    // cout<<s.substr(0, 1);
    return 0;
}