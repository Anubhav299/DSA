#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, n, low, high, mid, flag = 0;
    cout << "Enter Size of Array : ";
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter Element : ";
        cin >> arr[i];
    }

    cout << "Enter element to be searched : ";
    cin >> x;

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else if (arr[mid] > x)
        {
            high = mid - 1;
        }
        else
        {
            flag = 1;
            break;
        }
    }

    if (flag == 1)
    {
        cout << "Element found at : " << mid + 1;
    }
    else
    {
        cout << "Element not found.";
    }

    return 0;
}