#include <bits/stdc++.h>
using namespace std;

int isSorted(int n, vector<int> a) 
{
    for(int i=0;i<n-1;i++)
    {
        if(a[i]<=a[i+1])
        {
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    vector<int> a = {6, 1, 2, 3, 4, 5};
    if(isSorted(a.size(),a)==1)
    {
        cout << "Sorted.";
    }
    else
    {
        cout << "Not Sorted.";
    }
    return 0;
}