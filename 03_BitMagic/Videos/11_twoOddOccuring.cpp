//Find out the two numbers that occurs odd number of times in the array
#include <bits/stdc++.h>
using namespace std;

int oddCountUsingXOR(vector<int>& vct, int n)
{
     int key=vct[0];
     
     for (int i=1; i<n; i++)
     {
          key^=vct[i];
     }
     
     return key;
}

vector<int> twoOddCount(vector<int>& vct, int n, int key)
{
     vector<int> resultVct;

     for (int i=0; i<n; i++)
     {
          int k=1, result1=-1, result2=-1;
          int x=pow(2, k-1);

          if (vct[i]&x==0) //k-th bit is not set
          {
               result1^=vct[i];
          }
          else //k-th bit is set
          {
               result2^=vct[i];
          }

          resultVct.push_back(result1);
          resultVct.push_back(result2);
     }

     return resultVct;
}

int main()
{
     int n;
     cin>>n;
     
     vector<int> vct;
     for (int i=0; i<n; i++)
          cin>>vct[i];
     
     int key=oddCountUsingXOR(vct, n);
     cout<<"Key: "<<key;

     vector<int> resultVct=twoOddCount(vct, n, key);
     cout<<"Answer: ";
     for (int i=0; i<resultVct.size(); i++)
          cout<<resultVct[i]<<", ";

     return 0;
}