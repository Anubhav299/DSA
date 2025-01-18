#include <bits/stdc++.h>
using namespace std;

//void display(vector<int> &arr)


int main()
{
    list<int> ls;
    vector<int> res;
    vector<int> arr = {-8, 2, 3, -6, 10};
    int start = 0, end = 0, window = 2;
    
    while (end < arr.size())
    {
        if(arr[end]<0)
        {
            ls.push_back(arr[end]);
        }
        if ((end - start + 1) < window)
        {
            end++;
        }
        else if((end - start + 1) == window)
        {
            if(ls.empty())
            {
                res.push_back(0);
            }
            else
            {
                res.push_back(ls.front());
                if(arr[start]<0)
                {
                    ls.pop_front();
                }
            }
            
            start++;
            end++;
        }
    }
    cout << "Answer is : ";
    for(auto it:res)
    {
        cout << it << " ";
    }
    return 0;
}