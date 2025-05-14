#include <bits/stdc++.h>
using namespace std;

bool isMaxHeap(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int x = arr[i];

        int left = (2 * i) + 1;
        int right = (2 * i) + 2;

        if (left < n && x < arr[left])
        {
            return false;
        }

        if (right < n && x < arr[right])
        {
            return false;
        }
    }
    return true;
}

int main()
{

    return 0;
}