#include <bits/stdc++.h>
using namespace std;

int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
{
    unordered_map<int, pair<int, int>> hash;
    vector<int> rows(mat.size(), 0), cols(mat[0].size(), 0);
    int row, col;
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            hash[mat[i][j]] = {i, j};
        }
    }
    for (int i = 0; i < arr.size(); i++) {
        row = hash.find(arr[i])->second.first;
        col = hash.find(arr[i])->second.second;
        

        rows[row]++;
        cols[col]++;

        if (rows[row] == mat[0].size() || cols[col] == mat.size()) {
            return i; 
        }
    }
    return -1;
}

int main()
{
    // vector<int> arr = {2, 8, 7, 4, 1, 3, 5, 6, 9};
    // vector<vector<int>> mat = {{3, 2, 5}, {1, 4, 6}, {8, 7, 9}};

    vector<int> arr = {1,3,4,2};
    vector<vector<int>> mat = {{1,4}, {2,3}};
    cout << firstCompleteIndex(arr, mat);

    return 0;
}