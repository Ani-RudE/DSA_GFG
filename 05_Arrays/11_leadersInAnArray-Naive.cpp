#include <bits/stdc++.h>
using namespace std;

void printLeaders(int arr[], int size)
{
     for (int i = 0; i < size; i++)
     {
          bool flag = false;
          int j;
          for (j = i + 1; j < size; j++)
          {
               if (arr[i] <= arr[j])
               {
                    flag = true;
                    break;
               }
          }

          if (flag == false)
               cout << arr[i] << " ";

          if (j == size) // the loop didn't break
               cout << arr[i] << " ";
     }
}

int main()
{
     int arr[] = {16, 17, 4, 3, 5, 2};
     int n = sizeof(arr) / sizeof(arr[0]);

     printLeaders(arr, n);
     return 0;
}