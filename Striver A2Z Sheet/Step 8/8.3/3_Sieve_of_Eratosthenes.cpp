#include <bits/stdc++.h>
using namespace std;

/*
Intuition : Goal is to find primes in O(1), so we prepare a BlackBox(array) of sorts which will store 1 for those numbers which are prime and 0 otherwise

How we prepare the BlackBox ?
---We start i=2 and go till sqrt(n){written i*i<=n which is better as sqrt calculation takes time}
Goal is to use small prime numbers such as 2,3,5,7 set all their multiples = 0 and by the time we reach end, only primes will be = 1 and thus we can find primes in O(1)

Check register for more clarity.
*/

int main()
{
    int count = 0;
    int n = 10;
    vector<int> primes(n + 1, 1);

    for (int i = 2; i * i <= n; i++)
    {
        if (primes[i] == 1)
        {
            for (int j = i * i; j <= n; j += i) // multiples of i getting marked 0
            {
                primes[j] = 0;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (primes[i] == 1)
            count++;
    }
    return count;
    return 0;
}