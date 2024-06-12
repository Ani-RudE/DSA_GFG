//Brian Kerningam's Algorithm
#include <bits/stdc++.h>
using namespace std;

int countSetBits(int n)
{
     int res=0;

     while (n>0)
     {
          n=n&(n-1);
          res=res+1;
     }

     return res;
}

int main()
{
     int n;
     cin>>n;

     cout<<countSetBits(n);

     return 0;
}

/*
https://cdn.discordapp.com/attachments/1210088566542311444/1210088666626662530/image.png?ex=65e949e4&is=65d6d4e4&hm=617d8383b5cf8f1acd70b3a2efb5a3743e8c0e6bad3e1aed01667e021b5f3ced&

If n=101000, then n-1=100111
Which means all the bits towards the right of the rightmost set bit, including the set bit are reversed
*/