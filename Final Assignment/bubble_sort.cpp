#include <bits/stdc++.h>
using namespace std;
template <class T>
void bubble_sort(vector<T>& array) {
  for (int i = array.size(); i >= 0; i--) {
    bool swapped = false;
    for (int j = 1; j < i; j++)
      if (array[j - 1] > array[j]) {
        swap(array[j - 1], array[j]);  // slowly moves the largest to the end
        swapped = true;
      }
    if (!swapped) break;  // checks if sorting done
  }
}
