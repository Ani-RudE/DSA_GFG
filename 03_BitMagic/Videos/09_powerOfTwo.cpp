#include <bits/stdc++.h>
using namespace std;

bool powerOfTwo(int n)
{
     if (n==0)
          return 0;

     return ((n&(n-1))==0);
}

//We can remove the if statement as well if we implement the following scenario
// bool powerOfTwo(int n)
// {
//      return ((n&(n&(n-1)))==0);
// }

int main()
{
     int n;
     cin>>n;

     cout<<"----------\n0 = No\n1 = Yes\n----------"<<endl;
     cout<<powerOfTwo(n);

     return 0;
}