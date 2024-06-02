#include <bits/stdc++.h>
using namespace std;

struct MyStack
{
     int *arr;
     int cap;
     int top;

     MyStack (int c)
     {
          cap=c;
          arr=new int[cap];
          top=-1;
     }

     void push(int x)
     {
          if (top==cap-1)
          {
               cout<<"Stack Full!"<<endl;
               return;
          }
          else
          {
               top+=1;
               arr[top]=x;
          }
     }

     int pop()
     {
          if (top==-1)
          {
               cout<<"Stack Empty!"<<endl;
               return -999;
          }
          else
          {
               int res=arr[top];
               top-=1;
               return res;
          }

     }

     int peek()
     {
          return arr[top];
     }

     int size()
     {
          return (top+1);
     }

     bool isEmpty()
     {
          return (top==-1);
     }
};

int main()
{
     MyStack s(5);
     s.push(10);
     s.push(20);
     s.push(30);
     s.push(40);
     s.push(50);
     s.push(60);
     cout<<s.pop()<<endl;
     cout<<s.peek()<<endl;

     return 0;
}