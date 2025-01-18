#include <bits/stdc++.h>
using namespace std;

bool canConstruct(string s, int k) 
{
    int cnt = 0;
    if(k>s.length())
    {
        return false;
    }
    vector<int> freq(26, 0);
    for(char c:s)
    {
        freq[c - 'a']++;
    }

    for(auto it:freq)
    {
        if(it%2==1)
        {
            ++cnt;
        }
    }
    return cnt <= k;
}

int main()
{
    string s = "true";
    int k = 2;
    cout << canConstruct(s, k);
    return 0;
}