// The title is intentionally written
// actual question is Kth_Largest_Sum_Subarray
/*https://www.naukri.com/code360/problems/k-th-largest-sum-contiguous-subarray_920398?leftPanelTab=0&leftPanelTabValue=PROBLEM*/

#include <bits/stdc++.h>
using namespace std;


/*Intuition : Of all the subarray we need to find the sum which is kth largest
So we start by generating subarrays and summing them up and adding said sums in a minHeap till we reach K
after that the idea is We'll remove those sums which are smaller than the current and since this is a min heap then we'll only have those sums which are kth largest and more and because of minHeap the kth largest will be at the top of the priority_queue*/
int getKthLargest(vector<int> &arr, int k)
{
    int n = arr.size();
    int sum = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];

            if (pq.size() < k)
            {
                pq.push(sum);
            }
            else
            {
                if (sum > pq.top())
                {
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }
    return pq.top();
}

int main()
{

    return 0;
}