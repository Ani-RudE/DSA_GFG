#include <bits/stdc++.h>
using namespace std;

int peakElement(int arr[], int n)
{
     if (arr[0]>=arr[1])
          return arr[0];
     if (arr[n-1]>=arr[n-2])
          return arr[n-1];

     for (int i=1; i<n-1; ++i)
     {
          if (arr[i]>=arr[i-1] && arr[i]>=arr[i+1])
          {
               return arr[i];

               // If we wish to print all the peak elements
               // cout<<arr[i]<<" ";
               // i+=2;
          }
     }

     return -1;
}

int main( )
{
     int n;
     int arr[]={10,20,15,5,23,90,67};
     n=sizeof(arr)/sizeof(arr[0]);

     cout<<peakElement(arr, n);

     return 0;
}