#include <bits/stdc++.h>
using namespace std;

void frequencyCount(vector<int>& arr, int N, int P) 
    {
        unordered_map <int,int> hash;
        for(int i=0;i<N;i++)
        {
            if(arr[i]>N)
            {
                hash[arr[i]-1]=0;
            }
            else
            {
                hash[arr[i]-1]++;
            }
        }
        
        for(int i=0;i<N;i++)
        {
            arr[i]=hash[i];

        }
    }

int main ()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    frequencyCount(arr, 5, 5);
    for(int i=0;i<arr.size();i++)
    {
        cout << arr[i] << " ";
    }
}