#include <bits/stdc++.h>
using namespace std;

int rotatedArraySearch(int arr[], int n,  int key)
{
     int low=0, high=n-1;

     while (low<=high)
     {
          int mid=low+((high-low)/2);
          
          if (arr[mid]==key)
               return mid;
          else if (arr[mid]>=arr[low]) //Means left half is sorted
          {
               if (key<=arr[mid-1] && key>=arr[low]) //Key lies in the sorted left half
                    high=mid-1;
               else //Key lies in the unsorted right half
                    low=mid+1;
          }
          else //Right half is sorted
          {
               if (key>=arr[mid+1] && key<=arr[high]) //Key lies in the sorted right half
                    low=mid+1;
               else //Key lies in the unsorted left half
                    high=mid-1;
          }
     }

     return -1;
}

int main()
{
     int n;
     int arr[]={10,20,40,60,5,8};
     n=sizeof(arr)/sizeof(arr[0]);
     int key=5;
     int key2=6;

     cout<<rotatedArraySearch(arr, n, key)<<endl;
     cout<<rotatedArraySearch(arr, n, key2);

     return 0;
}