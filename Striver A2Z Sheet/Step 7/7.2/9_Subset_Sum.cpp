#include <bits/stdc++.h>
using namespace std;

void subset(int ind, vector<int> &arr, vector<int> temp, vector<int> &ans, int sum)
{
    if (ind == arr.size())
    {
        ans.push_back(sum);
        return;
    }

    //take
    temp.push_back(arr[ind]);
    sum += arr[ind];
    subset(ind + 1, arr, temp, ans, sum);

    //not take
    temp.pop_back();
    sum -= arr[ind];            //removing the current from sum in order to get other sums as well
    subset(ind + 1, arr, temp, ans, sum);
}

vector<int> subsetSums(vector<int> &arr)
{
    vector<int> ans, a;
    subset(0, arr, a, ans, 0);
    return ans;
}

int main()
{
    
    return 0;
}