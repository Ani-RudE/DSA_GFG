#include <bits/stdc++.h>
using namespace std;

int firstOccurance(int arr[], int n, int key)
{
     int low = 0, high = n - 1;

     while (low <= high)
     {
          int mid = low + ((high - low) / 2);

          if (arr[mid] > key)
               high = mid - 1;
          else if (arr[mid] < key)
               low = mid + 1;
          else
          {
               if (mid == 0 || arr[mid] != arr[mid - 1])
                    return mid;
               else
                    high = mid - 1;
          }
     }

     return -1;
}

int lastOccurance(int arr[], int n, int key)
{
     int low = 0, high = n - 1;

     while (low <= high)
     {
          int mid = low + ((high - low) / 2);

          if (arr[mid] > key)
               high = mid - 1;
          else if (arr[mid] < key)
               low = mid + 1;
          else
          {
               if (mid == n - 1 || arr[mid] != arr[mid + 1])
               {
                    return mid;
               }
               else
               {
                    low = mid + 1;
               }
          }
     }

     return -1;
}

int totalOccurance(int arr[], int n, int key)
{
     int first = firstOccurance(arr, n, key);
     if (first == -1)
          return -1;
     else
          return (lastOccurance(arr, n, key) - first + 1);

     return -1;

     /*
          int first=firstOccurance(arr, n, key);
          int last=lastOccurance(arr, n, key);
          cout<<first<<" "<<last<<endl;

          if (first==-1 || last==-1)
               return -1;
          else
               return (abs(last-first+1));

          return -1;
     */
}

int main()
{
     int n;
     int arr[] = {10, 20, 20, 20, 30, 30};
     // int arr[]={10,10,10,10,10};
     n = sizeof(arr) / sizeof(arr[0]);
     int key = 20;
     // int key=10;

     cout << totalOccurance(arr, n, key);

     return 0;
}