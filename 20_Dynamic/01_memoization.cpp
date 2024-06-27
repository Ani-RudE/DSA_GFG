#include <bits/stdc++.h>
using namespace std;

int fib(vector<int> &memo, int n){
     if (memo[n] == -1) {
          int res;
          if (n == 0 || n == 1) {
               res = n;
          } else {
               res = fib(memo, n-1) + fib(memo, n-2);
          }
          memo[n] = res;
     }
     return memo[n];
}

int main()
{
     int n = 5;
     vector<int> memo(n+1, -1);
     // vector<int> memo(n+1); // Resize the vector to hold n+1 elements
     // for (int i = 0; i <= n; ++i) {
     //      memo[i] = -1; // Initialize each element to -1
     // }

     cout << fib(memo, n);

     return 0;
}
