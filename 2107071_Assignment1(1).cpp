#include <cstring>
#include <iostream>
using namespace std;

template <class T>
class Array {
 private:
  T* data = 0;
  int _size = 0;
  int real_size;
  bool checkWithin(int at) {
    if (at >= 0 && at < _size) return true;
    return false;
  }

 public:
  Array() {
    real_size = _size + 1;
    data = new T[real_size];
  }
  Array(T* t, int n) {
    _size = n;
    real_size = _size + 1;
    data = new T[real_size];
    memcpy(data, t, sizeof(T) * n);
  }
  Array(int n) {
    _size = n;
    real_size = _size + 1;
    data = new T[real_size];
  }
  Array(int n, T t) {
    _size = n;
    real_size = _size + 1;
    data = new T[real_size];
    for (int i = 0; i < n; i++) data[i] = t;
  }
  T at(int n) {
    string s = "\n\n Fault: Invalid index\n";
    if (!checkWithin(n)) throw s;
    return data[n];
  }
  void createArray(int n) {
    delete data;
    data = new T[n];
    for (int i = 0; i < n; i++) data[i] = 0;
  }
  bool insertElement(int index, T value) {
    if (!checkWithin(index - 1) && index != 0) return false;
    T* temp = new T[real_size + 1];
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
    return true;
  }
  bool deleteElement(int index) {
    if (_size < 1) return false;
    if (!checkWithin(index) && index != 0) return false;
    T* temp = new T[real_size - 1];
    real_size--;
    _size--;

    for (int i = 0; i < index; i++) {
      temp[i] = data[i];
    }
    for (int i = index; i < real_size - 1; i++) {
      temp[i] = data[i + 1];
    }
    T* tt = new T;

    delete tt;
    delete data;
    data = temp;
    return true;
  }
  bool searchElement(T value) {
    for (int i = 0; i < _size; i++)
      if (data[i] == value) return true;
    return false;
  }
  T* begin() { return data; }
  T* end() { return &data[_size]; }
  int size() { return _size; }
  void traverseArray() {
    for (auto i : *this) cout << i << " ";
    cout << endl;
  }
  T& operator[](int n) { return data[n]; }
  bool push_back(int n) { return insertElement(_size, n); }
  bool pop_back() { return deleteElement(_size - 1); }
  bool resize(int n) {
    T* temp = new T[n + 1];
    if (temp == NULL) return false;
    real_size = n + 1;

    for (int i = 0; i < min(n, _size); i++) {
      temp[i] = data[i];
    }
    T* tt = new T;
    temp[_size] = *tt;  // setting extra one garbage
    delete tt;
    _size = n;
    delete data;
    data = temp;
    return true;
  }
  bool empty() { return (_size == 0); }
  int max_size() { return real_size; }
  void fill(T t) {
    for (int i = 0; i < _size; i++) data[i] = t;
  }
  void swap(Array& a) {
    swap(a._size, _size);
    swap(a.real_size, real_size);
    swap(a.data, data);
  }
};

int main() {
  double data[8] = {4, 3.75, 3.75, 3.5, 3.75, 3.75, 3.75, 4.0};
  Array<double> a(data, 8);
  cout << a.searchElement(3.5) << endl;  // 1
  cout << a.searchElement(3.8) << endl;  // 0
  a.push_back(10);
  a.traverseArray();
  a.pop_back();
  a.traverseArray();
  a.insertElement(2, 3.5);
  a.traverseArray();
  a.deleteElement(3);
  a.traverseArray();
  cout << a[8];  // unsafe
  try {
    cout << a.at(9);  // safe
  } catch (string e) {
    cout << e << endl;
  }
  Array<double> aa;
  cout << aa.deleteElement(0) << endl;  // 0 failed
  cout << aa.deleteElement(1) << endl;  // 0 failed to delete
  aa.push_back(10);
  cout << aa.insertElement(2, 11) << endl;  // 0 failed to insert
  aa.insertElement(0, 11);                  // pre
  aa.insertElement(2, 12);                  // post
  aa.traverseArray();
  aa.fill(10);  // fill with value
  aa.traverseArray();
  aa.resize(20);  // others with grabage
  aa.traverseArray();
  aa.resize(3);  // resize
  aa.traverseArray();
  aa.deleteElement(2);
  aa.traverseArray();

  aa.deleteElement(0);
  aa.traverseArray();
  aa.deleteElement(0);
  cout << aa.size() << " ";
  aa.traverseArray();
  Array<int> aaa(3);
  aaa.traverseArray();

  Array<int> aaaa(5, 4);
  aaaa.traverseArray();

  // here failed operations return false
  //  the at() function throws error
}