#include <bits/stdc++.h>
using namespace std;

int main()
{
    int Numbers[] = {2, 4, 8, 10};
    int *ptr = Numbers;
    for (int C = 0; C < 3; C++)
    {
        cout << *ptr << "@";
        ptr++;
    }
    cout << endl;
    for (int C = 0; C < 4; C++)
    {
        (*ptr) *= 2;
        --ptr;
    }
    for (int C = 0; C < 4; C++)
        cout << Numbers[C] << "#";
    cout << endl;
    return 0;
}