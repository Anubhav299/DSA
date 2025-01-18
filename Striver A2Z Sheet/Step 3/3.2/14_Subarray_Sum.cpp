#include <bits/stdc++.h>
using namespace std;

int subarraySum_Brute(vector<int> &nums, int k)
{
    int n = nums.size();
    int sum, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            if (sum == k)
            {
                ++cnt;
            }
        }

    }
    return cnt;
}


int subarraySum_Optimal(vector<int> &nums, int k)
{
    int n = nums.size(); // size of the given array.
    map<int,int> mpp;
    int preSum = 0, cnt = 0;

    mpp[0] = 1; // Setting 0 in the map.
    for (int i = 0; i < n; i++) {
        // add current element to prefix Sum:
        preSum += nums[i];

        // Calculate x-k:
        int remove = preSum - k;

        // Add the number of subarrays to be removed:
        cnt += mpp[remove];

        // Update the count of prefix sum
        // in the map.
        mpp[preSum] += 1;
    }
    return cnt;
}

int main()
{
    vector<int> arr = {1, 1, 1};
    cout << subarraySum_Optimal(arr, 2);
    return 0;
}