#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) 
{
    string res="",word="";
    int i = 0;
    s = " " + s + " ";
    while(s[i++]!='\0')
    {
        if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
        {
            if(!word.empty())
            {
                if(res!="")
                {
                    res = word + " " + res;
                }
                else
                {
                    res = word;
                }
            }
            word = "";
        }
        else
        {
            word += s[i];
        }
    }
    return res;
}

int main()
{
    string str = "a good   example";
    cout << reverseWords(str);
    return 0;
}