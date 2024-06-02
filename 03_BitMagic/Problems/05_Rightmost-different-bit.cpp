//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
     // Function to find the first position with different bits.
     int posOfRightMostDiffBit(int m, int n)
     {
          // Your code here
          if (m == n)
               return -1;

          int count = 1, x = 0;

          while (x == 0)
          {
               if ((m & 1) == (n & 1))
               {
                    count += 1;
                    m = m >> 1;
                    n = n >> 1;
               }
               else
               {
                    x = 1;
               }
          }

          return count;
     }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
     int t;
     cin >> t; // input number of testcases
     while (t--)
     {
          int m, n;
          cin >> m >> n; // input m and n
          Solution ob;
          cout << ob.posOfRightMostDiffBit(m, n) << endl;
     }
     return 0;
}
// } Driver Code Ends