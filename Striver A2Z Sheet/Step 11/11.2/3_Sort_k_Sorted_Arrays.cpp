#include <bits/stdc++.h>
using namespace std;


/*Intuition : 
Since the given arrays are sorted in themselves so, we'll take advantage of that.
We start by maintaining a minHeap but we not only store the first element of all arrays but also their row and column since it is a 2D Matrix of sorts
Now since we had taken a minHeap so the minimum element among all elements will be at the top, so we start to store that in the result array and we check if the topmost element has elements after that, if yes we push them into the minHeap otherwise we don't and continue this till the minHeap gets empty.
*/
// optimal method
typedef tuple<int, int, int> HeapElement;
vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    priority_queue<HeapElement, vector<HeapElement>, greater<HeapElement>> minHeap;

    for (int i = 0; i < k; i++)
    {
        if (!kArrays[i].empty())
        {
            minHeap.push(make_tuple(kArrays[i][0], i, 0)); // Use make_tuple for compatibility
        }
    }

    vector<int> res;

    while (!minHeap.empty())
    {
        HeapElement top = minHeap.top();
        minHeap.pop();

        int val = get<0>(top);
        int row = get<1>(top);
        int col = get<2>(top);

        res.push_back(val);

        if (col + 1 < kArrays[row].size())
        {
            minHeap.push(make_tuple(kArrays[row][col + 1], row, col + 1));
        }
    }

    return res;
}

// better method but not efficient since we don't use the fact that each given array is sorted
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

void buildMaxHeap(vector<int> &arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxHeapify(arr, n, i);
    }
}

vector<int> mergeKArrays(vector<vector<int>> nums, int k)
{
    vector<int> arr;
    for (auto itr : nums)
    {
        for (auto it : itr)
        {
            arr.push_back(it);
        }
    }

    int size = k * k;
    buildMaxHeap(arr, size);

    for (int i = size - 1; i >= 1; i--)
    {
        swap(arr[0], arr[i]);
        size--;
        maxHeapify(arr, size, 0);
    }
    return arr;
}
*/
int main()
{

    return 0;
}