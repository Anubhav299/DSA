#include <bits/stdc++.h>
using namespace std;

// Optimal Approach
/*TC : O(√n * log n) for Average Case which is very good for worst : O(n)

Intuition : Check for only those  
*/
bool primeCheck(int x)
{
    if (x < 2)
        return false;

    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }

    return true;
}

vector<int> AllPrimeFactors(int n)
{
    vector<int> result;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (primeCheck(i))
            {
                result.push_back(i);
                while (n % i == 0)
                {
                    n = n / i;
                }
            }
        }
    }

    if (n != 1 && primeCheck(n))
        result.push_back(n);

    return result;
}

// Bakwas
//  bool primeCheck(int x)
//  {
//      if (x < 2)
//          return false;

//     for (int i = 2; i * i <= x; i++)
//     {
//         if (x % i == 0)
//             return false;
//     }

//     return true;
// }

// vector<int> AllPrimeFactors(int n)
// {
//     vector<int> result;
//     for (int i = 1; i * i <= n; i++)
//     {
//         if (n % i == 0)
//         {
//             if (primeCheck(i))
//             {
//                 result.push_back(i);
//             }

//             if (n / i != i)
//             {
//                 if (primeCheck(n / i))
//                 {
//                     result.push_back(n / i);
//                 }
//             }
//         }
//     }
//     return result;
// }

int main()
{

    return 0;
}