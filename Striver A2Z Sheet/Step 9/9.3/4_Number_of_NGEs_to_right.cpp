#include <bits/stdc++.h>
using namespace std;

vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices)
{
    vector<int> ans;
    int cnt = 0;
    for (int i = 0; i < queries; i++)
    {
        cnt = 0;
        for (int j = indices[i] + 1; j < arr.size(); j++)
        {
            if (arr[j] > arr[indices[i]])
            {
                cnt++;
            }
        }
        ans.push_back(cnt);
    }
    return ans;
}

int main()
{

    return 0;
}