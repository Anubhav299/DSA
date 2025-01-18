#include <bits/stdc++.h>
using namespace std;



void Reverse(vector<int> &arr, int start, int end)
{
  while (start <= end)
  {
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }
}

void rotate(vector<int> &nums, int k)
{
    //right rotating ,
    //say k = 1 and nums = 1,2,3,4,5,6
    int n = nums.size();
    Reverse(nums, 0, n - k - 1);     //5,4,3,2,1
    Reverse(nums, n - k, n - 1);     //6
                                            // becomes 5,4,3,2,1,6
                                            
    Reverse(nums, 0, n - 1);         //6,1,2,3,4,5

    for (auto it : nums)
    {
        cout << it << " ";
    }
}


int main()
{

  vector<int> arr = {1, 2, 3, 4, 5, 6};
  rotate(arr, 1);
}