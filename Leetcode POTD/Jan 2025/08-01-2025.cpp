// #include <bits/stdc++.h>
// using namespace std;

//O(n^3)
// bool isPrefixAndSuffix(string s1, string s2)
// {
//     for (int i = 0, j = 0; i < s1.length(); i++, j++)
//     {
//         if(s1[i]!=s2[j])
//         {
//             return false;
//         }
//     }
//     for (int i = s1.length() - 1, j = s2.length() - 1; i >= 0; i--, j--)
//     {
//         if(s1[i]!=s2[j])
//         {
//             return false;
//         }
//     }
//     return true;
// }

// int countPrefixSuffixPairs(vector<string>& words) 
// {
//     int c = 0;
//     for (int i = 0; i < words.size(); i++)
//     {
//         for (int j = 0; j < words.size(); j++)
//         {
//             if(isPrefixAndSuffix(words[i],words[j]) && i<j)
//             {
//                 ++c;
//             }
//         }
//     }
//     return c;
// }

// int main()
// {
//     vector<string> w = {"abc","abcabc"};
//     // cout << countPrefixSuffixPairs(w);
//     cout << isPrefixAndSuffix("a","abb");
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

//O(n^2)
bool isPrefixAndSuffix(string s1, string s2)
{
    if ((s2.find(s1) == 0) && (s2.rfind(s1) == s2.length() - s1.length()))
    {
        return true;
    }
    return false;
}

int countPrefixSuffixPairs(vector<string>& words) 
{
    int c = 0;
    for (int i = 0; i < words.size(); i++)
    {
        for (int j = 0; j < words.size(); j++)
        {
            if(isPrefixAndSuffix(words[i],words[j]) && i<j)
            {
                ++c;
            }
        }
    }
    return c;
}
int main()
{
    vector<string> w = {"abc","abcabc"};
    cout << countPrefixSuffixPairs(w);
    return 0;
}