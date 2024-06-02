// Using Binary Search - Recursive
#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int key, int l, int h)
{
     if (l>h)
          return -1;
     
     int mid = l + ((h - l) / 2);

     if (arr[mid] == key)
     {
          if (arr[mid-1]==key)
          {
               // binarySearch(arr, key, mid-2, mid+1); //Self
               binarySearch(arr, key, l, mid-1); //Given in video - If `arr[mid-1]==key` then the first occurance must be in the left half, hence we shift to the left half.
          }
          else
          {
               return mid;
          }
     }
     else if (arr[mid] < key)
          binarySearch(arr, key, mid + 1, h);
     else
          binarySearch(arr, key, l, mid - 1);
}

int main()
{
     int n;
     int arr[] = {10,10,15,20,20,20};
     n = sizeof(arr) / sizeof(arr[0]);
     int key = 20;

     int x = binarySearch(arr, key, 0, n - 1);
     cout << "First occurance index: " << x;

     return 0;
}