#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int key)
{
     int index=-1;
     int l=0, h=n-1;

     while (l<=h)
     {
          int mid=l+((h-l)/2);

          if (arr[mid]==key)
               return mid;
          else if (arr[mid]<key)
               l=mid+1;
          else
               h=mid-1;
     }

     return -1;

/*
     //For the below algo, even for `key=0`, the function is returning `0`, not `-1

     int mid=l+((h-l)/2);`
     
     while (arr[mid]!=key && mid>=l && mid<=h)
     {
          if (key>arr[mid])
          {
               l=mid+1;
               mid=l+((h-l)/2);
          }
          else if (key<arr[mid])
          {
               h=mid-1;
               mid=l+((h-l)/2);
          }
     }

     if (mid>=n)
     {
          return -1;
     }

     return mid;
*/
}

int main()
{
     int n;
     int arr[]={10,20,30,40,50,60};
     n=sizeof(arr)/sizeof(arr[0]);
     int key=20;

     int x=binarySearch(arr, n, key);
     cout<<"Element at index: "<<x;

     return 0;
}