#include <bits/stdc++.h>
using namespace std;

//brute approach
vector<string> stringMatchingbrute(vector<string>& words) 
{
    int n = words.size(), j = 0;
    set<string> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j || words[i].length() > words[j].length())
            {
            }
            else
            {
                if(words[j].find(words[i]) != string::npos )
                {
                    ans.insert(words[i]);
                }
            }
        }   
    }
    vector<string> res(ans.begin(), ans.end());
    return res;
}

//optimal KMP Method
vector<string> stringMatchingKMP(vector<string>& words)
{
    vector<string> res;
    
}

int main()
{
    vector<string> w = {"leetcoder", "leetcode", "od", "hamlet", "am"};
    for(auto it: stringMatchingKMP(w))
    {
        cout << it << " ";
    }
    return 0;
}