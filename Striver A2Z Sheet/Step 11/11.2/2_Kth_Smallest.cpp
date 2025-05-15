#include <bits/stdc++.h>
using namespace std;

// using Priority Queue
int kthSmallest(vector<int> &nums, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(nums[i]);
    }

    for (int i = k; i < nums.size(); i++)
    {
        if(nums[i]<pq.top())
        {
            pq.pop();
            pq.push(nums[i]);
        }
    }

    return pq.top();
}

// using explicit methods of heap
/*void minHeapify(vector<int> &nums, int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && nums[left] < nums[smallest])
    {
        smallest = left;
    }

    if (right < n && nums[right] < nums[smallest])
    {
        smallest = right;
    }

    if (smallest != i)
    {
        swap(nums[smallest], nums[i]);
        minHeapify(nums, n, smallest);
    }
}

void buildMinHeap(vector<int> &arr, int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
    {
        minHeapify(arr, N, i);
    }
}

int kthSmallest(vector<int> &nums, int k)
{
    int size = nums.size();
    buildMinHeap(nums, size);
    k = k - 1;
    while (k)
    {
        swap(nums[0], nums[size - 1]);
        size--;
        minHeapify(nums, size, 0);
        k--;
    }
    return nums[0];
}
*/

int main()
{

    return 0;
}