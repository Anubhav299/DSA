#include <bits/stdc++.h>
using namespace std;

void bubblesort(vector <int> &nums)
{
    int n = nums.size();
    int Swap = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if(nums[j]<nums[j-1])
            {
                Swap = 1;
                swap(nums[j], nums[j - 1]);
            }
        }
        if(Swap == 0)
        {
            break;
        }
    }
}

int main()
{
    vector<int> arr = {4, 7, 2, 5, 1, 3};
    bubblesort(arr);
    for(auto it:arr)
    {
        cout << it << " ";
    }
    return 0;
}