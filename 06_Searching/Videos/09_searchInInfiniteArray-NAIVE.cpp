#include <bits/stdc++.h>
using namespace std;

int search(int arr[], int n,  int key)
{
     int i=0;
     while (true)
     {
          if (arr[i]==key)
               return i;
          else if (arr[i]>key)
               return -1;
          
          i+=1;
     }

     return -1;
}

int main()
{
     int n;
     int arr[]={1,10,15,20,40,60,80,100,200,500,1000};
     n=sizeof(arr)/sizeof(arr[0]);
     int key=20;

     cout<<search(arr, n, key);

     return 0;
}