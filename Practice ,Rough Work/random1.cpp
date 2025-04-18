#include <bits/stdc++.h>
using namespace std;

string makeSequence(string s)
{
    string ans;
    int size = s.length(), cnt = 0;
    if (size == 1)
    {
        return ("1" + s);
    }
    for (int i = 0; i < size; i++)
    {
        cnt = 1;
        while (s[i] == s[i + 1] && i < size - 1)
        {
            cnt++;
            i++;
        }
        ans += (cnt + '0');
        ans += s[i];
    }
    return ans;
}

string countAndSay(int n)
{
    if (n == 1)
        return "1";
    string ans = "1";
    for (int i = 1; i < n; i++)
    {
        ans = makeSequence(ans);
    }
    return ans;
}

int main()
{
    string s = "1";
    cout << countAndSay(4);
    return 0;
}