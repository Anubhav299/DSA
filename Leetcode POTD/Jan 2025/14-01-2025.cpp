#include <bits/stdc++.h>
using namespace std;

vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
{
    int n = A.size(), add = 0;
    vector<int> ans(n,0);
    vector<int> hash(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        hash[A[i]]++;
        hash[B[i]]++;

        if (hash[A[i]] == 2 || hash[B[i]] == 2)
        {
            if(hash[A[i]] == 2 && hash[B[i]] == 2 && A[i]!=B[i])
            {
                add = 2;
            }
            else
            {
                add = 1;
            }
            
        }
        else
        {
            add=0;
        }
        if(i>0)
        {                
            ans[i] = ans[i - 1] + add;
        }
        else
        {
            ans[i] = add;
        }
    }
    return ans;
}

int main()
{
    vector<int> A, B;
    A = {1, 2, 3};
    B = {1, 3, 2};
    for(auto it:findThePrefixCommonArray(A,B))
    {
        cout << it << " ";
    }
    return 0;
}