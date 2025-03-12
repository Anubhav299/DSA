#include <bits/stdc++.h>
using namespace std;

// Structure of a node in Queue
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

// And structure of MyQueue
struct MyQueue
{
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() { front = rear = NULL; }
};

// Function to push an element into the queue.
void MyQueue::push(int x)
{
    QueueNode *newNode = new QueueNode(x);
    if (!rear)
    {
        front = newNode;
        rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

// Function to pop front element from the queue.
int MyQueue ::pop()
{
    if (!front)
    {
        return -1;
    }
    int t = front->data;
    QueueNode *temp = front;
    front = front->next;
    if (!front)
    {
        rear = NULL;
    }
    delete (temp);
    return t;
}

int main()
{

    return 0;
}