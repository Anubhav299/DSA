#include <bits/stdc++.h>
using namespace std;

void insertrev(stack<int> &st, int top)
{
    if (st.empty())
    {
        st.push(top);
        return;
    }
    int newtop = st.top();
    st.pop();
    insertrev(st, top);

    st.push(newtop);
}

void Reverse(stack<int> &st)
{
    if (st.empty())
        return;
    int top = st.top();
    st.pop();
    Reverse(st);

    insertrev(st, top);
}

int main()
{

    return 0;
}