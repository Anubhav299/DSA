#include <bits/stdc++.h>
using namespace std;

int main()
{
    // pair <int,int> p = {1,5};
    // cout << p.first;

    pair <int,pair<int,int>> pa = {1,{3,6}};
    cout<<pa.second.first<<" ";

    pair<int,int> arr[] = {{1,3},{2,4},{5,7}};
    cout<<arr[1].first;

    return 0;
}