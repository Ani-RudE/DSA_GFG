#include <bits/stdc++.h>
using namespace std;

int firstOccurance(int arr[], int n,  int key)
{
     for (int i=0; i<n; ++i)
     {
          if (arr[i]==key)
               return i;
     }

     return -1;
}

int main()
{
     int n;
     int arr[]={1,10,10,10,20,20,40};
     // int arr[]={10,20,30};
     n=sizeof(arr)/sizeof(arr[0]);
     int key=20;
     // int key=15;

     int x=firstOccurance(arr, n, key);
     cout<<"First occurance of Element "<<key<<" is at index: "<<x;

     return 0;
}