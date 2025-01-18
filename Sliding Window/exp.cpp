#include <bits/stdc++.h>
using namespace std;

//void display(vector<int> &arr)


int main()
{
    vector<int> res;
    vector<int> arr = {9, 5, 2, 1, 7, 9, 10};
    int start = 0, end = 0, window = 3, mx = INT_MIN;
    
    while (end < arr.size())
    {
        mx 
        // if(arr[end]<0)
        // {
        //     ls.push_back(arr[end]);
        // }
        
        if ((end - start + 1) < window)
        {
            mx=max(mx,arr[end]);
            end++;
        }
        else if((end - start + 1) == window)
        {
            if(arr[end]>mx)
            {
                mx=arr[end];
            }
            res.push_back(mx);
            start++;
            end++;

        }
    }
    cout << "Answer is : ";
    for(auto it:res)
    {
        cout << it << " ";
    }
    return 0;
}