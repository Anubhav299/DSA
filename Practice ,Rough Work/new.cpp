#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

class Solution
{
public:
    int lengthAfterTransformations(string s, int t)
    {
        int ans = 0, cnt = 0;
        vector<int> hash(26, 0);
        for (char c : s)
        {
            hash[c - 'a']++;
        }
        cnt = t / 26;
        t = t % 26;
        ans = cnt ? s.length() * (cnt + 1) : s.length();

        cnt = 0;
        // int i = 25;
        // while (t)
        // {
        //     cnt += hash[i];
        //     i--;
        //     t--;
        // }
        for (int i = 25; i > 25 - t; i--)
        {
            cnt = cnt + (hash[i]);
        }
        ans += cnt;
        return ans % mod;
    }
};

int main()
{

    return 0;
}