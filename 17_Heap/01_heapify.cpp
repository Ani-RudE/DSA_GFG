#include <bits/stdc++.h>
using namespace std;

class MinHeap {
     int *arr;
     int size;
     int capacity;

public:
     MinHeap(int c) {
          arr = new int[c];
          size = 0;
          capacity = c;
     }

     int left (int i) { return ((2 * i) + 1); }
     int right (int i) { return ((2 * i) + 2); }
     int parent (int i) { return ((i - 1) / 2); }

     void insert(int x) {
          if (size == capacity) {
               cout<<"Overflow";
               return;
          }

          int i = size;
          arr[i] = x;
          size += 1;

          while (i!=0 && arr[parent(i)]>arr[i]) {
               swap(arr[i], arr[parent(i)]);
               i = parent(i);
          }
     }

     // Heapify TC: O(logN)
     // Heapify SC: O(H), where H=Height
     void minHeapify(int i) {
          int lt = left(i);
          int rt = right(i);
          int smallest = i;

          if (lt<size && arr[lt]<smallest) {
               smallest = lt;
          } else if (rt<size && arr[rt]<smallest) {
               smallest = rt;
          }

          if (smallest != i) {
               swap(arr[i], arr[smallest]);
               minHeapify(smallest);
          }
     }

     int getMin() {
          return arr[0];
     }

     // TC: O(logN)
     // SC: O(logN) if Heapify is recursive, O(1) if iterative
     int extractMin() {
          if (size==0) {
               return INFINITY;
          } else if (size==1) {
               size -= 1;
               return arr[0];
          }

          swap(arr[0], arr[size-1]);
          size -= 1; // It removes the last element (after swap, i.e., originally arr[0], the min element in MinHeap), tho it is still in the array. But since we reduced the size by one, it no longer matters.
          minHeapify(0);
          return arr[size];

     }
};

int main() {
     MinHeap h(11);
     h.insert(3); 
     h.insert(2);
     h.insert(15);
     h.insert(20);
     
     return 0;
}