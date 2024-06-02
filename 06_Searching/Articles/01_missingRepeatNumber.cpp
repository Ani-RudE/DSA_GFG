/*
Description: Given an unsorted array of size n. Array elements are in the range from 1 to n. One number from set {1, 2, …n} is missing and one number occurs twice in the array. Our task is to find these two numbers.

Input                    Output
[2, 3, 2, 1, 5]          4 2
*/

// Article Link: https://www.geeksforgeeks.org/batch/dsa-self-paced/track/DSASP-Searching/article/MjYwMg%3D%3D
#include <bits/stdc++.h>
using namespace std;

int repeatSearch(int arr[], int n)
{
     int index=-1;
     
     for (int i=0; i<n-1; ++i)
     {
          if (arr[i]==arr[i+1])
          {
               cout<<"Repeat Element: "<<arr[i]<<endl;
          }
          else if (arr[i+1]!=arr[i]+1)
          {
               cout<<"Missing Element: "<<arr[i]+1;
          }
     }

     return index;
}

int main()
{
     int n;
     int arr[]={2, 3, 2, 1, 5};
     n=sizeof(arr)/sizeof(arr[0]);

     sort(arr, arr+n);

     int x=repeatSearch(arr, n);

     return 0;
}