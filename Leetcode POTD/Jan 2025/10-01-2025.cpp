#include <bits/stdc++.h>
using namespace std;

vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
{
    char c;
    vector<string> ans;
    unordered_map<int, int> temp1;
    vector<int> wd2(26, 0);                                                // combined hashmap for words2
    vector<int> wd1(26, 0);

    for (int i = 0; i < words2.size(); i++)
    {
        temp1.clear();
        for (int j = 0; j < words2[i].length(); j++)
        {
            temp1[words2[i][j] - 'a'] += 1;
            wd2[words2[i][j] - 'a'] = max(temp1[words2[i][j] - 'a'], wd2[words2[i][j] - 'a']);
        }
    }

    for (int i = 0; i < words1.size(); i++)
    {
        // wd1.clear();
        vector<int> wd1(26, 0);
        int flag = 1;
        for (int j = 0; j < words1[i].length(); j++)
        {
            c = words1[i][j];
            wd1[c - 'a']++;
        }
        for (int i = 0; i < wd2.size(); i++)
        {
            if (wd2[i] > 0)
            {
                if (wd2[i] > wd1[i])
                {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag==1)
        {
            ans.push_back(words1[i]);
        }
    }
    return ans;
}

int main()
{
    vector<string> w1, w2;
    w1 = {"amazon", "apple", "facebook", "google", "leetcode"};
    w2 = {"e", "o"};
    for (auto it : wordSubsets(w1, w2))
    {
        cout << it << endl;
    }
    return 0;
}