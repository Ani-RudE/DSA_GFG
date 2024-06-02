// Explanation
// The logic behind this approach is that if a number is a power of 2, it will have only one bit set to 1 in its binary representation,
// and subtracting 1 from it will result in a binary number with all bits flipped to the right of that one bit. Performing a bitwise
// AND between these two numbers will result in O, indicating that the number is a power of 2.
// However, there is a problem with this approach when the input is O. In that case, the function will return true, even though O
// is not a power of 2. This is because O is the only number whose binary representation has no bits set to 1, so subtracting 1
// from it will result in a binary number with all bits set to 1, and performing a bitwise AND between O and (0-1) will also result
// in O.
// Therefore, the given function is incorrect as it does not handle the special case of O. To fix this, we need to add a separate
// check for O at the beginning of the function and return false if the input is O.

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
     // Function to check if given number n is a power of two.
     bool isPowerofTwo(long long n)
     {

          // Your code here
          if (n == 0)
               return 0;

          return (!(n & (n - 1)));
     }
};

//{ Driver Code Starts.

// Driver code
int main()
{

     int t;
     cin >> t; // testcases

     for (int i = 0; i < t; i++)
     {
          long long n; // input a number n
          cin >> n;

          Solution ob;
          if (ob.isPowerofTwo(n)) // Now, if log2 produces an integer not decimal then we are sure raising 2 to this value
               cout << "YES" << endl;
          else
               cout << "NO" << endl;
     }

     return 0;
}

// } Driver Code Ends