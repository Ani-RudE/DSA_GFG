#include <bits/stdc++.h>
using namespace std;

int freqSortedArray(int arr[], int n)
{
     int count=0, x;

     for (int i=0; i<n; ++i)
     {     
          if (i==0)
          {
               x=arr[0];
               count+=1;
               continue;
          }
          else
          {
               if (arr[i]==x)
               {
                    count+=1;
               }
               else
               {
                    cout<<x<<" : "<<count<<endl;
                    count=1;
                    x=arr[i];
               }
          }

          if (i==(n-1))
          {
               cout<<x<<" : "<<count<<endl;
          }
     }

     return -1;
}

int main()
{
     int n;
     // int arr[]={10,10,10,25,30,30};
     // int arr[]={40,50,50,50};
     // int arr[]={10,10};
     int arr[]={1};
     n=sizeof(arr)/sizeof(arr[0]);

     freqSortedArray(arr, n);

     return 0;
}