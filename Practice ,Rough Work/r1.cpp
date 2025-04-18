#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {3, 1, 2, 2, 2, 1, 3};
    unordered_map<int, int> hash;
    int n = arr.size(), k = 2, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if(hash.find(arr[i]) == hash.end())
        {
            if (i % k == 0)
            {
                hash.insert({arr[i], i});
            }
        }
        else
        {
            ++cnt;  
            if(i % k == 0)
            {
                hash[arr[i]] = i;
            }
        }
    }

    for(auto it:hash)
    {
        cout << it.first << " " << it.second << endl;
    }
    cout << endl;
    cout << cnt;
    return 0;
}