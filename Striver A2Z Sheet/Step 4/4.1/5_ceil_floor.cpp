#include <bits/stdc++.h> 
using namespace std;

pair<int,int> getFloorAndCeil(vector<int> &a, int n, int x)
{
    int f, c, mid, high, low;
    low = 0;
    high = n - 1;
    f = -1;
    c = -1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] >= x)
        {
            c = a[mid];
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }

        if (a[mid] <= x)
        {
            f = a[mid];
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return {f, c};
}

int main()
{
    int k;
    vector<int> v = {3, 4, 4, 7, 8, 10};
    k = 5;
    cout << endl;
    
    cout << getFloorAndCeil(v, v.size(), k).first << " " << getFloorAndCeil(v, v.size(), k).second;
}