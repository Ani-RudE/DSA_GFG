 #include <bits/stdc++.h>
using namespace std;

int editDist(string s1, string s2, int m, int n) {
     if (m==0) { return n; }
     if (n==0) { return m; }

     if (s1[m-1]==s2[n-1]) {
          m-=1;
          n-=1;
     } else {
          return (1+min(editDist(s1, s2, m, n-1), editDist(s1, s2, m-1, n-1), editDist(s1, s2, m-1, n-1)));
     }
}

int main()
{
     string s1="";
     string s2="";
     int m=s1.length(), n=s2.length();
     cout<<editDist(s1, s2, m, n);

     return 0;
}