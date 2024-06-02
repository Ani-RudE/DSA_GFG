#include <bits/stdc++.h>
using namespace std;

int ternarySearch(int l, int r, int key, int ar[])
{
     while (r >= l)
     {
          // Find mid1 and mid2
          int mid1 = l + (r - l) / 3;
          int mid2 = r - (r - l) / 3;

          // Check if key is present at any mid
          if (ar[mid1] == key)
          {
               return mid1;
          }
          if (ar[mid2] == key)
          {
               return mid2;
          }

          // Since key is not present at mid,
          // check in which region it is present
          // then repeat the Search operation
          // in that region

          if (key < ar[mid1])
          {
               // The key lies in between l and mid1
               r = mid1 - 1;
          }
          else if (key > ar[mid2])
          {
               // The key lies in between mid2 and r
               l = mid2 + 1;
          }
          else
          {
               // The key lies in between mid1 and mid2
               l = mid1 + 1;
               r = mid2 - 1;
          }
     }

     // Key not found
     return -1;
}

int main()
{
     int n;
     int arr[] = {10, 20, 30, 40, 50, 60};
     n = sizeof(arr) / sizeof(arr[0]);
     int key = 20;

     int x = ternarySearch(0, n-1, key, arr);
     cout << "Element at index: " << x;

     return 0;
}