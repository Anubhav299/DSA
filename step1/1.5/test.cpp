#include <bits/stdc++.h>
using namespace std;

string required_way(string s)
{
    string str="";
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            s[i]=char(tolower(s[i]));
            if(int(s[i])>96&&int(s[i])<123)
            {
                str+=s[i];
            }
        }
        return str;
}
// bool isPalindrome(string s) 
//     {
//         string str,rev;
//         str = required_way(s);
//         int n=str.length();
//         for(int  i = 0; i < (n/2); i++)
//         {
//             rev[i]=str[n-1-i];
//         }
//         if(rev==str)
//         {
//             return true;
//         }
//         else
//         {
//             return false;
//         }
//     }


int main()
{
    string s,rev;
    cout<<"Enter String - ";
    getline(cin,s);
        // str = required_way(s);
    cout<<required_way(s);
    
    return 0;
}

// for (int i = 0; i < n / 2; ++i) 
// {
//         char temp = str[i];
//         str[i] = str[n - i - 1];
//         str[n - i - 1] = temp;
// }