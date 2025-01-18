#include <bits/stdc++.h>
using namespace std;

void left_rotate(vector<int> &nums, int k)
{
    int x,n = nums.size();
    vector<int> arr2 = nums;
    while(k--)
    {
        x = arr2[0];    
        for (int i = 0; i < n; i++)
        {
            if(i==n-1)
            {
                arr2[i] = x;
            }
            else
            {
                arr2[i]=arr2[i+1];    
            }
            
        }
    }

    for (auto it : arr2)
    {
        cout << it << " ";
    }
}

int right_rotate(vector<int> &nums, int k)
{
    int x,n = nums.size();
    vector<int> arr2 = nums;
    while(k--)
    {
        x = arr2[n-1];    
        for (int i = n-1; i >= 0; i--)
        {
            if(i==0)
            {
                arr2[0] = x;
            }
            else
            {
                arr2[i]=arr2[i-1];    
            }
            
        }
    }

    for (auto it : arr2)
    {
        cout << it << " ";
    }

}



int main()
{
    int k = 3;
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7};
    left_rotate(arr1, 1);
    return 0;
}