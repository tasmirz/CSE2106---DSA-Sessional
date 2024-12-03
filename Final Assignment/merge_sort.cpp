#include <bits/stdc++.h>
using namespace std;
template <class T>
void merge_sort(vector<T>& array) {
  int iterations =
      pow(2, ceil(log2(array.size())));  // finds number of iteration required
  for (int i = 2; i <= iterations; i *= 2) {
    for (int j = 0; j < array.size(); j += i) {  // merges 2,4,....
      int l = j;                                 // start
      int r = j + i / 2;                         // mid
      vector<T> vv;
      while (l < j + i / 2 && r < j + i && l < array.size() &&
             r < array.size()) {  // merge
        if (array[l] > array[r])
          vv.push_back(array[r++]);
        else
          vv.push_back(array[l++]);
      }
      while (l < j + i / 2 && l < array.size()) vv.push_back(array[l++]);
      while (r < j + i && r < array.size()) vv.push_back(array[r++]);
      for (int k = j, p = 0; k < j + i && k < array.size();
           k++, p++)  // copy - avoiding this step may save time
        array[k] = vv[p];
    }
  }
}