//Time: θ(n)
//Space: θ(n)
#include <bits/stdc++.h>
using namespace std;

int fib(int n){
     int f[n+1];
     f[0]=0, f[1]=1;

     for (int i=2; i<=n; ++i) {
          f[i]=f[i-1]+f[i-2];
     }

     return f[n];
}

int main()
{
     int n = 5;
     cout << fib(n);

     return 0;
}
