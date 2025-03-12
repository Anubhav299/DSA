#include <bits/stdc++.h>
using namespace std;

struct StackNode
{
    int data;
    StackNode *next;

    StackNode(int a)
    {
        data = a;
        next = NULL;
    }
};

class MyStack 
{
  private:
    StackNode *top;

  public:
    void push(int x) 
    {
        StackNode *newNode = new StackNode(x);
        newNode->next = top;
        top = newNode;
    }

    int pop() 
    {
        if(!top)
        {
            return -1;
        }
        int t = top->data;
        StackNode *temp = top;
        top = top->next;
        delete(temp);
        return t;
    }

    MyStack() { top = NULL; }
};

int main()
{
    
    return 0;
}

