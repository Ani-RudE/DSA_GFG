#include <bits/stdc++.h>
using namespace std;

int sqRoot(int n)
{
     int i=1;

     while (i*i<n)
          i+=1;
     
     return (i-1);
}

int main()
{
     int n=14;

     cout<<sqRoot(n);

     return 0;
}