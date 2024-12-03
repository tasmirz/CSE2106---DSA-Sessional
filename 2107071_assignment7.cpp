#include <bits/stdc++.h>
using namespace std;

template <class T, bool type = 0>
class PriorityQueue {
 private:
  const bool comparator = type;
  vector<pair<T, int>> heap;
  int size = 0;

 public:
  PriorityQueue() {}
  PriorityQueue(vector<pair<T, int>> heap) : heap(heap) {
    int i = size = heap.size();
    while (i = i / 2) {
      Heapify(i - 1);
    }
  }
  bool empty() { return size; }
  void push(pair<T, int> what) {
    size++;
    heap.push_back(what);
    heapify(heap.size() - 1);
  }
  void heapify(int i) {
    // from bottom
    if (i == 0) return;
    if (comparator && heap[i].second < heap[i / 2].second) {
      swap(heap[i], heap[i / 2]);
      heapify(i / 2);
    }
    if (!comparator && heap[i].second > heap[i / 2].second) {
      swap(heap[i], heap[i / 2]);
      heapify(i / 2);
    }
  }
  void Heapify(int i) {
    // from top
    //  try left first to sustain the complete nature

    if (comparator) {
      if (2 * i + 3 <= size) {
        if (heap[i].second >= heap[2 * i + 2].second &&
            heap[2 * i + 1].second > heap[2 * i + 2].second) {
          swap(heap[i], heap[2 * i + 2]);
          return Heapify(2 * i + 1);
        } else {
          swap(heap[i], heap[2 * i + 1]);
          return Heapify(2 * i + 1);
        }
        return;
      } else if (2 * i + 2 <= size) {
        if (heap[i].second >= heap[2 * i + 1].second) {
          swap(heap[i], heap[2 * i + 1]);
          return Heapify(2 * i + 1);
        }
      } else  //
        if (2 * i + 3 <= size) {
          if (heap[i].second <= heap[2 * i + 2].second &&
              heap[2 * i + 1].second < heap[2 * i + 2].second) {
            swap(heap[i], heap[2 * i + 2]);
            return Heapify(2 * i + 1);
          } else {
            swap(heap[i], heap[2 * i + 1]);
            return Heapify(2 * i + 1);
          }
          return;
        } else if (2 * i + 2 <= size) {
          if (heap[i].second <= heap[2 * i + 1].second) {
            swap(heap[i], heap[2 * i + 1]);
            return Heapify(2 * i + 1);
          }
        }
    } else {
      if (2 * i + 3 <= size) {
        if (heap[i].second <= heap[2 * i + 2].second &&
            heap[2 * i + 1].second < heap[2 * i + 2].second) {
          swap(heap[i], heap[2 * i + 2]);
          return Heapify(2 * i + 1);
        } else {
          swap(heap[i], heap[2 * i + 1]);
          return Heapify(2 * i + 1);
        }
        return;
      } else if (2 * i + 2 <= size) {
        if (heap[i].second < heap[2 * i + 1].second) {
          swap(heap[i], heap[2 * i + 1]);
          return Heapify(2 * i + 1);
        }
      } else  //
        if (2 * i + 3 <= size) {
          if (heap[i].second >= heap[2 * i + 2].second &&
              heap[2 * i + 1].second > heap[2 * i + 2].second) {
            swap(heap[i], heap[2 * i + 2]);
            return Heapify(2 * i + 1);
          } else {
            swap(heap[i], heap[2 * i + 1]);
            return Heapify(2 * i + 1);
          }
          return;
        } else if (2 * i + 2 <= size) {
          if (heap[i].second >= heap[2 * i + 1].second) {
            swap(heap[i], heap[2 * i + 1]);
            return Heapify(2 * i + 1);
          }
        }
    }
  }
  void pop() {
    assert(size);
    int ret = heap[0].first;
    swap(heap[0], heap[size - 1]);
    // heap.pop_back();
    size--;
    Heapify(0);
  }
  T top() { return heap[0].first; };
};

template <class T>
struct Node {
  pair<T, int> data;
  Node *previous = 0, *next = 0;
  Node(pair<T, int> data) : data(data){};
  Node(){};
  bool operator<(Node q) { return data.second < q.data.second; }
  bool operator<=(Node q) { return data.second <= q.data.second; }
  bool operator>=(Node q) { return data.second >= q.data.second; }
  bool operator>(Node q) { return data.second > q.data.second; }
};

template <class T, bool type = 0>
class PriorityQueueLL {
 private:
  int size = 0;
  bool comparator = type;
  Node<T>*head, *tail;

 public:
  bool empty() { return (bool)size; }
  T top() { return head->data.first; }
  void pop() {
    assert(size >= 1);
    head = head->next;
    delete head->previous;
    head->previous = 0;
    size--;
    if (size == 0) {
      head = 0;
      tail = 0;
    }
  }
  void push(pair<T, int> data) {
    Node<T>* n = new Node(data);
    if (!size) {
      head = n;
      tail = n;
      size++;
      return;
    }
    size++;
    /*
      keep a mid if inserted after mid=mid->next else mid=mid->previous ;
      thus n/2
      what if binary tree with doubly?
    */
    Node<T>*curr = head, temp;
    if (!comparator) {
      while (curr && curr->next && *curr->next >= *n) curr = curr->next;
      if (curr->next == 0) {
        if (curr == head) {
          if (*head > *n) {
            head->next = n;
            n->previous = head;
            tail = n;
          } else {
            n->next = head;
            head->previous = n;
            head = n;
          }
        } else {
          if (*tail > *n) {
            tail->next = n;
            n->previous = tail;
            tail = n;
          } else {
            n->previous = tail->previous;
            n->next = tail;
            n->previous->next = n;
            tail->previous = n;
          }
        }
        return;
      } else {
        n->previous = curr;
        n->next = curr->next;
        n->next->previous = n;
        curr->next = n;
      }
    } else {
      while (curr && curr->next && *curr->next <= *n) curr = curr->next;
      if (curr->next == 0) {
        if (curr == head) {
          if (*head < *n) {
            head->next = n;
            n->previous = head;
            tail = n;
          } else {
            n->next = head;
            head->previous = n;
            head = n;
          }
        } else {
          if (*tail < *n) {
            tail->next = n;
            n->previous = tail;
            tail = n;
          } else {
            n->previous = tail->previous;
            n->next = tail;
            n->previous->next = n;
            tail->previous = n;
          }
        }
        return;
      } else {
        n->previous = curr;
        n->next = curr->next;
        n->next->previous = n;
        curr->next = n;
      }
    }
  }  // 2 : 4 3 1 x if () {}
  // 3 1 3->next 2 2 prev3 2->next 1 1 prev
  // if (!curr->next) end = curr;
};
int main() {
  // 1 for min
  PriorityQueue<int, 1> p;
  p.push({11, 1});  // O(log(n))
  p.push({13, 3});
  p.push({12, 2});
  p.push({10, 0});
  p.pop();                  // O(log(n))
  cout << p.top() << endl;  // O(1)
  PriorityQueueLL<int, 1> a;
  a.push({11, 1});  // O(n)
  a.push({13, 3});
  a.push({12, 2});
  a.push({10, 0});
  a.pop();  // O(1)
  a.pop();
  cout << a.top() << endl;  // O(1)
  return 0;
}