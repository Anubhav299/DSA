#include <bits/stdc++.h>
using namespace std;

// using priority queue
//optimal 
int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(nums[i]);
    }

    for (int i = k; i < nums.size(); i++)
    {
        if (nums[i] > pq.top())
        {
            pq.pop();
            pq.push(nums[i]);
        }
    }

    return pq.top();
}

// using explicit heap methods
/*void maxHeapify(vector<int> &nums, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && nums[left] > nums[largest])
    {
        largest = left;
    }

    if (right < n && nums[right] > nums[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(nums[largest], nums[i]);
        maxHeapify(nums, n, largest);
    }
}

void buildMaxHeap(vector<int> &arr, int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
    {
        maxHeapify(arr, N, i);
    }
}

int findKthLargest(vector<int> &nums, int k)
{
    int size = nums.size();
    buildMaxHeap(nums, size);
    k = k - 1;
    while (k)
    {
        swap(nums[0], nums[size - 1]);
        size--;
        maxHeapify(nums, size, 0);
        k--;
    }
    return nums[0];
}
*/

int main()
{

    return 0;
}