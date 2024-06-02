#include <bits/stdc++.h>
using namespace std;

int deletionOnArray(int n, int arr[], int key)
{
     int keyIndex=-1;

     for (int i=0; i<n; ++i)
     {
          if (key==arr[i])
          {
               keyIndex=i;
               break;
          }
     }

     for (int i=keyIndex; i<n; ++i)
     {
          arr[i]=arr[i+1];
     }

     return (n-1);
}

int main()
{
     int n, key;
     cin>>n;
     int arr[n];

     for (int i=0; i<n; ++i)
          cin>>arr[i];

     cin>>key;

     int newSize=deletionOnArray(n, arr, key);
     int newArr[newSize];

     for (int i=0; i<newSize; ++i)
     {
          newArr[i]=arr[i];
          cout<<newArr[i]<<" ";
     }

     return 0;
}