#include <bits/stdc++.h>
using namespace std;

void insertSorted(stack<int> &s, int top)
{
    if (s.empty() || top >= s.top())
    {
        s.push(top);
        return;
    }
    int temp = s.top();
    s.pop();
    insertSorted(s, top);

    s.push(temp);
}

void sort(stack<int> &s)
{
    if (s.empty())
        return;
    int top = s.top();
    s.pop();
    sort(s);

    insertSorted(s, top);
}

int main()
{

    return 0;
}