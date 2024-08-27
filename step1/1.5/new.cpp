#include <bits/stdc++.h>
using namespace std;

int main()
{
    
string str;
string s,rev;
    cout<<"Enter String - ";
    getline(cin,str);
        // str = required_way(s);
        rev=str;
        reverse(str.begin(), str.end());
        // int n=str.length();
        // for (int i = 0; i < n / 2; ++i) 
        // {
        // char temp = str[i];
        // str[i] = str[n - i - 1];
        // str[n - i - 1] = temp;
        // }

        cout<<rev<<endl;
        cout<<str;
    return 0;
}
