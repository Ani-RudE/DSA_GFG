#include <bits/stdc++.h>
using namespace std;

void zeroEnd(int arr[], int n)
{
     int count=0;
     for (int i=0; i<n; ++i)
     {
          if (arr[i]!=0)
          {
               swap(arr[i], arr[count]);
               count+=1;
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
     // cin>>n;
     int arr[]={10, 8, 0, 0, 12, 0};
     n=sizeof(arr)/sizeof(arr[0]);
     
     zeroEnd(arr, n);
     printArray(arr, n);

     return 0;
}