#include <bits/stdc++.h>
using namespace std;

//Brute Force
int medianBrute(vector<vector<int>> &mat)
{
    vector<int> ans;
    int k = 0;
    for (auto itr : mat)
    {
        for (auto it : itr)
        {
            ans.push_back(it);
        }
    }
    sort(ans.begin(), ans.end());
    k = (ans.size()) / 2;
    return ans[k];
}


//Optimal Approach
int countSmallEqual(vector<vector<int>> arr, int x)
{
    int m = arr.size();
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        cnt += (upper_bound(arr[i].begin(), arr[i].end(), x) - arr[i].begin());
    }
    return cnt;
}

int medianOptimal(vector<vector<int>> &mat)
{
    int low = INT_MAX, high = INT_MIN;
    int m = mat.size(), n = mat[0].size();
    for (int i = 0; i < m; i++)
    {
        low = min(low, mat[i][0]);
        high = max(high, mat[i][n-1]);
    }
    int req = (m * n) / 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int smallEqual = countSmallEqual(mat, mid);
        if(smallEqual <= req)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    vector<vector<int>> arr = {{1, 3, 5}, {2, 6, 9}, {3, 6, 9}};
    cout << medianOptimal(arr);
    return 0;
}