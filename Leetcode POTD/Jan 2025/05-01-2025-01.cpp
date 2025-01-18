#include <bits/stdc++.h>
using namespace std;

//short method
string shiftingLettersOpti(string s, vector<int>& shifts) 
{
    long long sum = 0, n = shifts.size();
    string ans;
    for (int i = n-1; i >= 0; i--)
    {
        sum += shifts[i];
        s[i] = 'a' + (s[i] - 'a' + sum) % 26;
    }
    return s;
}

//my method (long)
string shiftingLetters(string s, vector<int>& shifts) 
{
    int n = s.length();              // length of string is same as size of shifts
    string ans="";
    long long tshift = 0, lshift = 0;
    for(auto it:shifts)
    {
        it %= 26;
        tshift += it;
    }
    for (int i = 0; i < n; i++)
    {
        char ch;
        long long target = tshift - lshift;
        target %= 26;
        if(s[i] + target > 'z')
        {
            target -= 26;
        }
        ch = s[i] + target;
        lshift += shifts[i];
        lshift %= 26;
        ans += ch;
    }
    return ans;
}

int main()
{
    string str = "zvhez";
    vector<int> sh = {10,16,10,26,26};
    string res = shiftingLettersOpti(str, sh);
    cout << res;
    return 0;
}