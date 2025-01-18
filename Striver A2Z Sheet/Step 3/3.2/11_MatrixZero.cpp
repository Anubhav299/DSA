#include <bits/stdc++.h>
using namespace std;

//Better Approach
void setZeroesBetter(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> row(m, 0);
        vector<int> col(n, 0);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    row[i]=1;
                    col[j]=1;
                }
            }
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(row[i]||col[j])
                {
                    matrix[i][j]=0;
                }
            }
        }
    }


//Optimal Approach
void setZeroes_Optimal(vector<vector<int>> &matrix)
{
    // int col[n] = {0}  -> matrix[0][..]
    // int row[m] = {0}  -> matrix[..][0]

    int col0 = 1;
    for (int i = 0; i != matrix.size(); i++)
    {
        for (int j = 0; j != matrix[0].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                // marked i-th row
                matrix[i][0] = 0;

                if (j != 0)
                    // marked j-th col
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    for (int i = 1; i < matrix.size(); i++)
    {
        for (int j = 1; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] != 0)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    if (matrix[0][0] == 0)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            matrix[0][j] = 0;
        }
    }

    if (col0 == 0)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            matrix[i][0] = 0;
        }
    }
}

int main()
{
    vector<vector<int>> arr = {{1, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 1, 1}};
    setZeroes_Optimal(arr);
    for (auto row = 0; row != arr.size(); row++)
    {
        for (auto col = 0; col != arr[0].size(); col++)
        {
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }
    return 0;
}