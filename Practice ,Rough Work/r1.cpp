#include <bits/stdc++.h>
using namespace std;

void rev(string s, int idx)
{
    if(s.length() == idx)
    {
        return;
    }
    rev(s, idx + 1);

    cout << s[idx];
}

int main()
{
    string s = "fedcba";
    rev(s, 0);
    return 0;
}
