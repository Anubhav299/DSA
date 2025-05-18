#include <bits/stdc++.h>
using namespace std;

/*
Intuition : We sort the tasks by frequency by storing them in MaxHeap
then we execute the highest frequency task first and go till the cooldown 'n' is exhausted 
(in this time(loop) we try to fit other tasks if possible), once the cooldown is reached, again the first task is executed and this continues till the MaxHeap gets empty
*/
int leastInterval(vector<char> &tasks, int n)
{
    // getting frequency of all tasks
    vector<int> taskFreq(26, 0);
    for (char it : tasks)
    {
        taskFreq[it - 'A']++;
    }

    int time = 0; // resultant time that needs to be computed

    priority_queue<int> sortedFreq;
    for (int i = 0; i < 26; i++)
    {
        if (taskFreq[i] != 0)
        {
            sortedFreq.push(taskFreq[i]);
        }
    }

    while (sortedFreq.empty() != true)
    {
        vector<int> tempFreq;

        //for 
        for (int i = 1; i <= n + 1; i++)
        {
            if (sortedFreq.empty() != true)
            {
                int freq = sortedFreq.top();                //getting the task with the highest frequency
                sortedFreq.pop();
                freq--;
                tempFreq.push_back(freq);               //storing it somewhere so that can be pushed later
            }
        }


        for (auto f : tempFreq)
        {
            if (f > 0)
                sortedFreq.push(f);
        }

        if (sortedFreq.empty() == true)
        {
            time += tempFreq.size();
        }
        else
        {
            time += (n + 1);
        }
    }
    return time;
}
int main()
{

    return 0;
}