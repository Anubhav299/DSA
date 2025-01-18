#include <bits/stdc++.h>
using namespace std;

int select(int arr[], int i, int n)
{
    int min = i;
    for (int j = i; j < n; j++)
    {
        if (arr[min] > arr[j])
        {
            min = j;
        }
    }
    return min;
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = select(arr, i, n);

        swap(arr[min], arr[i]);
    }
}

int main()
{
    int n;
    cout << "Enter Array Size : ";
    cin >> n;
    int arr[n];
    cout << "Enter Array Elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    selectionSort(arr, n);

    cout << endl
         << "Sorted Array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}