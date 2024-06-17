// #include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

queue<int> reverseQueueIterative(queue<int> &q)
{
     stack<int> s;
     while (q.empty()==false)
     {
          s.push(q.front());
          q.pop();
     }

     while (s.empty()==false)
     {
          q.push(s.top());
          s.pop();
     }

     return q;
}

void printQueue(queue<int> &q)
{
     for (int i=1; i<=q.size(); ++i)
     {
          int x=q.front();
          q.pop();
          q.push(x);
          cout<<x<<" ";
     }

     cout<<endl;

     return;
}

int main()
{
     queue<int> q;
     q.push(10);
     q.push(20);
     q.push(30);
     q.push(40);
     q.push(50);
     printQueue(q);

     reverseQueueIterative(q);
     printQueue(q);

     return 0;
}