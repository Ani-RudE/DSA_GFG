//T.C : O(nlogn) in Average case, O(n^2) in worst case
//S.C : O(1) Auxiliary space, 
#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high) {
     int pivot = arr[high];
     int pIdx = low;
     for (int i=low; i<high; ++i) {
          if (arr[i]<=pivot) {
               swap(arr[i], arr[pIdx]);
               pIdx++;
          }
     }

     swap(arr[high], arr[pIdx]);

     return pIdx;
}

void quickSort(vector<int> &arr, int low, int high) {

     if (low<high) {
          int pIdx = partition(arr, low, high);
          quickSort(arr, low, pIdx-1);
          quickSort(arr, pIdx+1, high);
     }

     return;
}

void printVector(vector<int>& arr)
{
     for (int i = 0; i < arr.size(); i++)
          cout << arr[i] << " ";
     cout << endl;
}

int main()
{
     vector<int> arr = {10, 7, 8, 9, 1, 5};
     int n = arr.size();
     quickSort(arr, 0, n - 1);
     cout << "Sorted Array\n";
     for (int i = 0; i < n; i++)
     {
          cout << arr[i] << " ";
     }
     return 0;
}