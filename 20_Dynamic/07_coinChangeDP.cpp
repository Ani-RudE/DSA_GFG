#include <bits/stdc++.h>
using namespace std;

int countWays(vector<int> &coins, int n, int s) {
     int dp[n+1][s+1];

     for (int i=0; i<n; ++i) {
          dp[i][0]=1;
     }
     for (int j=1; j<s; ++j) {
          dp[0][j]=0;
     }

     for (int i=1; i<=n; ++i) {
          for (int j=1; j<=s; ++j) {
               dp[i][j]=dp[i-1][j];

               if (coins[i-1]<=j) {
                    dp[i][j]+=dp
               }
          }
     }
}

int main()
{
     vector<int> coins={2,5,3};
     int n=3, s=5;
     cout<<countWays(coins, n, s);

     return 0;
}