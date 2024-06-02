#include <bits/stdc++.h>
using namespace std;

int peakElementBinary(int arr[], int n)
{
     int low=0, high=n-1;

     while (low<=high)
     {
          int mid=low+((high-low)/2);

          if ((arr[0]>arr[1] || arr[mid]>=arr[mid+1]) && (arr[n-1]>=arr[n-2] || arr[mid]>=arr[mid-1]))
               return arr[mid];
          else if ()
     }

     return -1;
}

int main( )
{
     int n;
     int arr[]={10,20,15,5,23,90,67};
     n=sizeof(arr)/sizeof(arr[0]);

     cout<<peakElementBinary(arr, n);

     return 0;
}