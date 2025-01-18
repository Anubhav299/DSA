#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> res;
    int m = matrix.size(), n = matrix[0].size();
    int left = 0, right = n - 1, top = 0, bottom = m - 1;
    while (left <= right && top <= bottom)
    {
        for (int i = left; i <= right; i++)
        {
            res.push_back(matrix[top][i]);
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            res.push_back(matrix[i][right]);
        }
        right--;

        // if the matrix is a only 1D then top++ would give wrong answer 
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                res.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                res.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    vector<int> result;
    result = spiralOrder(arr);
    for (auto it : result)
    {
        cout << it << " ";
    }
    return 0;
}