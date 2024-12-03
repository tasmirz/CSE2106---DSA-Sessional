#include <bits/stdc++.h>
using namespace std;
template <class T>
void radix_sort(vector<T>& array) {
  int maximum = -1;
  for (auto i : array) maximum = max((int)ceil(log10(i)), maximum);
  /*
   * exploits the fact that this approach of counting sort is stable
   * So it always remains previous lower digit order
   * thus the whole array gets sorted
   */
  for (int j = 0; j < maximum; j++) {
    vector<T> v(10, 0), result(array.size());
    for (auto i : array) v[(i / (int)pow(10, j)) % 10]++;
    for (int i = 1; i < v.size(); i++) v[i] = v[i - 1] + v[i];
    for (int i = array.size() - 1; i >= 0; i--)
      result[--v[(array[i] / (int)pow(10, j)) % 10]] = array[i];
    // without taking from reverse each time order will be changed and stability
    // would be lost scanning from end ensures last one is placed in the last
    // space, as count decreases gradually
    array = result;
  }
}