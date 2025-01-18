#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, n;
    cout << "Enter Array Size : ";
    cin >> n;
    int arr[n];
    cout << "Enter Array Elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (i = 0; i < n; i++)
    {
        j = i;
        while (j > 0 && (arr[j - 1] > arr[j]))
        {
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }

    cout << endl
         << "Sorted Array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}