#include <bits/stdc++.h>
using namespace std;

bool canPlaceFlowers(vector<int> &flowerbed, int n)
{
    int len = flowerbed.size(), m = n;
    if (n == 0)
        return true;
    if (len == 1)
    {
        if (flowerbed[0] == 0 && n > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    for (int i = 0; i < len; i++)
    {
        if ((i == 0 && flowerbed[0] == 0 && flowerbed[1] == 0) ||
            (i == len - 1 && flowerbed[i] == 0 &&
             flowerbed[len - 2] == 0))
        {
            flowerbed[i] = 1;
            m--;
        }
        else if (i > 0 && i < len - 1 &&
                 flowerbed[i - 1] == flowerbed[i] &&
                 flowerbed[i] == flowerbed[i + 1] && flowerbed[i] == 0)
        {
            flowerbed[i] = 1;
            m--;
        }
        else
        {
        }
    }
    if (m <= 0)
    {
        return true;
    }
    return false;
}

int main()
{
    vector<int> arr = {1, 0, 0, 0, 1};
    cout << canPlaceFlowers(arr,1);
    return 0;
}