#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &nums)
{
    int n = nums.size();
    stack<int> st;
    vector<int> nse(n, 0);
    for (int i = 0; i < n; i++)
    {
        while(st.empty()!=true && nums[i]<=st.top())
        {
            st.pop();
        }
        if(st.empty())
        {
            nse[i] = -1;
        }
        else
        {
            nse[i] = st.top();
        }
        st.push(nums[i]);
    }
    return nse;
}

int main()
{
    vector<int> n1 = {3,2,1};
    for (auto it : nextSmallerElement(n1))
    {
        cout << it << " ";
    }
    return 0;
}