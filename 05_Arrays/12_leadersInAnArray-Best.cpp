// One drawback of this approach is that it prints the leaders from left to right.
// If we want the ouput of leaders from left to right, then we can store the numbers in a array and reverse it.
#include <bits/stdc++.h>
using namespace std;

void printLeaders(int arr[], int n)
{
     int lead=arr[n-1];
     cout<<lead<<" ";

     for (int i=n-2; i>=0; --i) // i starts from `i=n-2` bcoz the `(n-1)th` element is always a leader, and hence it is already printed before initializing the loop. Even tho using `(n-1)` won't change the results.
     {
          if (arr[i]>lead) // As per GFG problem (link below), this should be taken as `(lead<=a[i])`, the equality should also be considered.
          {
               lead=arr[i];
               cout<<lead<<" ";
          }
     }
}

int main()
{
     int arr[] = {7, 10, 4, 10, 6, 5, 2};
     int n = sizeof(arr) / sizeof(arr[0]);

     printLeaders(arr, n);
     return 0;
}

/*
     GFG Link: https://www.geeksforgeeks.org/batch/dsa-self-paced/track/DSASP-Arrays/problem/leaders-in-an-array-1587115620
     Leaders might be defined as any element that does not have a greater element to its right, equal might work.
*/