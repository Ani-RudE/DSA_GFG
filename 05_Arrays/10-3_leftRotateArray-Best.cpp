//Time: O(n)
//Space: O(1)
#include <bits/stdc++.h>
using namespace std;

void reverseArray(int arr[], int low, int high)
{
     while (low<high)
     {
          swap(arr[low], arr[high]);
          low+=1;
          high-=1;
     }
}

/*
     This reverse wont work as we are reversing parts of an array, not the complete array.
     For case like `reverseArray(arr, n-d, n-1);`, where n-d=3 and n-1=4, so, left=3 and right=4
     During the first iteration itself the condition for i, ie, `i=left` and `i<right/2` will fail hence the sub-array won't get reversed and we will see a wrong output.

// void reverseArray(int arr[], int left, int right)
// {
//      for (int i=left; i<=right/2; ++i)
//      {
//           swap(arr[i], arr[right-i]);
//      }
// }
*/

void leftRotateArray(int arr[], int n, int d)
{
     reverseArray(arr, 0, n-1);
     reverseArray(arr, 0, n-1-d);
     reverseArray(arr, n-d, n-1);

     /*
          Another way of passing the parameters to get the same output

     reverse(arr, 0, d-1);
     reverseArray(arr, d, n-1);
     reverseArray(arr, 0, n-1);
     */

     return;
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

int main()
{
     int n;
     int arr[]={1, 2, 3, 4, 5};
     n=sizeof(arr)/sizeof(arr[0]);
     int d=2;
     if (d>n)
     {
          d=d%n;
     }

     leftRotateArray(arr, n, d);
     printArray(arr, n);

     return 0;
}