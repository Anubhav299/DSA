#include <bits/stdc++.h>
using namespace std;

// same as Brute but with safety checks, so it is a bit better
class Solution
{
public:
    vector<string> res;

    void solve(string &curr, int n, int open, int close)
    {
        if(curr.length() == 2*n)
        {
            res.push_back(curr);
            return;
        }
        if (open < n)
        {
            curr.push_back('(');
            solve(curr, n, open + 1, close);
            curr.pop_back();
        }
        if(close < open)
        {
            curr.push_back(')');
            solve(curr, n, open, close + 1);
            curr.pop_back();
        }
            
    }

    vector<string> validParantheses(int n)
    {
        string s = "";
        int open = 0;
        int close = 0;
        solve(s, n, 0, 0);
        return res;
    }

    void display()
    {
        for(auto it:res)
        {
            cout << it << endl;
        }
    }
};

int main()
{
    Solution s;
    s.validParantheses(3);
    s.display();
    return 0;
}

// Brute of sorts
/*
class Solution
{
public:
    vector<string> res;

    bool isValid(string s)
    {
        int cnt=0;
        for(char c:s)
        {
            if(c=='(')
                ++cnt;
            else
                --cnt;
            if(cnt<0)
                return false;
        }
        return cnt==0;
    }

    void solve(string &curr, int n)
    {
        if(curr.length() == 2*n)
        {
            if(isValid(curr))
                res.push_back(curr);
            return;
        }
        curr.push_back('(');
        solve(curr,n);
        curr.pop_back();

        curr.push_back(')');
        solve(curr,n);
        curr.pop_back();
    }

    vector<string> generateParenthesis(int n)
    {
        string curr = "";
        solve(curr, n);
        return res;
    }
};
*/