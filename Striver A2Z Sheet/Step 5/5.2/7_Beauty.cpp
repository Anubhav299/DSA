#include <bits/stdc++.h>
using namespace std;

int beautySum(string s)
{
    int beauty = 0, n = s.length();
    for (int i = 0; i < n; i++)
    {   
        vector<int> hash(26, 0);
        int maxf = 0, minf = INT_MAX;
        for (int j = i; j < n; j++)
        {
            hash[s[j] - 'a']++;
            maxf = max(maxf, hash[s[j] - 'a']);

            minf = INT_MAX;
            for (int i : hash)
            {
                if(i>0)
                {
                    minf = min(i, minf);
                }
            }
            
            beauty += (maxf - minf);
        }
        
    }
    return beauty;
}

int main()
{
    string s = "aabcb";
    cout << beautySum(s);
    return 0;
}