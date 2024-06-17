#include <iostream>
#include <queue>
using namespace std;

int main()
{
     queue<int> q;
     cout<<q.empty()<<endl;
     q.push(10);
     q.push(20);
     q.push(30);
     cout<<q.empty()<<endl;
     cout<<q.size()<<endl;
     cout<<q.front()<<endl;
     cout<<q.back()<<endl;
     q.pop();
     cout<<q.front()<<endl;
     cout<<q.size();

     return 0;
}

/*
Queue can be implemented on any of the underlying conatiner the provides the functionalities such as empty(), size(), front(), back(), push_back(), pop_front() in O(1) time.

There are two underlying containers that provide it - list and dequeue. (Vector does not provide pop_front() in O(1) time.)

By default Queue uses Dequeue container. Queue is a Container Adapter just like Stack, bcoz it works as an interface on top of other containers. 
*/