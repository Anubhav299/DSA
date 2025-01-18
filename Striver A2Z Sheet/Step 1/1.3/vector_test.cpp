#include <bits/stdc++.h>
using namespace std;

int main()
{
    // pair <int,int> p ={7,5};
    // cout<<p.first<<" "<<p.second;
    // cout<<endl;

    // pair <int,pair<int,int>> p1 = {9,{4,5}};
    // cout<<p1.first<<" "<<p1.second.first;
    // pair<int,int> arr[] = {{9,6},{4,5},{3,8}};
    // cout<<arr[1].second;    

    // vector <int> v;
    // v.push_back(1);
    // v.push_back(3);
    // v.emplace_back(5);
    //cout<<v[1]<<endl;
    // for(auto it = v.begin();it!=v.end();it++)
    // {
    //     cout<<*(it)<<" ";
    // }

    vector <int> ve(2,37);
    ve.insert(ve.begin(),20);
    ve.insert(ve.begin()+1,2,5);

    for(auto it : ve)
    {
        cout<<it<<" ";
    }

    return 0;
}