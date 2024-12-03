#include <bits/stdc++.h>
using namespace std;
template <class T>
void insertion_sort(vector<T>& array) {     // On on sorted
  for (int i = 1; i < array.size(); i++) {  // first one is considered sorted
    T temp = array[i];
    for (int j = i - 1; j >= 0;
         j--) {  // until greater than previous element, swap, this is an
                 // alternate form of array element insertion
      if (temp > array[j]) {
        array[j + 1] = temp;  // insert the picked up current
        break;
      }
      array[j + 1] = array[j];
    }
  }
}