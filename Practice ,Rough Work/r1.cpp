#include <bits/stdc++.h>
using namespace std;

class heap
{
    int arr[100];
    int size;

public:
    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int x)
    {
        size = size + 1;
        int index = size;
        arr[size] = x;
        while (index > 1)
        {
            int parentIndex = index / 2;
            if (arr[index] > arr[parentIndex])
            {
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deletefromHeap()
    {
        arr[1] = arr[size];
        size--;

        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = (2 * i) + 1;

            if (leftIndex < size &&arr[i] < arr[leftIndex])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex < size &&arr[i] < arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else
            {
                return;
            }
        }
    }
};

void heapify(int arr[], int n, int i)
{
    int left = 2 * i;
    int right = 2 * i + 1;
    int largest = i;
    if (left < n &&arr[i] < arr[left])
    {
        largest = left;
    }

    if (right < n &&arr[i] < arr[right])
    {
        largest = right;
    }

    if(largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }

}

int main()
{
    heap h;
    h.insert(50);
    h.insert(52);
    h.insert(51);
    h.insert(56);
    h.insert(54);

    h.print();
    
    h.deletefromHeap();
    h.print();

    int arr[6] = {-1, 54, 56, 50, 52, 51};
    int n = 5;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}