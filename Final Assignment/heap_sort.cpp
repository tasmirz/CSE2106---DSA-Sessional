#include <bits/stdc++.h>
using namespace std;
template <class T>
void heapify(vector<T>& array, int n) {  // on insertion or from bottom to top

  if (!n) return;
  if (array[n] > array[n / 2])
    swap(array[n], array[n / 2]);  // checks only the parent
  heapify(array, n / 2);
}
template <class T>
void Heapify(vector<T>& array, int N, int n) {  // from top to bottom
  int i = 2 * n + 1;
  int j = 2 * n + 2;
  int largest = n;
  if (i < N && array[largest] < array[i])
    largest = i;  // larger one between i and n
  if (j < N && array[largest] < array[j])
    largest = j;       // logic to find the largest = j,largest
  if (largest != n) {  // if it isn;t the head, make it head
    swap(array[largest], array[n]);
    Heapify(array, N, largest);  // and make the top also heaped
  }
}

template <class T>
void heap_sort(vector<T>& array) {
  for (int i = array.size() / 2; i < array.size();
       i++) {  // it reaches leaf to root each time, and heapifies each path
               // Build up time nlogn
    heapify(array, i);
  }
  for (int i = array.size() - 1; i >= 0;
       i--) {  // extracts n-1 elements, each extraction takes logn time
    swap(array[0], array[i]);  // top moved to the sorted portion
    Heapify(array, i, 0);  // re heapification, array size is considered i , so
                           // that i does not touch the sorted portion
  }
}