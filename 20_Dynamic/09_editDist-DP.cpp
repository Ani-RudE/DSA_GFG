 #include <bits/stdc++.h>
using namespace std;

int editDist(string s1, string s2, int m, int n) {
     vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
     for (int i=0; i<=m; ++i) {
          dp[i][0]=i;
     }

     for (int j=0; j<=n; ++j) {
          dp[0][j]=j;
     }
     
     for (int i=1; i<=m; ++i) {
          for (int j=1; j<=n; ++j) {
               if (s1[i-1]==s2[j-1]) {
                    dp[i][j]=dp[i-1][j-1];
               } else {
                    dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
               }
          }
     }

     return dp[m-1][n-1];
}

int main()
{
     string s1="horse";
     string s2="ros";
     int m=s1.length(), n=s2.length();
     cout<<editDist(s1, s2, m, n);

     return 0;
}