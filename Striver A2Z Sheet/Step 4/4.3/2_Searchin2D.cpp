#include <bits/stdc++.h>
using namespace std;


//better approach
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0; i < m; i++)
    {
        if (matrix[i][0] <= target && target <= matrix[i][n - 1])
        {
            int low = 0;
            int high = n;
            while (low <= high)
            {
                int mid = (low + high) / 2;
                if (matrix[i][mid] == target)
                {
                    return true;
                }
                else if (matrix[i][mid] < target)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        else
        {
            continue;
        }
    }
    return false;
}


//optimal approach
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int low = 0, high = (m * n) - 1;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        int row = mid / n;
        int col = mid % n;
        if(matrix[row][col] == target)
        {
            return true;
        }
        else if(matrix[row][col] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return false;
}

int main()
{

    return 0;
}