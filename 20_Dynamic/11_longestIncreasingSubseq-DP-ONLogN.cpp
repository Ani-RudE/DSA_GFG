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

int lengthOfLIS(vector<int> &nums)
{
     vector<int> tail;
     tail.push_back(nums[0]);
     for (int i = 1; i < nums.size(); ++i)
     {
          if (tail[tail.size() - 1] < nums[i])
          {
               tail.push_back(nums[i]);
          }
          else
          {
               int idx = ceilIndex(tail, 0, tail.size() - 1, nums[i]);
               tail[idx] = nums[i];
          }
     }

     return tail.size();
}

int main()
{
     vector<int> arr = {3, 4, 2, 8, 10, 5, 1};
     cout << lengthOfLIS(arr);

     return 0;
}