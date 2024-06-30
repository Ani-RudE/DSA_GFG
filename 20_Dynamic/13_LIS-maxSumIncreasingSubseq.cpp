#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int maxSumIncSubseq(vector<int> &arr, int n)
{
     int msis[n];

     for (int i=0; i<n; ++i) {
          msis[i]=arr[i];
          for (int j=0; j<i; ++j) {
               if (arr[j]<arr[i]) {
                    msis[i]=max(msis[i], arr[i] + msis[j]);
               }
          }
     }

     int res=msis[0];
     for (int i=0; i<n; ++i) {
          res=max(res, msis[i]);
     }

     return res;
}

int main()
{
     vector<int> arr = {3, 4, 2, 8, 10, 5, 1};
     cout << maxSumIncSubseq(arr, arr.size());

     return 0;
}