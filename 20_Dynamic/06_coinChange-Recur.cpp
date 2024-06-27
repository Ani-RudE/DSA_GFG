#include <bits/stdc++.h>
using namespace std;

int countWays(vector<int> &coins, int n, int s)
{
     if (s==0) { return 1; }
     if (s<0) { return 0; }
     if (n==0) { return 0; }

     return countWays(coins, n, s-coins[n-1]) + countWays(coins, n-1, s);
}

int main()
{
     vector<int> coins={2,5,3};
     int n=3, s=5;
     cout<<countWays(coins, n, s);

     return 0;
}