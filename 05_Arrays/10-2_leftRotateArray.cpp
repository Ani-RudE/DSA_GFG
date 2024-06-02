//Time: O(n)
//Space: O(d)
#include <bits/stdc++.h>
using namespace std;

void leftRotateArray(int arr[], int n, int d)
{
     int save[d], index=0;

     for (int i=0; i<d; ++i)
     {
          save[i]=arr[i];
     }

     for (int i=0; i<n; ++i)
     {
          if (i<n-d)
          {
               arr[i]=arr[i+2];
          }
          else
          {
               arr[i]=save[index];
               index+=1;
          }
     }

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
          d=d-n;
     }

     leftRotateArray(arr, n, d);
     printArray(arr, n);

     return 0;
}