//Check if the k-th bit is set (i.e., equal to 1) or not
#include <bits/stdc++.h>
using namespace std;

int main()
{
     int n, k;
     cin>>n>>k;

     int x=pow(2, k-1);
     cout<<x<<endl;

     if ((n&x)!=0)
          cout<<k<<"th bit is set.";
     else
          cout<<k<<"th bit is not set.";

     return 0;
}