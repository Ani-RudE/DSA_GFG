// Time Complexity: O(N log N)
// Auxiliary Space: O(N)
#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
     return ((a.second/a.first)>(b.second/b.first)); // Comparing the per unit value of an item
}

int getOptimal(pair<int, int> arr[], int n, int knapsackCapacity)
{
     sort(arr, arr+n, compare);
     int res=0, weight=0;

     for (int i=0; i<n && weight<=knapsackCapacity; ++i)
     {
          if ((knapsackCapacity-weight)>=arr[i].first) // Comparing remaining capacity with the weight of next most valueable item
          {
               res+=arr[i].second;
               weight+=arr[i].first;
          }
          else /* if ((knapsackCapacity-weight)<arr[i].first) */
          {
               res+=(knapsackCapacity-weight)*(arr[i].second/arr[i].first);
               // weight+=knapsackCapacity-weight;
               return res;
          }
     }

     return res;
}

int main()
{
     int n=3;
     pair<int, int> arr[]={{50,600}, {20,500}, {30,400}};
     int knapsackCapacity=70;

     int res=getOptimal(arr,n,knapsackCapacity);
     cout<<res;

     return 0;
}