#include <bits/stdc++.h>
using namespace std;

int countServers(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    int ans = 0;
    vector<int> rsum(m, 0), csum(n, 0);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            rsum[i] += grid[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            csum[i] += grid[j][i];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1 && (rsum[i] > 1 || csum[j] > 1))
            {
                ans++;
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> grid = {{1, 0, 0, 1, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 1, 0}};
    cout << countServers(grid);
    return 0;
}