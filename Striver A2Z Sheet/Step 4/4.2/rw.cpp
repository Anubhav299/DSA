#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num = 1993 ;
    int mnindex,mxindex,min,max;
        // n = to_string(num);
        min=INT_MAX;
        max=INT_MIN;
    // cout << "Enter Number : ";
    // cin >> num;
    string n;
    n = to_string(num);
    // if((*min_element(n.begin(),n.end()))==n[0])
    //     {
    //         swap(*max_element(n.begin(),n.end()),n[0]);
    //         cout << stoi(n);
    //     }
    for(int i = 0;i<n.length();i++)
        {
            if(min>n[i])
            {
                min=n[i];
                mnindex=i;
            }
        }
        for(int i = mnindex+1;i<n.length();i++)
        {
            if(max<=n[i])
            {
                max=n[i];
                mxindex=i;
                cout << n[mxindex];
            }
        }
        // if(n[mnindex]<n[mxindex])
        // {
        //     swap(n[mnindex],n[mxindex]);
        // }
        // cout << stoi(n);
}