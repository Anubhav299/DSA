#include <bits/stdc++.h>
using namespace std;

int Kth_Missing(vector<int> &nums,int k)
{
    int low = 0, high = nums.size() - 1,mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        int miss = nums[mid] - (mid + 1);       //done as we can get how many numbers are missing 
        if(miss<k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low + k;
    //or return (high+1+k)
    // striver has derived a formula for this but no need to mug it up
}

int main()
{
    vector<int> arr = {4, 7, 9, 10};
    cout << Kth_Missing(arr, 4);
    return 0;
}