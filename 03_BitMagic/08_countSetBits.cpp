#include <bits/stdc++.h>
using namespace std;

int countSetBits(int n)
{
     int res=0;

     while (n>=1)
     {
          if (n&1==1) //or can also use `if (n%2==1)` //This line checks if the
               res++;
          
          n/=2;
     }

     //Another way to implement the same logic
     // while (n>=1)
     // {
     //      res=res+(n&1);
     //      n/=2;
     // }

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
Our approach is to first check the last bit if it is set or not - it is being checked by the if statement on line 12

After that we move every bit to the last place by the operation n=n/2

Using the while loop the if condition again checks for the new last bit, if it is set or not

Time=θ(d), where d=number of bits from last to MSB
*/