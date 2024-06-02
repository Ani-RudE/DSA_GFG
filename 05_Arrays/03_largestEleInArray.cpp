#include <bits/stdc++.h>
using namespace std;

int largestEleIndex(int n, int arr[])
{
     int max=INT_MIN, index;
     for (int i=0; i<n; ++i)
     {
          if (arr[i]>max)
          {
               max=arr[i];
               index=i;
          }
     }

     return index;
}

int main()
{
     int n;
     cin>>n;
     int arr[n];
     for (int i=0; i<n; ++i)
          cin>>arr[i];

     int x=largestEleIndex(n, arr);
     cout<<"Largest Element: "<<arr[x];
     cout<<"Largest Element's Index: "<<x<<endl;

     return 0;
}