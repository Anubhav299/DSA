#include <bits/stdc++.h>
using namespace std;

void maxHeapify(vector<int> &arr, int i)
{
    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < arr.size() && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < arr.size() && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        maxHeapify(arr, largest);
    }
}

void buildMaxHeap(vector<int> &arr, int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
    {
        maxHeapify(arr, i);
    }
}

void convertMinToMaxHeap(vector<int> &arr, int N)
{
    buildMaxHeap(arr, N);
}

int main()
{

    return 0;
}