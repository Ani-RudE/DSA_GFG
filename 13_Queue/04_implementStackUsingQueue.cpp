#include <iostream>
#include <queue>
using namespace std;

struct Stack
{
     queue<int> q1, q2;
     void pop() { q1.pop(); }
     void push(int x)
     {
          while (q1.empty()==false)
          {
               q2.push(q1.front());
               q1.pop();
          }

          q1.push(x);
          while (q2.empty()==false)
          {
               q1.push(q2.front());
               q2.pop();
          }
     }

     int top() { return q1.front(); }
     int size() { return q1.size(); }
     bool isEmpty() { return (q1.size()==0); }
};

int main()
{
     Stack s;
     cout<<s.isEmpty()<<endl;
     cout<<s.size()<<endl;
     s.push(5);
     s.push(10);
     s.push(15);
     cout<<s.isEmpty()<<endl;
     cout<<s.size()<<endl;
     cout<<s.top()<<endl;
     s.pop();
     cout<<s.size()<<endl;
     cout<<s.top()<<endl;

     return 0;
}