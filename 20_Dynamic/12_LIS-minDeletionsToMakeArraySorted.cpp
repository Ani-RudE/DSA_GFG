//Minimum deletions to make an array sorted
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int ceilIndex(vector<int> &tail, int l, int r, int key)
{
     while (l < r)
     {
          int mid = l + ((r - l) / 2);

          if (tail[mid] >= key)
          {
               r = mid;
          }
          else
          {
               l = mid + 1;
          }
     }

     return r;
}

int lengthOfLIS(vector<int> &arr)
{
     vector<int> tail;
     tail.push_back(arr[0]);
     for (int i = 1; i < arr.size(); ++i)
     {
          if (tail[tail.size() - 1] < arr[i])
          {
               tail.push_back(arr[i]);
          }
          else
          {
               int idx = ceilIndex(tail, 0, tail.size() - 1, arr[i]);
               tail[idx] = arr[i];
          }
     }

     return tail.size();
}

int minDeletions(vector<int> &arr) {
     return (arr.size() - lengthOfLIS(arr));
}

int main()
{
     vector<int> arr = {5,10,3,6,7,8};
     cout << minDeletions(arr);

     return 0;
}