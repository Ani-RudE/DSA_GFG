//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
     // Function to find floor of x
     // n: size of vector
     // x: element whose floor is to find
     int findFloor(vector<long long> v, long long n, long long x)
     {

          // Your code here
          // if (x<v[0] || x>v[n-1])
          //     return -1;

          // for (int i=0; i<n; ++i)
          // {
          //     if (v[i]==x)
          //         return i;

          //     if (v[i]>x)
          //         return (i-1);
          // }

          if (x < v[0])
               return -1;

          int start = 0, end = n - 1;

          while (start <= end)
          {
               int mid = start + ((end - start) / 2);

               if (v[mid] == x)
                    return mid;
               if (v[mid] < x)
                    start = mid + 1;
               else
                    end = mid - 1;
          }

          return end;
     }
};

//{ Driver Code Starts.

int main()
{

     long long t;
     cin >> t;

     while (t--)
     {
          long long n;
          cin >> n;
          long long x;
          cin >> x;

          vector<long long> v;

          for (long long i = 0; i < n; i++)
          {
               long long temp;
               cin >> temp;
               v.push_back(temp);
          }
          Solution obj;
          cout << obj.findFloor(v, n, x) << endl;
     }

     return 0;
}
// } Driver Code Ends