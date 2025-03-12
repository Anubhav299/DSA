#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> arr = {3, 1, 2};
    void solve(int ind, vector<int> &subs)
    {
        if (ind >= arr.size())
        {
            for (auto it : subs)
            {
                cout << it << " ";
            }
            cout << endl;
            return;
        }

        subs.push_back(arr[ind]);
        solve(ind + 1, subs);
        subs.pop_back();
        solve(ind + 1, subs);
    }
};

int main()
{
    vector<int> v;
    Solution s;
    s.solve(0, v);
    return 0;
}