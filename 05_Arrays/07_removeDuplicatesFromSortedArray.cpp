#include <bits/stdc++.h>
using namespace std;

int fnc(int arr[], int n)
{
     int temp[n];
     temp[0]=arr[0];
     int res=1;
     
     for (int i=1; i<n; ++i)
     {
          if (temp[res-1]!=arr[i])
          {
               temp[res]=arr[i];
               res+=1;
          }
               
     }

     for (int i=0; i<res; ++i)
     {
          arr[i]=temp[i];
     }

     for (int i=0; i<res; ++i)
     {
          std::cout<<arr[i]<<" ";
     }

     std::cout<<endl;

     return res;
}

int main()
{
     int n;
     cin>>n;
     int arr[n];
     for (int i=0; i<n; ++i)
     {
          cin>>arr[i];
     }

     std::sort(arr, arr+n);

     int x=fnc(arr, n);
     std::cout<<"Unique Elements: "<<x<<endl;

     return 0;
}