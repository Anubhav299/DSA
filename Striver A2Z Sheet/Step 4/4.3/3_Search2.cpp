#include <bits/stdc++.h>
using namespace std;

//better approach                  TC:O(m*log(n))
bool searchMatrixbetter(vector<vector<int>> &matrix, int target)
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

//optimal approach                    TC: O(m+n)
bool searchMatrixoptimal(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int row = 0, col = n - 1; // we start with the minor diagonal top element(topmost right element)
                             /*we compare element with target and reduce row or col accordingly as
                               from the starting element when we go left in row the numbers decrease in magnitude whereas as we go down in column the numbers increase in magnitude
                               so we end up finding the numbers by eliminating row and col accordingly
                             */ 

    while (row < m && col >= 0)         
    {
        if (matrix[row][col] == target)
        {
            return true;
        }
        else if (matrix[row][col] < target)
        {
            row++;
        }
        else
        {
            col--;
        }
    }
    return false;
}

int main()
{

    return 0;
}