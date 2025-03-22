#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, n, low, high, mid, ans, num;
    cout << "Enter Size of Array : ";
    cin >> n;

    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Element : ";
        cin >> num;
        arr.push_back(num);
    }

    cout << "Enter element to be searched : ";
    cin >> x;

    ans = upper_bound(arr.begin(),arr.end(),x)-arr.begin();

    // l4ow = 0;
    // high = n - 1;
    // ans = n;
    // while (low <= high)
    // {
    //     mid = (low + high) / 2;
    //     if (arr[mid] > x)
    //     {
    //         ans = mid;
    //         high = mid - 1;
    //     }
    //     else
    //     {
    //         low = mid + 1;
    //     }
    // }

    cout << "Upper Bound is : " << ans;

    return 0;
}
