
/* Doubly Linked List Node(in the header file) Create a struct named Node within
    the header file to represent a node in the doubly linked list
        .The Node struct should have
    : A templated data member to store the value
        .Pointers to the previous and next nodes
        .
 */
#include <cmath>
#include <iostream>
#include <utility>

using namespace std;
#ifndef DoublyLinkedListL
template <class T>
struct Node {
  T data;
  Node *previous = 0, *next = 0;
  Node(T data);
  Node();
};

template <class T>
struct NodeIterator {
  Node<T>* now;
  void operator++();
  void operator--(int);
  T operator*();
  NodeIterator(Node<T>* q);
  bool operator==(NodeIterator q);
  bool operator!=(NodeIterator q);
};

/*       Doubly Linked List Class(in the header file) Create a templated
      class named DoublyLinkedList to represent the doubly linked list
        .The class should have private members
    : Pointers to the head and tail of the doubly linked list.Properly implement
      constructors,
    destructors,
    and any other necessary functions. */
template <class T>
class DoublyLinkedList {
 private:
  int _size = 0;
  Node<T>*head, *tail;
  DoublyLinkedList();
  void merge(int ll, int rr);
  void quick(int ll, int rr);

 public:
  DoublyLinkedList(Node<T>* data);
  // Insertion Methods:
  // Implement the following insertion methods:

  //
  // Inserts a node with the given value at
  // the beginning of the doubly linked list.
  void insertBegin(const T& value);
  //: the end of the doubly linked list.
  void insertEnd(const T& value);

  //: Inserts a node with the given value at
  void insertAtPosition(
      int position,
      const T& value);  //: Inserts a node with the given value at the
                        //: specified position in the doubly linked list.

  // Deletion Methods:
  // Implement the following deletion methods:
  void deleteBegin();  //: Deletes the node at the beginning of the doubly
                       //: linked list.
  void deleteEnd();    //: Deletes the node at the end of the doubly linked
                       //: list.
  void deleteAtPosition(int position);  //: Deletes the node at the specified
                                        //: position in the doubly linked list.
  void deleteByValue(
      const T& value);  //: Deletes the node(s) with the specified value
                        //: from the doubly linked list.

  // Sorting Methods:
  // Implement the following sorting methods:
  void quickSort();  //: Performs the QuickSort algorithm on the doubly
                     //: linked list.
  void mergeSort();  //: Performs the MergeSort algorithm on the doubly
                     //: linked list.

  Node<T>* at(int pos);
  std::pair<int, Node<T>*> search(T data);
  void display();
  NodeIterator<T> begin();
  NodeIterator<T> end();
};
#define DoublyLinkedListL
#endif

template <class T>
Node<T>::Node() {}
template <class T>
Node<T>::Node(T data) : data(data) {}
template <class T>
NodeIterator<T>::NodeIterator(Node<T>* now) : now(now) {}
template <class T>
void NodeIterator<T>::operator++() {
  now = now->next;
}

template <class T>
T NodeIterator<T>::operator*() {
  return now->data;
}
template <class T>
void NodeIterator<T>::operator--(int) {
  now = now->previous;
}

template <class T>
bool NodeIterator<T>::operator==(NodeIterator<T> q) {
  return (now == q.now);
}
template <class T>
bool NodeIterator<T>::operator!=(NodeIterator<T> q) {
  return (now != q.now);
}

template <class T>
NodeIterator<T> DoublyLinkedList<T>::begin() {
  return NodeIterator(head);
};
template <class T>
NodeIterator<T> DoublyLinkedList<T>::end() {
  return NodeIterator(tail);
};
template <class T>
DoublyLinkedList<T>::DoublyLinkedList(Node<T>* data) {
  head = tail = data;
  _size++;
};

template <class T>
void DoublyLinkedList<T>::insertBegin(const T& data) {
  Node<T>* n = new Node(data);
  head->previous = n;
  n->next = head;
  head = n;
  _size++;
}
template <class T>
void DoublyLinkedList<T>::insertEnd(const T& data) {
  Node<T>* n = new Node(data);
  tail->next = n;
  n->previous = tail;
  tail = n;
  _size++;
}

template <class T>
Node<T>* DoublyLinkedList<T>::at(int pos) {
  if (pos < 0 || pos >= _size) throw "Out of bound";
  Node<T>* temp = head;
  for (int i = 0; i < pos; i++) temp = temp->next;
  return temp;
}

template <class T>
void DoublyLinkedList<T>::insertAtPosition(int position, const T& data) {
  if (position == 0) return insertBegin(data);
  if (position == _size) return insertEnd(data);
  Node<T>* n = new Node(data);
  Node<T>* loc = at(position);
  n->previous = loc->previous;
  n->next = loc;
  loc->previous->next = n;
  loc->previous = n;
  _size++;
}

template <class T>
void DoublyLinkedList<T>::deleteBegin() {
  if (_size < 1) throw "Out of bounds";
  delete head;
  head = head->next;
  head->previous = 0;
  _size--;
}
template <class T>
void DoublyLinkedList<T>::deleteEnd() {
  if (_size < 1) throw "Out of bounds";
  delete tail;
  tail = tail->prev;
  tail->next = 0;
  _size--;
}

template <class T>
void DoublyLinkedList<T>::deleteAtPosition(int position) {
  if (position == 0) return deleteBegin();
  if (position == _size) return deleteEnd();
  Node<T>* loc = at(position);
  loc->previous->next = loc->next;
  loc->next->previous = loc->prev;
  delete loc;
  _size--;
}

template <class T>
std::pair<int, Node<T>*> DoublyLinkedList<T>::search(T data) {
  Node<T>* tempP = head;
  Node<T>* tempE = tail;
  std::pair<int, Node<T>*> ret;
  for (int i = 0; i <= _size / 2; i++) {
    tempP = tempP->next;
    tempE = tempE->previous;
    if (tempP->data == data) return std::make_pair(i, tempP);
    if (tempE->data == data) return std::make_pair(_size - i, tempE);
  }
  return 0;
}

template <class T>
void DoublyLinkedList<T>::deleteByValue(const T& value) {
  std::pair<int, Node<T>*> loc = search(value);
  if (loc.second == 0) throw "Not found";
  deleteAtPosition(loc.first);
}
template <class T>
void DoublyLinkedList<T>::display() {
  for (auto i = begin(); i != 0; ++i) {
    cout << *i << " ";
  }
  cout << endl;
}

template <class T>
void DoublyLinkedList<T>::mergeSort() {  // node swap
  merge(0, _size - 1);                   // without head
}
template <class T>
void DoublyLinkedList<T>::quickSort() {  // node swap
  quick(0, _size - 1);
}
template <class T>
void DoublyLinkedList<T>::quick(int low, int high) {
  // calculate pivot
  if (low >= high) return;
  int i = low;
  int pivot = at(high)->data;
  for (int j = low; j <= high; j++) {
    if (at(i)->data < pivot) {
      swap(at(i)->data, at(j)->data);
      i++;
    }
  }
  cout << low << " " << high << " " << i << endl;
  // for (int i = 0; i < 11; i++) cout << arr[i] << " ";
  swap(at(i)->data, at(high)->data);
  quick(low, i - 1);
  quick(i + 1, high);

  cout << endl;
}
template <class T>
void DoublyLinkedList<T>::merge(int ll, int rr) {
  if (ll >= rr) return;
  int mid = (ll + rr) / 2;
  merge(ll, mid);
  merge(mid + 1, rr);
  Node<T>* l = at(ll);
  DoublyLinkedList<T> left = DoublyLinkedList<T>(new Node(l->data));
  l = l->next;
  for (int i = ll; i < mid; i++) {
    left.insertEnd(l->data);
    l = l->next;
  }
  DoublyLinkedList<T> right = DoublyLinkedList<T>(new Node(l->data));
  for (int i = mid + 1; i <= rr - 1; i++) l = l->next, right.insertEnd(l->data);

  int a = 0, b = 0;
  Node<T>* working = at(ll);
  NodeIterator wl(left.head), wr(right.head);
  while (a < left._size && b < right._size) {
    if (*wl > *wr) {
      working->data = *wr;
      ++wr;
      b++;
    } else {
      working->data = *wl;
      ++wl;
      a++;
    }
    working = working->next;
  }
  while (a < left._size) {
    working->data = *wl;
    ++wl;
    a++;
    working = working->next;
  }
  while (b < right._size) {
    working->data = *wr;
    ++wr;
    b++;
    working = working->next;
  }
}

/* int main() {
  DoublyLinkedList<int> q(new Node(9));
  q.insertEnd(7);
  q.insertEnd(6);
  q.insertEnd(5);
  q.insertEnd(4);
  q.insertEnd(3);
  q.insertEnd(2);
  q.insertEnd(1);
  q.display();
  q.mergeSort();
  // q.quickSort();
  q.display();
} */