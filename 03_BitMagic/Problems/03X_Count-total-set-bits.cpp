// Count total set bits
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
     // n: input to count the number of set bits
     // Function to return sum of count of set bits in the integers from 1 to n.
     int countSetBitsOfANum(int n)
     {
          int k = 0;

          while (n != 0)
          {

               if ((n & 1) == 1)
               {
                    k += 1;
                    n = n >> 1;
               }
               else
               {
                    n = n >> 1;
               }
          }
          return k;
     }

     int countSetBits(int n)
     {
          // Your logic here
          int bitsCount = 0;

          for (int i = 1; i <= n; i++)
          {
               bitsCount += countSetBitsOfANum(i);
          }

          return bitsCount;
     }
};

//{ Driver Code Starts.

// Driver code
int main()
{
     int t;
     cin >> t;   // input testcases
     while (t--) // while testcases exist
     {
          int n;
          cin >> n; // input n
          Solution ob;
          cout << ob.countSetBits(n) << endl; // print the answer
     }
     return 0;
}

// } Driver Code Ends