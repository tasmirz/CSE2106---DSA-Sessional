#include <bits/stdc++.h>
using namespace std;
template <class T>
void count_sort(vector<T>& array) {
  int maximum = -1;
  for (auto i : array)
    maximum =
        max(maximum, i);  // finding maximum for getting auxiliary array size
  vector<T> v(maximum + 1, 0), result(array.size());
  for (auto i : array) v[i]++;  // counting
  for (int i = 1; i < v.size(); i++)
    v[i] = v[i - 1] + v[i];  // as first element was in the lowest in count,
                             // this prefix sum ensures
  for (int i = array.size() - 1; i >= 0; i--)
    result[--v[array[i]]] = array[i];  // the last element is picked first and
                                       // place in the last position
  array = result;
}