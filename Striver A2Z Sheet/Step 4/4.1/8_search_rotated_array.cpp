#include <bits/stdc++.h>
using namespace std;

int main()
{
    int low, high, mid, target, index = -1;

    vector<int> arr = {7, 8, 1, 2, 3, 4, 5, 6};
    low = 0;
    high = arr.size() - 1;
    target = 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            index = mid;
            break;
        }
        else
        {   //left part is sorted
            if (arr[low] <= arr[mid])
            {
                if (target >= arr[low] && target <= arr[mid]) //checking element existence
                {
                    high = mid - 1; //element exists here
                }
                else
                {
                    low = mid + 1; //element does not exist here
                }
            }
            else 
            {   //right half is sorted
                if (target >= arr[mid] && target <= arr[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
    }

    cout << endl
         << "Here's the Index : " << index;
    return 0;
}