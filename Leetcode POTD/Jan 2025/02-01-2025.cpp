#include <bits/stdc++.h>
using namespace std;

vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
{
    vector<int> ans;
    char ch, chr;
    int c = 0, d = 0;
    int arr[words.size()] = {0};
    for (auto i = 0; i < words.size(); i++)
    {
        ch = words[i][0];
        chr = words[i][words[i].length() - 1];
        if ((ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') && (chr == 'a' || chr == 'e' || chr == 'i' || chr == 'o' || chr == 'u'))
        {
            ++c;
        }
        arr[i] = c;
    }

    for (int i = 0; i < queries.size(); i++)
    {

        if (queries[i][0] == 0)
        {
            ans.push_back(arr[queries[i][1]]);
        }
        else
        {
            d = arr[queries[i][1]] - arr[queries[i][0] - 1];
            ans.push_back(d);
        }
    }
    return ans;
}

int main()
{
    vector<string> w = {"a", "e", "i"};
    vector<vector<int>> q = {{0, 2}, {0, 1}, {2, 2}};
    for (auto it : vowelStrings(w, q))
    {
        cout << it << " ";
    }
    return 0;
}