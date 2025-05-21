#include <bits/stdc++.h>
using namespace std;

/*
Because you will add these steps to reach to the n to previously present options and the amount of variations would be the same afterwards

2: [1,1] , [2]
3: [1,1,1] , [2,1] , [1,2]
Now we are on the 4th one.
We can climb from 3 by adding 1 to each and every option from 3:
[1,1,1,*1] , [2,1,*1] , [1,2,*1]
Or we can climb frmo 2 by adding 2 to each and every option from 2:
[1,1,*2] , [2,*2]
The amount of steps changed, but the amount of options is the same.
Now, to form 4 we need to combine these 2 into
4: [1,1,1,*1] , [2,1,*1] , [1,2,*1] , [1,1,*2] , [2,*2]

I struggled to understand that until I visualized it this way
*/

//Check register for more clarity
int climbStairs(int n)
{
    if (n == 1)
        return 1;
    int prev2 = 1;
    int prev1 = 1, curr = 0;
    for (int i = 2; i <= n; i++)
    {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main()
{

    return 0;
}