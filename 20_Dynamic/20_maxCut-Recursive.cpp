//Worst cast Time: O(3^n)
#include <bits/stdc++.h>
using namespace std;

int maxCuts(int n, int a, int b, int c) {
     if (n<0) { return -1; }
     if (n==0) { return 0; }

     int res=max(maxCuts(n-a, a, b, c), max(maxCuts(n-b, a, b, c), maxCuts(n-c, a, b, c)));

     if (res==-1) {
          return res;
     } else {
          return res+1;
     }
}

int main()
{
     int n=5;
     int a=1;
     int b=2;
     int c=3;
     cout<<maxCuts(n, a, b, c);

     return 0;
}