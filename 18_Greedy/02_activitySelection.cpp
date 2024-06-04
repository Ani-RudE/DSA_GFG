#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
     return (a.second<b.second);
}

int maxActivities(pair <int, int> arr[], int n)
{
     sort(arr, arr+n, compare);
     int res=1;
     int prev=0;

     for (int current=1; current<n; ++current)
     {
          if (arr[current].first>=arr[prev].second)
          {
               res+=1;
               prev=current;
          }
     }

     return res;
}


int main()
{
     int n=3;
     pair<int, int> arr[n]={{12,25}, {10,20}, {20,30}};

     int res=maxActivities(arr, n);
     cout<<res;
     
     return 0;
}