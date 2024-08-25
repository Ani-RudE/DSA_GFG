#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high) {
     int n1 = mid-low+1;
     int n2 = high-mid; // high-(mid+1)+1

     vector<int> leftArr(n1), rightArr(n2);
     for (int i=0; i<n1; ++i) {
          leftArr[i]=arr[low+i];
     }
     for (int i=0; i<n2; ++i) {
          rightArr[i]=arr[mid+1+i];
     }

     int i = 0, j = 0;
     int k = low;

     while (i<n1 && j<n2) {
          if (leftArr[i]<=rightArr[j]) {
               arr[k] = leftArr[i];
               i++;
               // k++;
          }
          else {
               arr[k] = rightArr[j];
               j++;
               // k++;
          }
          k++;
     }

     while (i<n1) {
          arr[k] = leftArr[i];
          i++;
          k++;
     }

     while (j<n2) {
          arr[k] = rightArr[j];
          j++;
          k++;
     }

     return;
}

void mergeSort(vector<int> &arr, int low, int high) {
     if (low>=high) {
          return;
     }

     int mid = low+(high-low)/2;
     mergeSort(arr, low, mid);
     mergeSort(arr, mid+1, high);
     merge(arr, low, mid, high);

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
    vector<int> arr = { 12, 11, 13, 5, 6, 7 };
    int n = arr.size();

    cout << "Given vector is \n";
    printVector(arr);

    mergeSort(arr, 0, n - 1);

    cout << "\nSorted vector is \n";
    printVector(arr);
    return 0;
}