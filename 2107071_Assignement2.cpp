#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

class Array {
 private:
  int *data = 0;
  int _size = 0;
  int real_size;
  bool sorted = true;
  bool checkWithin(int at) {
    if (at >= 0 && at < _size) return true;
    return false;
  }
  void is_sorted() {
    bool flag = true;
    for (int i = 1; i < _size; i++) {
      if (data[i - 1] > data[i]) {
        flag = false;
        break;
      }
    }
    sorted = flag;
  }

 public:
  Array() {
    real_size = _size + 1;
    data = new int[real_size];
  }
  Array(int *t, int n) {
    _size = n;
    real_size = _size + 1;
    data = new int[real_size];
    data[0] = t[0];
    for (int i = 1; i < n; i++) {
      if (data[i - 1] > data[i]) sorted = false;
      data[i] = t[i];
    }
  }
  Array(int n) {
    _size = n;
    real_size = _size + 1;
    data = new int[real_size];
  }
  Array(int n, int t) {
    _size = n;
    real_size = _size + 1;
    data = new int[real_size];
    for (int i = 0; i < n; i++) data[i] = t;
  }
  int at(int n) {
    string s = "\n\n Fault: Invalid index\n";
    if (!checkWithin(n)) throw s;
    return data[n];
  }
  void createArray(int n) {
    delete data;
    data = new int[n];
    for (int i = 0; i < n; i++) data[i] = 0;
  }
  bool insertElement(int index, int value) {
    if (!checkWithin(index - 1) && index != 0) return false;
    int *temp = new int[real_size + 1];
    real_size++;
    _size++;

    for (int i = 0; i < index; i++) {
      temp[i] = data[i];
    }
    temp[index] = value;
    for (int i = index + 1; i < real_size - 1; i++) {
      temp[i] = data[i - 1];
    }
    delete data;
    data = temp;
    /* if (sorted) // O(1) Checking
      if (index == 0 && _size > 1 && data[0] > data[1])
        sorted = false;
      else if (index == _size - 1 && _size >= 2)
        if (data[_size - 2] > data[_size - 1])
          sorted = false;
        else if (index > 0 && index < _size - 1)
        if (a[])
          else  */
    return true;
  }
  bool deleteElement(int index) {
    if (_size < 1) return false;
    if (!checkWithin(index) && index != 0) return false;
    int *temp = new int[real_size - 1];
    real_size--;
    _size--;

    for (int i = 0; i < index; i++) {
      temp[i] = data[i];
    }
    for (int i = index; i < real_size - 1; i++) {
      temp[i] = data[i + 1];
    }
    int *tt = new int;

    delete tt;
    delete data;
    data = temp;
    return true;
  }
  int searchElement(int value) {
    for (int i = 0; i < _size; i++)
      if (data[i] == value) return i;
    return -1;
  }
  int *begin() { return data; }
  int *end() { return &data[_size]; }
  int size() { return _size; }
  void traverseArray() {
    cout << "Size : " << _size << endl;
    cout << "Contents : ";

    for (auto i : *this) cout << i << " ";
    cout << endl;
  }
  //
  int &operator[](int n) { return data[n]; }
  //
  bool push_back(int n) { return insertElement(_size, n); }
  bool pop_back() { return deleteElement(_size - 1); }
  bool resize(int n) {
    int *temp = new int[n + 1];
    if (temp == NULL) return false;
    real_size = n + 1;

    for (int i = 0; i < min(n, _size); i++) {
      temp[i] = data[i];
    }
    int *tt = new int;
    temp[_size] = *tt;  // setting extra one garbage
    delete tt;
    _size = n;
    delete data;
    data = temp;
    return true;
  }
  bool empty() { return (_size == 0); }
  int max_size() { return real_size; }
  void fill(int t) {
    for (int i = 0; i < _size; i++) data[i] = t;
  }
  /*   void swap(Array& a) {
      swap(a._size, _size);
      swap(a.real_size, real_size);
      swap(a.data, data);
    } */

  //
  //
  //
  int binary_search(int what) {
    is_sorted();
    if (!sorted) throw "The array was not sorted, during execution";
    int l = 0;
    int r = size();
    int mid;
    while (r >= l) {
      mid = (r + l) / 2;
      if (data[mid] == what)
        return mid;
      else if (data[mid] > what)
        r = mid - 1;
      else
        l = mid + 1;
    }
    return (data[mid] == what) ? mid : -1;
  }
  int meta_binary_search(int what) {
    is_sorted();
    if (!sorted) throw "The array was not sorted, during execution";
    int pos = 0;
    int loops = log(_size - 1) + 1;     // -1 for 2^n
    for (int i = loops; i > -1; i--) {  // starting from right
      int probable_pos = pos + (1 << i);
      if (probable_pos > _size)
        break;  // out of bound
      else if (data[probable_pos] == what) {
        pos = probable_pos;
        break;
      } else if (data[probable_pos] < what)
        pos = probable_pos;
    }

    return ((data[pos] == what) ? pos : -1);
  }
  int binary_search(long what) {
    is_sorted();
    if (!sorted) throw "The array was not sorted, during execution";
    int l = 0;
    int r = _size;
    int mid;
    while (r > l) {
      mid = l + (r - l) / 2;
      if (data[mid] == what)
        return what;
      else if (data[mid] < what)
        r = mid - 1;
      else
        l = mid + 1;
    }
    cout << mid << " " << data[mid] << endl;
    return -1;
  }
  int lower_bound(int what) {
    is_sorted();
    if (!sorted) throw "The array was not sorted, during execution";
    if (data[0] > what) return -1;
    int l = 0;
    int r = size();
    int mid;
    while (l < r) {
      mid = l + (r - l) / 2;
      if (data[mid] >= what)
        r = mid;  // for including mid
      else
        l = mid + 1;
    }
    if (data[l] > what && l > 0) l--;
    return l;
  }
  int upper_bound(int what) {
    is_sorted();
    if (!sorted) throw "The array was not sorted, during execution";
    int l = 0;
    int r = _size;
    int mid;
    while (r > l) {
      // cout << r << " " << l << endl;
      mid = (r + l) / 2;
      if (data[mid] <= what)
        l = mid + 1;  // for taking one higher
      else
        r = mid;
    }
    if (mid == _size - 1 && data[mid] < what) return -1;
    return l;
  }
};

int main() {
  int demo[8] = {1, 3, 3, 3, 4, 7, 7, 7};
  Array a(10),        // of size 10
      b(10, 10),      // of size ten , value 10
      c(demo, 4),     // created array from demo
      test(demo, 7);  // empty
  /* int m;
  cout << "Create Array : Size Contents\n : ";
  cin >> m;
  for (int i = 0; i < m; i++) {
    int t;
    cin >> t;
    test.push_back(t);
  }
  cout << endl << endl; */
  int input;
  do {
    test.traverseArray();
    cout << "Operations"
            "\n\t 1. insert element index, data"  //
            "\n\t 2. remove element index"        //
            "\n\t 3. push back      data"         //
            "\n\t 4. pop back       x"            //
            "\n\t 5. normal search  data"         //
            "\n\t 6. binary search  data"         //
            "\n\t 7. lower bound    data"         //
            "\n\t 8. upper bound    data"         //
            "\n\t 9. meta bsearch   data"         //
            "\nSelect an operation: ";
    cin >> input;
    int p, q;
    try {
      switch (input) {
        case 0:
          break;
        case 1:
          cin >> p >> q;
          cout << (test.insertElement(p, q) ? "Inserted\n" : "Failed\n");
          break;
        case 2:
          cin >> p;
          cout << (test.deleteElement(p) ? "Deleted\n" : "Failed\n");
          break;
        case 3:
          cin >> p;
          cout << (test.push_back(p) ? "Pushed\n" : "Failed\n");
          ;
          break;
        case 4:
          cout << (test.pop_back() ? "Poped\n" : "Failed\n");
          ;
          break;
        case 5:
          cin >> p;
          cout << "Result : " << test.searchElement(p) << endl;
          break;
        case 6:
          cin >> p;
          cout << "Result : " << test.binary_search(p) << endl;
          break;
        case 7:
          cin >> p;
          cout << "Result : " << test.lower_bound(p) << endl;
          break;
        case 8:
          cin >> p;
          cout << "Result : " << test.upper_bound(p) << endl;
          break;
        case 9:
          cin >> p;
          cout << "Result : " << test.meta_binary_search(p) << endl;
          break;
        default:
          cout << "\nInvalid input.\n";
          break;
      }
    } catch (char const *s) {
      cout << s << endl;
    }

#ifdef OSisWindows
    system("pasue");
    system("cls");
#else
    system("read -n1 -r -p \"Press any key to continue...\"");
    system("clear");
#endif

  } while (input);
  return 0;
}