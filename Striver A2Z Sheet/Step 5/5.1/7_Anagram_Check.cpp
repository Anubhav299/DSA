#include <bits/stdc++.h>
using namespace std;

//Brute Force
//Sort both strings and check afterwards

//Better Approach
//using hash arrays to store freq of both strings

//Optimal Approach
//using a single hash array to increase freq from s and decrease from t and hence all 0s should exist in the hash array
bool isAnagram(string s, string t) 
{
    if(s.length()!=t.length())
    {
        return false;
    }
    vector<int> hash(26,0);
    for(int i=0;i<s.length();i++)
    {
        hash[s[i]-'a']++;
        hash[t[i]-'a']--;
    }
    for(int i=0;i<26;i++)
    {
        if(hash[i]!=0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string str = "anagram", t = "gramnaa";
    cout << isAnagram(str, t);
    return 0;
}