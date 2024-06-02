#include <bits/stdc++.h>
using namespace std;

int sqRoot(int n)
{
     int low=1, high=n;
     int ans=-1;

     while (low<=high)
     {
          int mid=low+((high-low)/2);
          int midSq=mid*mid;

          if (midSq==n)
               return mid;
          else if (midSq>n)
               high=mid-1;
          else
          {
               low=mid+1;
               ans=mid;
          }
     }

     return ans;
}

int main()
{
     int n=14;

     cout<<sqRoot(n);

     return 0;
}