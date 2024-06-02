#include <bits/stdc++.h>
using namespace std;

void deletionOnArray(int n, int arr[], int key)
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

     for (int i=0; i<n; ++i)
     {
          cout<<arr[i]<<", ";
     }

     return;
}

int main()
{
     int n, key;
     cin>>n;
     int arr[n];

     for (int i=0; i<n; ++i)
          cin>>arr[i];

     cin>>key;

     deletionOnArray(n, arr, key);

     return 0;
}