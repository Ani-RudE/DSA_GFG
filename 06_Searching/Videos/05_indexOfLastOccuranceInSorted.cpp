#include <bits/stdc++.h>
using namespace std;

int lastOccurance(int arr[], int n,  int key)
{
     for (int i=n-1; i>=0; --i)
     {
          if (arr[i]==key)
               return i;
     }

     return -1;
}

int main()
{
     int n;
     int arr[]={10,15,20,20,40,40};
     n=sizeof(arr)/sizeof(arr[0]);
     int key=20;

     cout<<lastOccurance(arr, n, key);

     return 0;
}