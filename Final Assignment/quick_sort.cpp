#include <bits/stdc++.h>
using namespace std;

template <class T>
void quick_sort(vector<T>& array) {
  stack<pair<int, int>> st;
  st.push({0, array.size() - 1});  // used for recursion stack
  while (!st.empty()) {
    pair<int, int> p = st.top();
    st.pop();
    if (p.first >= p.second) continue;  // invalid and same check
    if (p.second - p.first == 1) {      // adjacent swap
      if (array[p.first] > array[p.second])
        swap(array[p.first], array[p.second]);
      continue;
    }
    T pivot = array[p.second];
    int last_smallest = p.first;
    int last_largest = p.second;
    for (int i = p.first; i <= last_largest;) {  // until two pointers are met
      if (array[i] < pivot)
        swap(array[i], array[last_smallest++]), i++;  // left pointer progresses
      else if (array[i] > pivot)
        swap(array[i], array[last_largest--]);  // right pointer progresses,
      // this condition freezes the loop progression ans, it brings the equals
      // to current position
      else
        i++;  // as equal to pivot no need to move any pointer
    }
    pivot = last_smallest - 1;
    st.push({last_largest, p.second});      // executed second
    st.push({p.first, last_smallest - 1});  // executed first
  }
}