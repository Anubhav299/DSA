#include <bits/stdc++.h>
using namespace std;

//better approach
string shiftingLettersBett(string s, vector<vector<int>>& arr) 
{
    vector<int> res(26, 0);
    for (int i = 0; i < arr.size(); i++)
    {
        int left, right, dir;
        left = arr[i][0];
        right = arr[i][1];
        dir = arr[i][2];
        for (int j = left; j <= right; j++)
        {
            if(dir == 0)
            {
                res[s[j] - 'a'] -= 1;
            }
            else
            {
                res[s[j] - 'a'] += 1;
            }
            res[s[j]] %= 26;
        }
    }
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] + (res[s[i] - 'a']) > 'z')
        {
            (res[s[i] - 'a']) -= 26;
        }
        s[i] += res[s[i] - 'a'];
    }
    return s;
}

//optimal approach
string shiftingLettersOpti(string s, vector<vector<int>>& arr) {
    vector<int> operations(s.length(), 0);

    for (int i = 0; i < s.length(); i += 1) {
        
    }
}

int main()
{
    string s = "dztz", ans;
    vector<vector<int>> arr = {{0, 0, 0}, {1, 1, 1}};
    // vector<int> res(26, 0);
    ans = shiftingLettersBett(s, arr);
    cout << ans;
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     int left, right, dir;
    //     left = arr[i][0];
    //     right = arr[i][1];
    //     dir = arr[i][2];
    //     for (int j = left; j <= right; j++)
    //     {
    //         if(dir == 0)
    //         {
    //             res[s[j] - 'a'] -= 1;
    //         }
    //         else
    //         {
    //             res[s[j] - 'a'] += 1;
    //         }
    //         res[s[j]] %= 26;
    //     }
    // }

    // for (int i = 0; i < 26; i++)
    // {
    //     cout << (char)('a' + i) << " " << res[i] << endl;
    // }
    return 0;
}
