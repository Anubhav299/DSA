#include <bits/stdc++.h>
using namespace std;

int maxLen(vector<int> &arr)
{
    int maxi = 0;
    int sum = 0;
    unordered_map<int, int> mpp;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            maxi = i + 1;
        }
        else
        {
            if (mpp.find(sum) != mpp.end())         /*sum already exists so that means a+0=a, 
                                                      so, all elements between add upto 0
                                                    */  
            {
                maxi = max(maxi, i - mpp[sum]);
            }
            else
            {
                mpp[sum] = i;                       //sum doesn't exist, just add it to the hash map
            }
        }
    }
    return maxi;
}

int main()
{
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};
    cout << maxLen(arr);
    return 0;
}