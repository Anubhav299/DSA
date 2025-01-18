#include <bits/stdc++.h>
using namespace std;

//void display(vector<int> &arr)


int main()
{
    vector<int> arr = {2, 5, 1, 8, 2, 9, 1};
    int start = 0, end = 0, window = 3, mx = 0, sum = 0;
    
    while (end < arr.size())
    {
        sum += arr[end];
        if ((end - start + 1) < window)
        {
            end++;
        }
        else if((end - start + 1) == window)
        {
            mx = max(mx, sum);
            sum -= arr[start];
            start++;
            end++;
        }
    }
    cout << "MaxSum : " << mx;
    return 0;
}