/* @author : 2107071 */

/*
 * Start Of Header File
 * header.hpp
 */
#include <iostream>
#define endl '\n'
using namespace std;
#ifndef _LinkedList
template <class T>
struct Node {
  T data;
  Node* next = 0;
  Node() {}
  Node(T data);
};

template <class T>
class LinkedList {
 private:
  Node<T>*head = 0, *last;
  int _size = 0;
  Node<T>* at(int i);

 public:
  ~LinkedList();
  void insertFront(const T& value);  //: Inserts a node with the given value at
                                     //: the front of the linked list.
  void insertEnd(const T& value);    //: Inserts a node with the given value at
                                     //: the end of the linked list.
  void insertAtPosition(
      int position,
      const T& value);  //: Inserts a node with the given value at the specified
                        //: position in the linked list.
  bool search(
      const T& value) const;  //: Searches for a node with the specified value.
                              //: Returns true if found, false otherwise.
  void display() const;       //: Displays the elements of the linked list.
  int getLength() const;      //: Returns the length of the linked list.
  void bubble_sort();
};
#define _LinkedList
#endif
/* End of Header File*/

/*
 * Header file implementation
 * header.cpp
 */

#ifndef _LinkedList
#include "header.hpp"
#endif
template <class T>
LinkedList<T>::~LinkedList() {
  Node<T>* curr = head;
  while (curr) {
    head = curr;
    curr = curr->next;
    delete head;
  }
}
template <class T>
Node<T>::Node(T data) : data(data) {}
template <class T>
void LinkedList<T>::insertFront(const T& value) {
  Node<T>* nNode = new Node<T>(value);
  nNode->next = head;
  head = nNode;
  _size++;
}
template <class T>
void LinkedList<T>::insertEnd(const T& value) {
  if (_size == 0) {
    insertFront(value);
    last = head;
    return;
  }
  Node<T>* nNode = new Node<T>(value);
  this->last->next = nNode;
  this->last = nNode;
  _size++;
}
template <class T>
void LinkedList<T>::insertAtPosition(int position, const T& value) {
  if (i < 0 || i >= _size) throw "Out of bounds";
  if (position == 0)
    insertFront(value);
  else if (position == _size)
    insertEnd(value);
  else {
    Node<T>* nNode = Node<T>(value);
    Node<T>* temp = head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = nNode;
  }
}
template <class T>
bool LinkedList<T>::search(const T& data) const {
  Node<T>* temp = head;
  while (temp) {
    if (temp->data == data) return true;
    temp = temp->next;
  }
  return false;
}
template <class T>
void LinkedList<T>::display() const {
  Node<T>* temp = head;
  while (temp) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

template <class T>
Node<T>* LinkedList<T>::at(int i) {
  if (i < 0 || i >= _size) throw "Out of bounds";
  Node<T>* curr = head;
  while (curr->next && --i) curr = curr->next;
  return curr;
}

template <class T>
void LinkedList<T>::bubble_sort() {
  Node<T>*temp = head, *a, *b, *h, *temp2;
  for (int step = 0; step < _size; step++) {
    temp = head;
    h = temp;  // prev
    a = temp;  // working
    for (int i = 0; i < _size - step - 1; i++) {
      b = a->next;  // second working
      // cout << a->data << " " << b->data << endl;
      if (a->data > b->data) {
        h->next = b;
        temp2 = b->next;
        b->next = a;
        a->next = temp2;
        if (a == head) head = b;
        a = b;  // keep a
      }
      h = a;        // set previous
      a = a->next;  // set new
    }
  }
  temp = temp->next;
}
template <class T>

int LinkedList<T>::getLength() const {
  return _size;
}
