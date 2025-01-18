#include <bits/stdc++.h>
using namespace std;

//variation 1
//generate element at n,r 
int generateNcR(int n,int r)
{
    int res=1;
    for (int i = 0; i < r-1; i++)
    {
        res *= (n - i - 1);
        res /= (i + 1);
    }
    return res;
}


//variation 2
//generate nth row of pascal triangle
vector<int> generate_row(int n)
{
    int res = 1;
    vector<int> ans;
    ans.push_back(1);
    for (int i = 1; i < n; i++)
    {
        res *= (n - i);
        res /= i;
        ans.push_back(res);
    }
    return ans;
}


//variation 3
//generate pascal triangle for n rows
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans;
    for (int i = 1; i <= numRows; i++)
    {
        ans.push_back(generate_row(i));
    }
    return ans;
}


int main()
{
    int n = 5;
    vector<vector<int>> arr = generate(n);
    for (auto it : arr)
    {
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}