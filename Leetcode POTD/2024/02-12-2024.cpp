#include <bits/stdc++.h>
using namespace std;

//using extra space
int isPrefixOfWord(string sentence, string searchWord) 
{
    

}

//without using extra space
int isPrefixOfWord(string sentence, string searchWord) 
{
    sentence = " " + sentence;
    int n = sentence.length();
    for (int i = 0; i < n; i++)
    {
        if(sentence[i]==' ' && sentence[i + 1] == searchWord[0])
        {
            
        }
    }
}

int main()
{
    string sen = "i love eating burger";
    string w = "burg";
    cout << isPrefixOfWord(sen, w);
    return 0;
}