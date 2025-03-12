#include <bits/stdc++.h>
using namespace std;

//Better Approach
//O(N^3)
int tupleSameProduct(vector<int> &nums)
{
    int n = nums.size(), ans = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            int pro = nums[i] * nums[j];
            unordered_set<int> hash;
            for (int k = i + 1; k < j; k++)
            {

                if ((pro % nums[k]) == 0)
                {
                    if (hash.find(pro / nums[k]) != hash.end())
                    {
                        ++ans;
                    }
                    hash.insert(nums[k]);
                }
            }
        }
    }
    return ans * 8;
}


//Optimal Approach
//O(N^2)

int main()
{

    return 0;
}