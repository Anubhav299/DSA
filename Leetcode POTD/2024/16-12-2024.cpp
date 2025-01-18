#include <bits/stdc++.h>
using namespace std;

vector<int> getFinal(vector<int> &nums, int k, int multi)
{
    int des;
    vector<int> res = nums;
    for (int i = 0; i < k; i++) // Loop k times
    {
        // Find the minimum element in the vector
        int des = *min_element(res.begin(), res.end());
        
        // Multiply the minimum element by multi
        des = des * multi;
        
        // Find the index of the minimum element
        auto min_pos = min_element(res.begin(), res.end());
        
        // Update the minimum element in the vector with the new value
        *min_pos = des;
    }
    return res;
}

int main()
{
    vector<int> arr = {2, 1, 3, 5, 6};
    vector<int> ans;
    ans = getFinal(arr, 5, 2);
    for(auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}