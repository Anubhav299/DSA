/*
Question Description : 2 sorted arrays will be given, :
arr1 = [3,5,7]      arr2 = [1,2,6]

output:
arr1 = [1,2,3]      arr2 = [5,6,7]
task is to sort them as combined array and put elements according to original sizes of the arrays
which will be the brute force solution
*/
#include <bits/stdc++.h>
using namespace std;

// brute force is taking extra space since it won't be mentioned directly in the interview

// optimal 1
/*
Intuition : We get the elements that should be in arr1 somehow irrespective of order in arr1 and elements that should be in arr2 in arr2 irrespective of their order.
TC : O(m+n) + O(nlog n) + O(mlog m)
*/
void mergeArrays1(vector<int> &arr1, int m, vector<int> &arr2, int n)
{
    int left = m - 1;
    int right = 0;
    while (left >= 0 && right < n)
    {
        if (arr1[left] > arr2[right])
        {
            swap(arr1[left], arr2[right]);
            left--;
            right++;
        }
        else
        {
            break;
        }
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}

// Optimal 2
/*
Intuition : Gap Method(taken from shell sort) states that we start with a gap = ceil[(m+n)/2]
and left is at 0 and right = left + gap,  we
TC : O((m+n) * log (m+n))
*/
void mergeArrays2(vector<int> &arr1, int m, vector<int> &arr2, int n)
{
    int len = m + n;
    int gap = (len / 2) + (len % 2); // gap is calculated as : gap = ceil((m+n)/2)
    // ceil(x/2) can also be written as (x/2) + (x%2)  ,say for ceil(7/2) =  int(7/2) + (7%2) = 3 + 1 = 4

    while (gap > 0)
    {
        int left = 0;
        int right = left + gap;

        while (right < len)
        {
            // case 1 : left in arr1 and right in arr2
            if (left < m && right >= m)
            {
                if (arr1[left] > arr2[right - m])
                {
                    swap(arr1[left], arr2[right - m]);
                }
            }
            // case 2 : both in arr2
            else if (left >= m) // no need to check for right as if left >= n then right is obviosly > n
            {
                if (arr2[left - m] > arr2[right - m])
                {
                    swap(arr2[left - m], arr2[right - m]);
                }
            }
            // case 3 : both in arr1
            else
            {
                if (arr1[left] > arr1[right])
                {
                    swap(arr1[left], arr1[right]);
                }
            }
            left++;
            right++;
        }

        if (gap == 1)
            break;
        gap = (gap / 2) + (gap % 2);
    }
}

int main()
{
    vector<int> arr1 = {3, 5, 7};
    vector<int> arr2 = {1, 2, 4, 8, 9};

    mergeArrays2(arr1, arr1.size(), arr2, arr2.size());
    for (auto it : arr1)
    {
        cout << it << " ";
    }

    cout << endl;

    for (auto it : arr2)
    {
        cout << it << " ";
    }
    return 0;
}