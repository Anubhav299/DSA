#include <bits/stdc++.h>
using namespace std;


//storing in vector and then sorting
string frequencySortVector(string s) 
{
    string ans = "";
    unordered_map<char, int> mpp;
    for (char c : s)
    {
        mpp[c]++;
    }
    vector<pair<char, int>> res;
    for(auto it:mpp)
    {
        res.emplace_back(it.first, it.second);
    }
    sort(res.begin(), res.end(), [](const pair<char, int> a, const pair<char, int> b)
         { return a.second > b.second; });

    for(auto it: res)
    {
        ans += string(it.second, it.first);
    }
    return ans;
}

//using maxHeap (Priority Queue)
string frequencySortPQ(string s) 
{
    string ans = "";
    unordered_map<char, int> mpp;
    for (char c : s)
    {
        mpp[c]++;
    }
    priority_queue<pair<char, int>> res;
    for(auto it:mpp)
    {
        res.push({it.first, it.second});
    }
    while(!res.empty())
    {
        auto t = res.top();
        ans.append(t.second, t.first);
        res.pop();
    }
    return ans;
}

int main()
{
    string s = "tree";
    cout << frequencySortPQ(s);
    return 0;
}