// Time Comp: O((search() Function) + (binarySearch)) = O(log(2*position) + log(position))
// Time Complexity: O(logN) 
// Auxiliary Space: O(1)
#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int key, int low, int high)
{
     while (low<=high)
     {
          int mid=low+((high-low)/2);

          if (arr[mid]==key)
               return mid;
          else if (arr[mid]<key)
               low=mid+1;
          else
               high=mid-1;
     }

     return -1;
}

int search(int arr[], int n,  int key)
{
     if (arr[0]==key)
          return 0;
     
     int i=1;

     while (arr[i]<key)
     {
          i=i*2; //We keep on multiplying this by 2, since the array is sorted, we stop the loop as soon as the value exceeds the key value, and then we apply binary search with `low` as the previous value of i, and high as the current value of i, as the key value will lie between these two indexes.
     }
     
     if (arr[i]==key)
          return i;
          
     return binarySearch(arr, n, key, (i/2)+1, i);
}

int main()
{
     int n;
     int arr[]={1,10,15,20,40,60,80,100,200,500,1000};
     n=sizeof(arr)/sizeof(arr[0]);
     int key=20;

     cout<<search(arr, n, key);

     return 0;
}