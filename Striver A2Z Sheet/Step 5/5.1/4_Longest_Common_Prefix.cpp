#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) 
{

    string ans = "";
    for (int i = 0; i < strs[0].length();i++)
    {
        char c = strs[0][i];
        for (int j = 1; j < strs.size(); j++)
        {
            if(strs[j][i] != c || i>=strs[j].length())
            {
                return ans;
            }
        }
        ans += c;
    }
    return ans;
}

int main()
{
    vector<string> arr = {"flower", "flow", "flowerpot", "flows", "flank", "flex"};
    cout << longestCommonPrefix(arr);
    return 0;
}