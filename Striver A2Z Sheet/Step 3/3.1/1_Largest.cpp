#include <bits/stdc++.h>
using namespace std;

int largest(vector<int> &arr) 
{
    int mx=INT_MIN;
    for(auto it: arr)
    {
        if(it>mx)
        {
            mx=it;
        }
    }
    
    return mx;
}

int main ()
{
    vector<int> arr={2,5,1,3,0};
    cout << largest(arr);
    return 0;
}