#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &ranks, long long mid, int cars)
{
    long long carsFixed = 0;
    for (int i = 0; i < ranks.size(); i++)
    {
        carsFixed += sqrt(mid / ranks[i]);
    }
    if (carsFixed >= cars)
    {
        return true;
    }
    return false;
}

long long repairCars(vector<int> &ranks, int cars)
{   
    long long low = 1;                                         //as low as 1
    int maxR = *min_element(ranks.begin(), ranks.end());       //
    long long high = (long long)maxR * cars * cars;            // as high as all cars assigned to least rank
    long long res = -1;
    while (low <= high)
    {
        long long mid = (low + high) / 2;
        if (isPossible(ranks, mid, cars))
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return res;
}

int main()
{
    vector<int> ranks = {4, 2, 3, 1};
    int cars = 10;
    cout << repairCars(ranks, cars);
    return 0;
}