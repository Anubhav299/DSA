#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 5, 3, 8};
    vector<int> hash(*max_element(arr.begin(),arr.end())+1,0);
    for (int i = 0; i < arr.size(); i++)
    {
        hash[arr[i]]++;
    }

    // 0,1,2,3,4,5,6,7,8
    // 0,1,1,1,0,1,0,0,1
    for (int i = 1; i < hash.size(); i++)
    {
        if(hash[])
        if((hash[i]==1 && hash[i*2]==1) || (hash[i]==1 && hash[i/2]==1))
        {
            cout << "Yes !!";
        }
    }
    
    // for(auto it:hash)
    // {
    //     cout << endl << it ;
    // }

}