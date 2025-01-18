#include <bits/stdc++.h>
using namespace std;

//my method
void rotate_matrix_better (vector <vector <int>> &matrix)
{
    int n,x,y;
    n = matrix.size();
    y = n - 1;
    x = 0;

    //swapping ith row with (n-i)th row
    //as in 1st row is swapped with the last row, then second row with the second last row and so on.
    for (int i = 0; i < n/2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            swap(matrix[i][j], matrix[y][j]);
        }
        y--;
    }


    //transposing the matrix but make sure that you don't swap back the elements already swapped.
    for (int i = 0; i < n; i++)
    {
        for (int j = x + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
        x++;
    }
}

void rotate_matrix_optimal (vector <vector <int>> &matrix)
{
    int n;
    n = matrix.size();
    
    //transposing the matrix but make sure that you don't swap back the elements that are already swapped.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
        
    //reversing each row
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
    
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    rotate_matrix_optimal(arr);
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