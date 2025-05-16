#include <bits/stdc++.h>
using namespace std;

/*
Intuition is that we start from the end of nums2 and left is nums1's last non-zero element
whereas total is the actual last index of nums1
we compare left of nums1 with right of nums2 and whichever is larger is put at last place(total) in nums1 
*/
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    
    int left = m - 1;                   //left is assigned to the last non-zero element of nums1
    int right = n - 1;                  //right is assigned to the last element of nums2
    int total = (m + n) - 1;            //this is the actual last index of nums1

    while (left >= 0 && right >= 0)
    {
        if (nums1[left] > nums2[right])
        {
            nums1[total] = nums1[left];
            left--;
            total--;
        }
        else
        {
            nums1[total] = nums2[right];
            right--;
            total--;
        }
    }

    // in case elements from nums2 are left
    while (right >= 0)
    {
        nums1[total] = nums2[right];
        total--;
        right--;
    }
}

int main()
{
    vector<int> arr1 = {1, 2, 3, 0, 0, 0, 0};
    vector<int> arr2 = {3, 4, 7, 9};

    merge(arr1, 3, arr2, 4);
    for(auto it:arr1)
    {
        cout << it << " ";
    }
    return 0;
}