#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
public:
    stack<int> s1, s2;
    MyQueue()
    {
    }

    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        int p;
        if (!s2.empty()) // stack2 is not empty
        {
            p = s2.top();
            s2.pop();
        }
        else
        {
            while (!s1.empty())
            {
                int temp = s1.top();
                s1.pop();
                s2.push(temp);
            }
            p = s2.top();
            s2.pop();
        }
        return p;
    }

    int peek()
    {
        if (!s2.empty())
        {
            return s2.top();
        }
        while (!s1.empty())
        {
            int temp = s1.top();
            s1.pop();
            s2.push(temp);
        }
        return s2.top();
    }

    bool empty()
    {
        if (s1.empty() && s2.empty())
            return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main()
{

    return 0;
}