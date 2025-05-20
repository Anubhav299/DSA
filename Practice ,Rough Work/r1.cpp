#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n = 6;
    int prev2 = 0, prev1 = 1, curr = 0;
    for (int i = 2; i <= n; i++)
    {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    cout << prev1;
    return 0;
}