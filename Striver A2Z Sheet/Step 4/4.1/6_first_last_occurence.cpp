#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &arr, int n, int x)
{
    int low, high, mid, ans;
    low = 0;
    high = n - 1;
    ans = n;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int upperBound(vector<int> &arr, int n, int x)
{
    int low, high, mid, ans;
    low = 0;
    high = n - 1;
    ans = n;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] > x)
        {
            ans = mid;
            high = mid - 1;
                }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

pair<int, int> firstandlastPosition(vector<int> &arr, int n, int k)
{
    int lb = lowerBound(arr, n, k);
    if (lb == n || arr[lb] != k)
    {
        return {-1, -1};
    }
    return {lb, (upperBound(arr, n, k) - 1)};
}

int main()
{
    int n, k;
    vector<int> v = {3,4,13,13,13,20,40};
    n = v.size();
    k = 13;
    cout << endl;
    cout << firstandlastPosition(v, n, k).first << " " << firstandlastPosition(v, n, k).second;
    // cout<<n;

    return 0;
}