#include <bits/stdc++.h>
using namespace std;

pair<int, int> get(int a, int b)
{
    int x = a ^ b;
    a = a ^ x;
    b = b ^ x;
    return {a, b};
}

int main()
{

    return 0;
}