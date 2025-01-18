#include <bits/stdc++.h>
using namespace std;

int main()
{
    int low, high, mid, target, index = -1;

    vector<int> nums = {3, 1, 2, 3, 3, 3, 3};
    low = 0;
    high = nums.size() - 1;
    target = 2;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (nums[mid] == target)
        {
            index = mid;
            break;
        }

        if (nums[low] == nums[mid] && nums[mid] == nums[high])
        {
            low += 1;
            high -= 1;
        }
        if (nums[low] <= nums[mid])
        {
            if (target >= nums[low] && target <= nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else if (nums[low] > nums[mid])
        {
            if (target >= nums[mid] && target <= nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }

    if (index == -1)
    {
        cout << "Not Present.";
    }
    else
    {
        cout << endl
             << "Present.";
    }

    return 0;
}