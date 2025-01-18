#include <bits/stdc++.h>
using namespace std;

vector<int> bruteAlt(vector<int> &nums)
{
    vector<int> pos, neg;
    for (auto it : nums)
    {
        if (it < 0)
            neg.push_back(it);
        else
            pos.push_back(it);
    }
    for (int i = 0; i < nums.size() / 2; i++)
    {
        nums[2 * i] = pos[i];
        nums[(2 * i) + 1] = neg[i];
    }
    return nums;
}

vector<int> optimalAlt(vector<int> &nums)
{
    vector<int> arr(nums.size(), 0);
    int i = 0, j = 1;
    for (auto it : nums)
    {
        if (it > 0)
        {
            arr[i] = it;
            i += 2;
        }
        else
        {
            arr[j] = it;
            j += 2;
        }
    }
    return arr;
}

vector<int> optimalAltReccur(vector<int> &nums)
{
    int n = nums.size(),posi,negs;
    vector<int> pos, neg;
    for (auto it : nums)
    {
        if (it < 0)
            neg.push_back(it);
        else
            pos.push_back(it);
    }
    posi = pos.size();
    negs = neg.size();
    if(posi > negs)
    {
        for (int i = 0; i < negs; i++)
        {
            nums[2 * i] = pos[i];
            nums[2 * i + 1] = neg[i];
        }

        int index = negs * 2;
        for (int i = negs; i < posi; i++)
        {
            nums[index] = pos[i];
            index++;
        }
    }
    else
    {
        for (int i = 0; i < posi; i++)
        {
            nums[2 * i] = pos[i];
            nums[2 * i + 1] = neg[i];
        }

        int index = posi * 2;
        for (int i = posi; i < negs; i++)
        {
            nums[index] = neg[i];
            index++;
        }
    }
    return nums;
}

int main()
{
    vector<int> arr = {1, 2, -4, -5, 3, 4, 5};
    // arr = optimalAltReccur(arr);
    for (auto it : optimalAltReccur(arr))
    {
        cout << it << " ";
    }
    return 0;
}