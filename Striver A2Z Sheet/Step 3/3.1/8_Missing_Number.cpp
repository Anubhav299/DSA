#include <bits/stdc++.h>
using namespace std;

// brute force using set for TC = O(2N) and SC = O(N)
//wrong on some test cases as we are not iterating using Size of Set 
//don't think much about this solution
// int brute_Missing(vector<int> &nums)
// {   
//     set<int> st;
//     for(auto it:nums)
//     {
//         st.insert(it);
//     }
//     if(*(st.begin())==0)
//     {
//         int j = 0;
//         for (auto it: st)
//         {
//             if(it!=j)
//             {
//                 return j;
//             }
//             j++;
//         }
//     }
//     return 0;
// }



//optimal approach using sum for TC = O(N) and SC = O(1)
int optimal1_Missing (vector<int> &nums)
{
    int n = nums.size(), true_sum, sum = 0;
    true_sum = (n * (n + 1)) / 2;
    for(auto it: nums)
    {
        sum += it;
    }
    return true_sum - sum;
}

//using XOR 
int optimal2_Missing (vector<int> &nums)
{
    int n = nums.size(),xor1=0,xor2=0;
    for (int i = 1; i <= n; i++)
    {
        xor1 ^= i;
    }
    for(auto it:nums)
    {
        xor2 ^= it;
    }
    return xor1 ^ xor2;
}

int main()
{
    
    vector<int> v = {9,6,4,2,3,5,7,0,1};
    cout << "Missing Number is " << optimal1_Missing(v);
}