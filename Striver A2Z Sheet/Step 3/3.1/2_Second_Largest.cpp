#include <bits/stdc++.h>
using namespace std;

int second_largest(vector<int> &arr)
{
    int mx = arr[0], smax = -1;
    for (auto it : arr)
    {
        if(mx<it)
        {
            smax = mx;
            mx = it;
        }
        else if(mx>it && (it>smax))
        {
            smax = it;
        }
    }
    if (smax == mx)
    {
        return -1;
    }
    
    return smax;
}


int second_smallest(vector<int> &arr)
{
    int mn = arr[0], smin = INT_MAX;
    for (auto it : arr)
    {
        if(mn>it)
        {
            smin = mn;
            mn = it;
        }
        else if(mn<it && (it<smin))
        {
            smin = it;
        }
    }
    if (smin == mn)
    {
        return -1;
    }
    
    return smin;

}


int main()
{
    vector<int> arr = {1, 2, 4, 7, 7, 5};
    cout << "Second Largest : " << second_largest(arr) << endl;
    cout << "Second Smallest : " << second_smallest(arr);
    return 0;
}
