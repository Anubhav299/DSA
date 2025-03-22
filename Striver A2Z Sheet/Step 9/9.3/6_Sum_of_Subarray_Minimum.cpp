#include <bits/stdc++.h>
using namespace std;

/*Say arr = {1,4,6,7,3,8,9,2};
    The basic idea is that element 3 will be part of subarrays : 
            {1,4,6,7,3}, {4,6,7,3}, {6,7,3}, {7,3}, {3}, {3,8}, {3,8,9}, {3,8,9,2}
min element :    1     ,    3     ,    3   ,   3  ,  3 ,   3  ,    3   ,     2
        so, 3 will contribute only till its previous smallest and/or next smallest element are encountered
        thus, we find PSEE(previous smallest or equal) and NSE(next smallest element)
        then we subtract the indices and thus get the count of occurence of 3 as minimum in such subarrays
        and therefore the contribution in SUM OF MINIMUM is 3*occurence or (element * occurence)
 */

int mod = (int)1e9 + 7;
vector<int> findNSE(vector<int> &arr)
{
    int n = arr.size();
    vector<int> nse(n, 0);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (st.empty() != true && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        nse[i] = (st.empty()) ? n : st.top();
        st.push(i);
    }
    return nse;
}

vector<int> findPSEE(vector<int> &arr)
{
    int n = arr.size();
    vector<int> psee(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (st.empty() != true && arr[st.top()] > arr[i])
        {
            st.pop();
        }
        psee[i] = (st.empty()) ? -1 : st.top();
        st.push(i);
    }
    return psee;
}

int sumSubarrayMins(vector<int> &arr)
{
    int n = arr.size();
    long long total = 0;
    vector<int> nse, psee;
    nse = findNSE(arr);
    psee = findPSEE(arr);
    for (int i = 0; i < n; i++)
    {
        long long left = i - psee[i];
        long long right = nse[i] - i;
        total = (total + (left * right * arr[i]) % mod) % mod;
    }
    return total;
}

int main()
{

    return 0;
}