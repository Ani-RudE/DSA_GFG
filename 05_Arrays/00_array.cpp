#include <bits/stdc++.h>
using namespace std;

int fnc(int arr[], int n)
{
     int x;
     

     return x;
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

int main()
{
     int n;
     cin>>n;
     int arr[]={1};
     n=sizeof(arr)/sizeof(arr[0]);
     for (int i=0; i<n; ++i)
     {
          cin>>arr[i];
     }

     int x=fnc(arr, n);
     printArray(arr, n);

     return 0;
}