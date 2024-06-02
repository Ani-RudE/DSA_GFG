#include <bits/stdc++.h>
using namespace std;

void powerSet(string s)
{
     int n = s.length();
     vector<string> vct;

     int powerSetSize = (1 << n); //(x<<y) = x*2^y

     for (int i = 0; i < powerSetSize; ++i)
     {
          cout<<"\"";

          for (int j = 0; j < i; ++j)
          {
               if ((i & (1 << j)) != 0)
                    cout << s[j];
          }

          cout <<"\"\n";
     }

     return;
}

int main()
{
     string s;
     cin >> s;

     powerSet(s);

     return 0;
}