#include <bits/stdc++.h>
using namespace std;

//Hashing Method
//useful for indices
vector<int> twoSumPossibleHash(vector<int> &nums,int target)
{
    unordered_map <int, int> hash;
    vector<int> v;
    for (int i = 0; i < nums.size(); i++)
    {
        if(hash.find(target-nums[i])!=hash.end())
        {
            return {hash[target-nums[i]],i};
        }
        hash[nums[i]] = i;
    }

    return {-1, -1};
}

//Two Pointers
//better for just detecting YES or NO for 2Sum 
//not for indices since we'll be sorting the array
void twoSumPossiblePointers(vector<int> &nums,int target)
{
    int left = 0, right = nums.size()-1, flag = 0;
    ;
    sort(nums.begin(), nums.end());
    while (left <= right)
    {
        int sum = nums[left] + nums[right];
        if (sum == target)
        {
            flag = 1;
            cout << "Yes, Possible !!";
            break;
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    if (flag == 0)
    {
        cout << "No, not possible.";
    }
}

int main()
{
    vector<int> res,arr = {2, 6, 5, 8, 11};
    twoSumPossiblePointers(arr, 9);
    // for(auto it: res)
    // {
    //     cout << it << " ";
    // }
}