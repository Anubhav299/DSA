#include <bits/stdc++.h>
using namespace std;

void sorting(vector<int> &nums)
{
    int a=0, b=0, c=0;
    for (int i = 0;i<nums.size();i++)
    {
        if(nums[i]==0)
            ++a;
        else if(nums[i]==1)
            ++b;
        else
            ++c;
    }
    for (int i = 0; i < a; i++)
    {
        nums[i] = 0;
    }
    for (int i = a; i < a+b; i++)
    {
        nums[i] = 1;
    }
    for (int i = a+b; i < a+b+c; i++)
    {
        nums[i] = 2;
    }
}

// Similar to Dutch National Flag Problem
void sort2method(vector<int> &nums)
{
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[high], nums[mid]);
            high--;
        }
    }
}


int main()
{
    vector<int> arr = {2, 0, 1, 0, 0, 1, 2, 2, 1};
    sort2method(arr);
    for(auto it:arr)
    {
        cout << it << " ";
    }
    return 0;
}