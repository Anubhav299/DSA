#include <bits/stdc++.h>
using namespace std;

// Recursive Method
int recurAtoi(int i, string s, int ans, int sign)
{
    if (isdigit(s[i]) != true || i >= s.length())
    {
        return ans * sign;
    }
    int digit = s[i] - '0';

    // Check for overflow before multiplying and adding
    if (ans > (INT_MAX / 10) || (ans == INT_MAX / 10 && digit > INT_MAX % 10))
    {
        return (sign == 1) ? INT_MAX : INT_MIN;
    }
    ans *= 10;
    ans += digit;
    return recurAtoi(i + 1, s, ans, sign);
}

int myAtoi(string s)
{
    int i = 0;
    while (i < s.length() && s[i] == ' ') // ignoring leading whitespaces
    {
        i++;
    }
    int ans = 0, sign = 1;
    if (s[i] == '+' || s[i] == '-')
    {
        sign = (s[i] == '+') ? 1 : -1;
        i++;
    }

    return recurAtoi(i, s, ans, sign);
}

int main()
{
    string s = " -042";
    cout << myAtoi(s);
    return 0;
}