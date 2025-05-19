#include <bits/stdc++.h>
using namespace std;

void print_divisors(int n)
{
    vector<int> leftHalf, rightHalf;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            leftHalf.push_back(i);
            if (n / i != i)
            {
                rightHalf.push_back(n / i);
            }
        }
    }
    for (auto it : leftHalf)
    {
        cout << it << " ";
    }
    for (int i = rightHalf.size() - 1; i >= 0; i--)
    {
        cout << rightHalf[i] << " ";
    }
}

int main()
{

    return 0;
}