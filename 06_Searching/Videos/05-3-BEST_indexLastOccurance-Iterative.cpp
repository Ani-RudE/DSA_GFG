#include <bits/stdc++.h>
using namespace std;

int lastOccuranceIterative(int arr[], int n, int key)
{
     int low=0, high=n-1;

     while (low<=high)
     {
          int mid=low+((high-low)/2);

          if (arr[mid]>key)
               high=mid-1;
          else if (arr[mid]<key)
               low=mid+1;
          else
          {
               if (mid==n-1 || arr[mid]!=arr[mid+1])
               {
                    return mid;
               }
               else
               {
                    low=mid+1;
               }
          }
     }

     return -1;
}

int main()
{
     int n;
     int arr[] = {5, 10, 10, 10, 10, 20, 20};
     n = sizeof(arr) / sizeof(arr[0]);
     int key = 20;

     cout << lastOccuranceIterative(arr, n, key);

     return 0;
}