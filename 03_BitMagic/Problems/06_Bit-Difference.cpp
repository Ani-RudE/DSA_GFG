//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
     // Function to find number of bits needed to be flipped to convert A to B
     int countSetBits(int n)
     {
          if (n == 0)
               return 0;
          else
               return ((n & 1) + countSetBits(n >> 1));
     }

     int countBitsFlip(int a, int b)
     {

          // Your logic here
          int x = a ^ b;
          int count = countSetBits(x);

          return count;
     }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
     int t;
     cin >> t;   // input the testcases
     while (t--) // while testcases exist
     {
          int a, b;
          cin >> a >> b; // input a and b

          Solution ob;
          cout << ob.countBitsFlip(a, b) << endl;
     }
     return 0;
}
// } Driver Code Ends