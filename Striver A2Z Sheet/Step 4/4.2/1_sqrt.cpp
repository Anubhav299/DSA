#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter Number : ";
    cin >> n;
    long long int low, mid, high, ans = 0;
    low = 1;
    high = n;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if ((mid * mid) <= n)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << "Answer is " << ans;
    return 0;
}