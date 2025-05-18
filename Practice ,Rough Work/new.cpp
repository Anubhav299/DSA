#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sumOfDigits(int n)
    {
        int sum = 0;
        while (n)
        {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int minSwaps(vector<int> &nums)
    {
        vector<vector<int>> digitSum;   //[sumOfDigits,number]
        unordered_map<int, int> posMap; // number->actualPos
        for (int i = 0; i < nums.size(); i++)
        {
            digitSum.push_back({sumOfDigits(nums[i]), nums[i]});
            posMap[nums[i]] = i;
        }
        sort(digitSum.begin(), digitSum.end());
        int cnt = 0;
        for (int i = 0; i < digitSum.size(); i++)
        {
            int actualPos = posMap[digitSum[i][1]];
            if (actualPos != i)
            {
                int el = nums[i];
                nums[actualPos] = el;
                posMap[el] = actualPos;
                cnt++;
            }
        }
        return cnt;
    }
};

int main()
{

    return 0;
}