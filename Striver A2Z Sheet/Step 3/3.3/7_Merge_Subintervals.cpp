#include <bits/stdc++.h>
using namespace std;


//optimal
/*
Intuition behind this is simple, we sort the intervals and start from the left and for say [a,b] and [c,d]
we encounter that c<=b then we make the interval [a,max(b,d)], and in case c>b then we store the previous one in ans and make a new one which would be [c,d] and so on.
*/
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());
    for (int i = 0; i < intervals.size(); i++)
    {
        int start = intervals[i][0];
        int end = intervals[i][1];
        if (ans.empty())
        {
            ans.push_back({start, end});
        }
        else
        {
            if (start <= ans.back()[1])
            {
                ans.back()[1] = max(end, ans.back()[1]);
            }
            else
            {
                ans.push_back({start, end});
            }
        }
    }
    return ans;
}

int main()
{

    return 0;
}