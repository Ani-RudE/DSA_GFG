#include <bits/stdc++.h>
using namespace std;

int main()
{
     int n;
     cin>>n;
     int arr[n];
     for (int i=0; i<n; ++i)
     {
          cin>>arr[i];
     }

     int l, r, x;

     for (int i=0; i<n/2; ++i)
     {
          // l=arr[i];
          // r=arr[n-1-i];
          // arr[i]=r;
          // arr[n-1-i]=l;
          
          x=arr[i];
          arr[i]=arr[n-1-i];
          arr[n-1-i]=x;
     }

     for (int i=0; i<n; ++i)
     {
          cout<<arr[i]<<" ";
     }

     return 0;
}