#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int key, int l, int h)
{
     if (l>h)
          return -1;
     
     int mid = l + ((h - l) / 2);

     if (arr[mid] == key)
          return mid;
     else if (arr[mid] < key)
          binarySearch(arr, key, mid + 1, h);
     else
          binarySearch(arr, key, l, mid - 1);
}

int main()
{
     int n;
     int arr[] = {10, 20, 30, 40, 50, 60};
     n = sizeof(arr) / sizeof(arr[0]);
     int key = 20;

     int x = binarySearch(arr, key, 0, n - 1);
     cout << "Element at index: " << x;

     return 0;
}