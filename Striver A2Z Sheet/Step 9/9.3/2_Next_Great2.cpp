#include <bits/stdc++.h>
using namespace std;

// striver's method(optimal)
vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    stack<int> st;
    vector<int> nge(n, 0);
    for (int i = (2 * n) - 1; i >= 0; i--)
    {
        int j = (i % n);
        while (st.empty() != true && st.top() <= nums[j])
        {
            st.pop();
        }
        if (j < n)
        {
            if (st.empty())
            {
                nge[j] = -1;
            }
            else
            {
                nge[j] = st.top();
            }
            st.push(nums[j]);
        }
    }
    return nge;
}

// my method
// vector<int> nextGreaterElements(vector<int> &nums)
// {
//     int n = nums.size();
//     stack<int> st;
//     vector<int> nge(n, 0);
//     for (int i = (2 * n) - 1; i >= 0; i--)
//     {
//         int j = (i % n);
//         while (st.empty() != true && st.top() <= nums[j])
//         {
//             st.pop();
//         }
//         if (st.empty())
//         {
//             nge[j] = -1;
//         }
//         else
//         {
//             nge[j] = st.top();
//         }
//         st.push(nums[j]);
//     }
//     for (int i = 0; i < nums.size(); i++)
//     {
//         ans[i] = nge[i];
//     }
//     return ans;
// }

int main()
{
    vector<int> n1 = {1, 2, 3, 4, 3};
    for (auto it : nextGreaterElements(n1))
    {
        cout << it << " ";
    }
    return 0;
}