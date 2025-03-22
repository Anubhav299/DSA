#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int start, int end)
{
    while (start <= end)
    {
        if (s[start++] != s[end--])
        {
            return false;
        }
    }
    return true;
}

void partitionPalin(string s, int ind, vector<string> &path, vector<vector<string>> &ans)
{
    if (ind == s.size())
    {
        ans.push_back(path);
        return;
    }
    for (int i = ind; i < s.length(); i++)
    {
        if (isPalindrome(s, ind, i))
        {
            path.push_back(s.substr(ind, i - ind + 1));
            partitionPalin(s, i + 1, path, ans);
            path.pop_back();
        }
    }
}

int main()
{
    string s = "aabb";
    vector<string> path;
    vector<vector<string>> ans;
    partitionPalin(s, 0, path, ans);
    for (auto itr : ans)
    {
        for (auto it : itr)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}