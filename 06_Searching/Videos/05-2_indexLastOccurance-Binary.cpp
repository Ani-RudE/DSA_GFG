// REFER FOR SOLUTION: https://www.geeksforgeeks.org/batch/dsa-self-paced/track/DSASP-Searching/article/NzIxNA%3D%3D
#include <bits/stdc++.h>
using namespace std;

// int lastOccuranceBinary(int arr[], int key, int l, int h, int n)
// {
//      if (l>h)
//           return -1;

//      int mid = l + ((h - l) / 2);

//      if (arr[mid] == key)
//      {
//           if ((mid==(n-1) || key<arr[mid+1]) && (arr[mid] == key))
//           {
//                return mid;
//           }
//           else
//           {
//                lastOccuranceBinary(arr, key, mid + 1, h, n);
//           }
//      }
//      else if (arr[mid] < key)
//           lastOccuranceBinary(arr, key, mid + 1, h, n);
//      else
//           lastOccuranceBinary(arr, key, l, mid - 1, n);

//      return -1;
// }

// int lastOccuranceBinary(int arr[], int x, int low, int high, int n)
// {
//      if (high >= low)
//      {
//           int mid = low + (high - low) / 2;
//           if ((mid == n - 1 || x < arr[mid + 1]) && arr[mid] == x)
//                return mid;
//           else if (x < arr[mid])
//                return lastOccuranceBinary(arr, low, (mid - 1), x, n);
//           else
//                return lastOccuranceBinary(arr, (mid + 1), high, x, n);
//      }
//      return -1;
// }

/* ---------- THIS FUNCTION IS WORKING FINE ----------*/
int lastOccuranceBinary(int arr[], int n, int key, int low, int high)
{
     if (low>high)
          return -1;
     
     int mid=low+((high-low)/2);

     if (arr[mid]>key)
          return lastOccuranceBinary(arr, n, key, low, mid-1);
     if (arr[mid]<key)
          return lastOccuranceBinary(arr, n, key, mid+1, high);
     else
     {
          if (mid==n-1 || arr[mid]!=arr[mid+1])
               return mid;
          else
               return lastOccuranceBinary(arr, n, key, mid+1, high);
     }
}

int main()
{
     int n;
     int arr[] = {5, 10, 10, 10, 10, 20, 20};
     n = sizeof(arr) / sizeof(arr[0]);
     int key = 20;

     cout << lastOccuranceBinary(arr, n, key, 0, n-1);

     return 0;
}

/* ---------- SOLUTION ---------- */
/*
     int last(int arr[], int low, int high, int x, int n)
     {
     	if (high >= low) {
     		int mid = low + (high - low) / 2;
     		if ((mid == n - 1 || x < arr[mid + 1])
     			&& arr[mid] == x)
     			return mid;
     		else if (x < arr[mid])
     			return last(arr, low, (mid - 1), x, n);
     		else
     			return last(arr, (mid + 1), high, x, n);
     	}
     	return -1;
     }
*/