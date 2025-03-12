#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans(nums1.size(), 0), nge(nums2.size(), 0);
    stack<int> st;
    for (int i = nums2.size() - 1; i >= 0; i--)
    {
        while (st.empty() != true && st.top() <= nums2[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            nge[i] = -1;
        }
        else
        {
            nge[i] = st.top();
        }
        st.push(nums2[i]);
    }
    for (int i = 0; i < nums1.size(); i++)
    {
        for (int j = 0; j < nums2.size(); j++)
        {
            if (nums1[i] == nums2[j])
            {
                ans[i] = nge[j];
                break;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> n1 = {4, 1, 2};
    vector<int> n2 = {1, 3, 4, 2};
    for (auto it : nextGreaterElement(n1, n2))
    {
        cout << it << " ";
    }
    return 0;
}