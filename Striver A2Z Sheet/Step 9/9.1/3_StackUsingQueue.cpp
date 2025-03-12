#include <bits/stdc++.h>
using namespace std;

class MyStack
{
public:
    queue<int> q;
    MyStack()
    {
    }

    void push(int x)
    {
        int n = q.size();
        q.push(x);
        while (--n >= 0)
        {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
    }

    int pop()
    {
        int temp = q.front();
        q.pop();
        return temp;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main()
{

    return 0;
}