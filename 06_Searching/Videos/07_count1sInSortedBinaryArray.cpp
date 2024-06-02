#include <bits/stdc++.h>
using namespace std;

int countOf1s(int arr[], int n)
{
     int low = 0, high = n - 1;

     while (low <= high)
     {
          int mid = low + ((high - low) / 2);

          if (arr[mid] == 0)
               low = mid + 1;
          else
          {
               if (mid == 0 || arr[mid] != arr[mid - 1])
               {
                    // cout<<n<<" "<<mid<<endl;
                    return (n - mid);
               }
               else
                    high = mid - 1;
          }
     }

     return 0;
}

int main()
{
     int n;
     int arr[] = {0,0,1,1,1,1,1};
     n = sizeof(arr) / sizeof(arr[0]);

     cout << countOf1s(arr, n);

     return 0;
}