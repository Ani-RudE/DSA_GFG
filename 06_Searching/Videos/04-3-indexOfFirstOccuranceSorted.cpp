// Using Binary Search - Iterative
#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int key)
{
     int l=0, h=n-1;

     while (l<=h)
     {
          int mid=l+((h-l)/2);

          if (arr[mid]<key)
               l=mid+1;
          else if (arr[mid]>key)
               h=mid-1;
          else
          {
               if (arr[mid]==key && arr[mid]!=arr[mid-1])
               {
                    return mid;
               }
               else
               {
               /*
                    h=mid+1;
                    l=mid-1;
               */
              
                    h=mid-1;
               }
          }
     }

     return -1;
}

int main()
{
     int n;
     int arr[] = {10,10,15,20,20,20};
     n = sizeof(arr) / sizeof(arr[0]);
     int key = 20;

     int x = binarySearch(arr, key, n);
     cout << "First occurance index: " << x;

     return 0;
}