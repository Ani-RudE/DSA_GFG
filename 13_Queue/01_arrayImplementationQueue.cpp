#include <bits/stdc++.h>
using namespace std;

struct Queue{
     int size, cap;
     int *arr;
     Queue (int c)
     {
          cap=c;
          size=0;
          arr=new int[cap];
     }

     void enque(int x) {
          if (isFull())
               return;
          
          arr[size]=x;
          size+=1;
     }
     void deque() {
          if (isEmpty())
               return;
          
          for (int i=0; i<size; ++i)
               arr[i]=arr[i+1];
          
          size-=1;
     }
     int getFront() { return arr[0]; }
     int getRear() { return arr[size-1]; }
     bool isFull() { return (size==cap); }
     bool isEmpty() { return (size==0); }
     int size() { return size; }
};