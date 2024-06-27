#include <bits/stdc++.h>
using namespace std;

int lcs(vector<vector<int>> &memo, string s1, string s2, int m, int n) {
     if (memo[m][n]!=-1)
          return memo[m][n];
     if (m==0 || n==0) {
          memo[m][n]=0;
     } else {
          if (s1[m-1]==s2[n-1]) {
               memo[m][n] = 1+lcs(memo, s1, s2, m-1, n-1);
          } else {
               memo[m][n] = max(lcs(memo, s1, s2, m-1, n), lcs(memo, s1, s2, m, n-1));
          }
     }

     return memo[m][n];
}

int main()
{
     string s1="AXYZ";
     string s2="BAZ";
     int m=4, n=3;
     vector<vector<int>> memo(m+1, vector<int>(n+1, -1));

     cout<<lcs(memo,s1, s2, m, n);

     return 0;
}