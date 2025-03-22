#include <bits/stdc++.h>
using namespace std;

int findMaxIndex(vector<vector<int>> &mat, int m, int n, int col)
{
    int maxVal = -1, ind = -1;
    for (int i = 0; i < m; i++)
    {
        if (mat[i][col] > maxVal)
        {
            maxVal = mat[i][col];
            ind = i;
        }
    }
    return ind;
}

vector<int> findPeakGrid(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int maxRowIndex = findMaxIndex(mat, m, n, mid);
        int left = (mid - 1 >= 0) ? mat[maxRowIndex][mid - 1] : -1;
        int right = (mid + 1 < n) ? mat[maxRowIndex][mid + 1] : -1;
        if (mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid] > right)
        {
            return {maxRowIndex, mid};
        }
        else if (mat[maxRowIndex][mid] < left)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return {-1, -1};
}

int main()
{

    return 0;
}