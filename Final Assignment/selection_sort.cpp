#include <bits/stdc++.h>
using namespace std;
template <class T>
void selection_sort(vector<T>& array) {
  for (int i = 0; i < array.size(); i++) {
    T minimum = array[i];
    int min_location = i;
    for (int j = i; j < array.size(); j++) {
      if (minimum > array[j])
        minimum = array[j],
        min_location = j;  // finds the minimum elements location
    }
    swap(array[i], array[min_location]);  // swaps the minimum to i (already
                                          // sorted portion)
  }
}
