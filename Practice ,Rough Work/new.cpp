#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int> &nums)
{
    int numElements = nums.size();                       // Number of elements in the input array
    int totalCombinations = (1 << numElements) - 1;      // Total number of combinations (2^n - 1)

    vector<vector<int>> allSubsets;                      // Result vector to store all subsets
    int curr = 0;                                        // This will iterate through all bitmasks

    while (curr <= totalCombinations)
    {
        int index = 0;                                   // Index to iterate through nums
        int bitMask = 1;                                 // Bitmask to check each bit
        vector<int>
            currentSubset;                               // Temporary vector to hold current subset

        while (index < numElements)
        {
            // If the bit at position 'index' is set in curr, include nums[index]
            if (curr & bitMask)
            {
                currentSubset.push_back(nums[index]);
            }

            bitMask = bitMask << 1;                       // Shift bitMask to check next bit
            index++;
        }

        allSubsets.push_back(currentSubset);              // Add the formed subset to the result
        curr++;                                           // Move to the next bitmask
    }

    return allSubsets;
}


int main()
{
    vector<int> nums = {1, 2, 3};
    for (auto itr : subsets(nums))
    {
        for (auto it : itr)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}