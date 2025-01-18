#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s)
{
    int ans = 0;
    int n = s.length();
    map<char, int> hash = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    for (int i = 0; i < n; i++)
    {
        if (i + 1 < n && hash[s[i]] < hash[s[i + 1]])
        {
            ans -= hash[s[i]];
        }
        else
        {
            ans += hash[s[i]];
        }
    }
    return ans;
}

int main()
{
    string s = "LVIII";
    cout << romanToInt(s);
    return 0;
}