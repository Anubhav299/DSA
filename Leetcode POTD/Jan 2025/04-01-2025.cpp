#include <bits/stdc++.h>
using namespace std;

int countPalindromicSubsequence(string s)
{
    int cnt = -1, n = s.length();
    unordered_set<string> res;
    unordered_set<char> left;
    vector<int> right(26, 0);
    left.empty();
    right.empty();
    for (int i = 0; i < n; i++)
    {
        right[s[i] - 'a']++; // storing occurences of character in a Vector
    }

    for (int i = 0; i < n; i++)
    {
        right[s[i] - 'a']--;
        if (right[s[i] - 'a'] == 0)
        {
            right[s[i] - 'a'] = -1;
        }

        for (int j = 0; j < 26; j++)
        {
            char c = 'a' + j;
            if (left.count(c) && right[j] > 0)
            {
                res.insert(string() + s[i] + c);
            }
        }
        left.insert(s[i]);
    }
    return res.size();
}

int main()
{
    string s = "aabcabcaa";
    cout << countPalindromicSubsequence(s);

    return 0;
}