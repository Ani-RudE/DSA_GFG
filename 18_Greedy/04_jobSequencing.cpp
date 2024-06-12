/*
Rules:
  i. One unit of time by every job.
 ii. Only one job can be assigned at a time.
iii. Time starts with 0.
*/
#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
     if (a.first!=b.first)
          return (a.first<b.first);
     else
          return (a.second>b.second);
}

int jobSequence(pair<int, int> arr[], int n)
{
     sort(arr, arr+n, compare);
     cout<<"{ ";
     for (int i=0; i<4; ++i) //Checking the sorted order
     {
          cout<<"("<<arr[i].first<<","<<arr[i].second<<"), ";
     }
     cout<<"}: ";

     int res=0, time=0;
     for (int i=0; i<n; ++i)
     {
          if (time<arr[i].first)
          {
               res+=arr[i].second;
               time+=1;
          }
     }

     return res;
}

int main()
{
     int n=4;
     pair<int, int> arr[]={{4,70}, {1,80}, {1,30}, {1,100}};
     int res1=jobSequence(arr,n);
     cout<<res1<<endl;

     int n2=4;
     pair<int, int> arr2[]={{2,50}, {2,60}, {3,20}, {3,30}};
     int res2=jobSequence(arr2,n2);
     cout<<res2<<endl;

     int n3=5;
     pair<int, int> arr3[]={{2,100}, {1,50}, {2,10}, {1,20}, {3,30}};
     int res3=jobSequence(arr3,n3);
     cout<<res3;

     return 0;
}
/*
Another approach:
  i. Sort jobs in decreasing order of profit.
 ii. Initialize the result as first job in the sorted list. Assign the latest possible slot.
iii. Do the following for the remaining (n-1) jobs
     a. If this job can not be added, ignore it.
     b. Else add it to the latest possible slot

Link: https://www.geeksforgeeks.org/batch/dsa-self-paced/track/DSASP-Greedy/article/MjM5Ng%3D%3D
*/