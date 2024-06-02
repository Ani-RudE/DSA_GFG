#include <bits/stdc++.h>
using namespace std;

int maxDifference(int arr[], int n)
{
     int maxDiff=arr[1]-arr[0];
     int minVal=arr[0];
     
     for (int i=1; i<n; ++i)
     {
          maxDiff=max(maxDiff, arr[i]-minVal);
          minVal=min(minVal, arr[i]);
     }

     return maxDiff;
}

int main()
{
     int n;
     int arr[]={2,3,10,6,4,8,1};
     n=sizeof(arr)/sizeof(arr[0]);
     int x=maxDifference(arr, n);
     cout<<x;

     return 0;
}