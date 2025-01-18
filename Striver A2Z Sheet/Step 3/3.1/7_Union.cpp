#include <bits/stdc++.h>
using namespace std;


//using Set 
vector<int> findUnion(vector<int> &a, vector<int> &b) 
    {
        
        set<int> st;
        for(auto it:a)
        {
            st.insert(it);
        }
        for(auto it:b)
        {
            st.insert(it);
        }
        
        vector<int> v(st.begin(), st.end());
        return v;
    }


//using Map


//using Pointers
vector<int> Union3(vector<int> &a, vector<int> &b) 
{
    int n1 = a.size(), n2 = b.size();
    int i = 0, j = 0;
    vector<int> unArr;
    while (i < n1 && j < n2)
    {
        if(a[i]<=b[j])
        {
            if (unArr.size() == 0 || unArr.back() != a[i])
            {
                unArr.push_back(a[i]);

            }
            i++;
        }
        else
        {
            if (unArr.size() == 0 || unArr.back() != b[j])
            {
                unArr.push_back(b[j]);
            }
            j++;
        }
    }


        //in case elements are left in the first array
    while (i < n1)
    {
        if (unArr.size() == 0 || unArr.back() != a[i])
            {
                unArr.push_back(a[i]);
            }
            i++;
    }


    //in case elements are left in the second array
    while (j < n2)
    {
        if (unArr.size() == 0 || unArr.back() != b[j])
            {
                unArr.push_back(b[j]);
            }
            j++;
    }

    return unArr;
}



int main()
{
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {1, 2, 3, 6, 7};
    for(auto it:Union3(a, b))
    {
        cout << it << " ";
    }
    return 0;
}