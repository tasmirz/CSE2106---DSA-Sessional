#include <iostream>
using namespace std;
#ifndef A5
#define A5
template <class T>
class Node {
 public:
  T data;
  Node<T>* previous = 0;
  Node<T>* next = 0;
  Node() {}
  Node(T data) : data(data) {}
  Node(Node<T>* previous, T data, Node<T>* next) : data(data), next(next) {}
};
template <class T>
class Deque {
  Node<T>*front, *back;
  int _size = 0;
  void first_insert(T data) {
    front = back = new Node(data);
    _size = 1;
  }
  void last_delete() {
    delete front;
    front = back = 0;
    _size = 0;
  }

 public:
  //: Constructor toinitialize the deque.
  Deque() {}
  ~Deque() {
    Node<T>* curr = front;
    while (_size--) {
      curr = curr->next;
      delete curr;
    }
  }

  // Inserts a node with the given value at the front of the deque.
  void push_front(const T& value) {
    if (_size == 0) return first_insert(value);
    Node<T>* n = new Node(value);
    n->next = front;
    front->previous = n;
    front = n;
    _size++;
  }
  // Inserts a node with the given value at the end of the deque.
  void push_back(const T& value) {
    if (_size == 0) return first_insert(value);
    Node<T>* n = new Node(value);
    n->previous = back;
    back->next = n;
    back = n;
    _size++;
  }
  // Delete the node at the front of the deque.
  void pop_front() {
    if (_size == 0) throw "underflow";
    if (_size == 1) return last_delete();
    front = front->next;
    delete front->previous;
    front->previous = 0;
    _size--;
  }
  // Delete the node at the end of the deque.
  void pop_back() {
    if (_size == 0) throw "underflow";
    if (_size == 1) return last_delete();
    back = back->previous;
    delete back->next;
    back->next = 0;
    _size--;
  }
  // Checks if the deque is empty. Returns true if found, false otherwise.
  bool empty() const { return _size; }
  // Displays the elements of the deque.
  void operator()() const {
    Node<T>* curr = front;
    while (curr) cout << curr->data << " ", curr = curr->next;
    cout << endl;
  }
  // Returns the size of the deque.
  int size() const { return _size; }
};
template <class T>
class Queue : protected Deque<T> {
 private:
  // Node<T>& front = Deque<T>::front;
  // Node<T>& back = Deque<T>::back;

 public:
  // Constructor to initialize the queue. handled by parent class
  Queue(){};
  // Destructor to deallocate memory. handled by parent class
  ~Queue(){};
  // Inserts a node with the given value at the end of the queue.
  void push(const T& value) { Deque<T>::push_back(value); }
  // Delete the oldest node.
  void pop() { Deque<T>::pop_front(); }
  // Checks if the queue is empty. Returns true if found, false otherwise.
  bool empty() const { return Deque<T>::empty(); }
  // Displays the elements of the queue.
  void operator()() const { return Deque<T>::operator()(); }
  // Returns the size of the queue.
  int size() const { return Deque<T>::size(); }
};

template <class T>
class Stack : protected Deque<T> {
 private:
  // Node<T>& front = Deque<T>::front; //inherits
  // Node<T>& back = Deque<T>::back; //inherits

 public:
  // Constructor to initialize the queue. handled by parent class
  Stack(){};
  // Destructor to deallocate memory. handled by parent class
  ~Stack(){};
  // Inserts a node with the given value at the top of the stack.
  void push(const T& value) { Deque<T>::push_front(value); }
  // Delete the node from to
  void pop() { Deque<T>::pop_front(); }
  // Checks if the stack is empty. Returns true if found, false otherwise.
  bool empty() const { return Deque<T>::empty(); }
  // Displays the elements of the stack.
  void operator()() const { Deque<T>::operator()(); }
  // Returns the size of the stack.
  int size() const { return Deque<T>::size(); }
};
#endif

void test() {
  try {
    Stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st();
    st.pop();
    st();
    st.pop();
    st();
    st.pop();
    st();
    cout << st.size() << endl << endl;

    Queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q();
    q.pop();
    q();
    q.pop();
    q();
    q.pop();
    q();
    cout << q.size() << endl << endl;

    Deque<int> d;
    d.push_back(1);
    d.push_front(2);
    d.push_back(3);
    d.pop_back();
    d.pop_front();
    d.push_front(7);
    d();
    cout << d.size() << endl << endl;

  } catch (char const* s) {
    cerr << "Error: " << s << endl;
  }
}

// int main() { test(); }