#include <bits/stdc++.h>
using namespace std;

//optimal approach
vector<int> minOperations(string boxes)
{
    int n = boxes.length();
    if(n==1)return {0} ;
    vector<int> ans(n, 0);
    int cumValue = 0;
    int cumValueSum = 0;
    for (int i = 0; i < n; i++)
    {
        ans[i] = cumValueSum;
        cumValue += (boxes[i]-'0');
        cumValueSum += cumValue;
    }
    cumValue = 0;
    cumValueSum = 0;
    for (int i = n-1; i >= 0; i--)
    {
        ans[i] += cumValueSum;
        cumValue += (boxes[i]-'0');
        cumValueSum += cumValue;
    }
    return ans;
}

int main()
{
    string boxes = "001011";
    for (auto it : minOperations(boxes))
    {
        cout << it << " ";
    }
    return 0;
}