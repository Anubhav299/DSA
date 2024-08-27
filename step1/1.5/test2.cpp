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

bool isPalindrome(string s) 
    {
        string rev,str;
        str = required_way(s);
        rev = required_way(s);
        reverse(rev.begin(), rev.end());

        if(rev==str)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }


int main()
{
    string s,str;
    cout<<"Enter String - ";
    getline(cin,s);

    // str = required_way(s);
    // cout<<str<<endl;
    // cout<<isPalindrome(s);
    if(isPalindrome(s))
    cout<<"String is Palindrome";
    else
    cout<<"String is not Palindrome";
    
    return 0;
}