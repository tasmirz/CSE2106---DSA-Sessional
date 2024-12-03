#include <bits/stdc++.h>

using namespace std;

enum iterator_mode { PREORDER, INORDER, POSTORDER };
enum at { LEFT, ROOT, RIGHT };
template <class E>
class Iterator;
void* nt = 0;
template <class E>
class BinaryTree {
  friend class Iterator<E>;
  iterator_mode Iteration_Mode = INORDER;
  bool iteration_locked = false;

 public:
  void unlock() {
    delete Boss;
    Boss = 0;
    iteration_locked = false;
  }
  // For fancy iteration
  Iterator<E>* Boss = 0;
  void IterationMode(iterator_mode mode) {
    assert(!iteration_locked);
    Iteration_Mode = mode;
  }
  Iterator<E>& begin() {
    assert(!iteration_locked);
    delete Boss;
    Boss = new Iterator(Iteration_Mode, this);
    iteration_locked = true;
    return *Boss;
  }
  Iterator<E>& end() { return *Boss; }

  E data;
  BinaryTree<E>*left = 0, *right = 0, *parent = 0;
  BinaryTree() {}
  BinaryTree(E data) : data(data) {}
  BinaryTree(E data, BinaryTree<E>* left, BinaryTree<E>* right) : data(data) {
    setLeft(left), setRight(right);
  }
  BinaryTree<E>* balance_tree() {
    BinaryTree<E>*balanced = new BinaryTree(), *result;
    balanced->right = this;

    this->parent = balanced;
    balanced->flatten();
    balanced->bstfy();

    balanced->right->parent = 0;
    result = balanced->right;
    balanced->right = 0;
    // delete balanced;
    return result;
  }
  void bstfy() {
    int i = 1;
    // bstfy_single(2);
    while (bstfy_single(i) > 1) i <<= 1;
  }
  int bstfy_single(int skips = 1, int n = 0) {
    // needs fix parent
    /*
    Rotation:
          C                      C
          \                       \
           Cr                     Crr 3
           / \                    / \
          p   Crr        ->    2 Cr  Crrr
             / \                / \
            q   Crrr            p  q 1
     */

    if (this->right) {                           // the ith
      BinaryTree<E>* temp = this->right->right;  // the i+1th
      if (temp) {
        if (temp->right) {
          this->right->right = temp->left;  // crr-q -> cr->q
          // easiest way to set parent
          if (this->right->right) this->right->right->parent = this->right;
        } else {
          return n + 1;
        }
        temp->left = this->right;
        if (temp->left) temp->left->parent = temp;
      } else {
        // cout << "outer: " << data << " " << n + 1 << endl;
        return n + 1;
      }
      this->right = temp;
      this->right->parent = this;
      temp = this;
      for (int i = 0; temp && i < skips; temp = temp->right, i++)
        ;
      if (temp) return temp->bstfy_single(skips, n + 1);
    }
    return n + 1;
  }
  void flatten() {
    if (right) {          // if there is right rotate right
      if (right->left) {  // if the left of right has left rotate that
        BinaryTree<E>* temp = right;
        right = right->left;
        right->parent = this;  // parent

        temp->left = right->right;

        if (temp->left) temp->left->parent = temp->left;  // parent

        right->right = temp;
        if (right->right) right->right->parent = right;  // parent
        flatten();
      }
      right->flatten();
    }
  }

  ~BinaryTree() {
    delete left;
    delete right;
  }
  // Returns height of node in tree.
  int height_raw(BinaryTree<E>* curr) {
    if (curr == 0) return 0;
    return (max(height_raw(curr->left), height_raw(curr->right)) + 1);
  }
  int height() { return height_raw(this); }
  // Update the left child of this node.
  void setLeft(BinaryTree<E>* newLeft) { left = newLeft, left->parent = this; }
  // Update the parent of this node.
  void setParent(BinaryTree<E> newParent) { parent = newParent; }
  // Update the right child of this node.
  void setRight(BinaryTree<E>* newRight) {
    right = newRight, right->parent = this;
  }
  // Sets value associated with this node.
  void setValue(E value) { data = value; }
  // Return an iterator to traverse the elements of subtree in-order.
  Iterator<E>& inorderIterator() { return *(new Iterator<E>(INORDER, this)); }
  // Return an iterator to traverse the elements of subtree in post-order.
  Iterator<E>& postorderIterator() {
    return *(new Iterator<E>(POSTORDER, this));
  }
  // Return an iterator to traverse nodes of subtree in-order.
  Iterator<E>& preorderIterator() { return *(new Iterator<E>(PREORDER, this)); }

  //  Return true if the tree is height balanced(the height of the left and
  //  right subtrees of every node differs by at most one).
  bool balance_raw(BinaryTree<E>* curr) {
    int a = height_raw(curr->left);
    int b = height_raw(curr->right);
    if (abs(a - b) <= 1) return true;

    return false;
  }
  bool isBalanced() { return balance_raw(this); }

  // Return whether tree is complete(all levels are completely filled except
  // possibly the last level, which is filled from left to right).

  bool isComplete() {
    queue<BinaryTree<E>*> q;
    /*
     * checks if has required 2^n
     * if one missing it has to be the last row if balanced
     * if left's missing there can't be any right
     * if right's missing there can't be anything
     * per miss = required--;
     * after the level having missings,check if the below nodes have nodes
     * underneath if below is clear it's a balanced tree
     */

    q.push(this);
    int level = 1;
    int at = 0;
    int required = 1 << 1;
    bool left_missing = false;
    bool right_missing = false;
    while (!q.empty()) {
      BinaryTree<E>* current = q.front();
      q.pop();
      // cout << current->data << " ";
      if (current->left) {
        if (right_missing) return false;
        at++;
        q.push(current->left);
      } else
        left_missing = true, required--;

      if (current->right) {
        if (left_missing) return false;
        at++;
        q.push(current->right);
      } else
        right_missing = true, required--;

      if (at == required) {
        level++;
        at = 0;
        required = 1 << level;
        if (left_missing)
          while (!q.empty()) {
            current = q.front();
            q.pop();
            if (current->left) return false;
            if (current->right) return false;
          }
        // cout << endl;
      }
    }
    return true;
  }

  //  Returns true if tree is full(every node has either 0 or 2 children).
  bool isFull() {
    Iterator<E> i = inorderIterator();
    int last = *i;
    for (; i; i++) {
      if (((bool)i.order.top()->left) ^
          ((bool)i.order.top()->right))  // checks 01,10
        return false;
    }
    return true;
  }

  // Returns true if tree is Binary Search Tree.
  bool isBinarySearchTree() {  // if in order sorted
    Iterator<E> i = inorderIterator();
    int last = *i;
    for (; i; i++) {
      if (*i < last) return false;
      last = *i;
    }
    return true;
  }

  // Balance an unbalanced binary search tree (rearrange the tree nodes to
  // ensure it is balanced) and return the new root of the balanced tree.
  BinaryTree<E> balance_tree(BinaryTree<E> Root) {}
};

template <class E>
class Iterator {
 public:
  iterator_mode mode;
  BinaryTree<E>* root_who = 0;
  stack<BinaryTree<E>*> order;
  at position;
  Iterator(iterator_mode mode, BinaryTree<E>* current)
      : mode(mode), root_who(current) {
    switch (mode) {
      case INORDER:
        position = LEFT;
        while (current) order.push(current), current = current->left;
        break;
      case PREORDER:
        order.push(current);
        break;
      case POSTORDER:
        position = LEFT;
        while (current->left) current = current->left;
        order.push(current);
        break;
        break;
    }
  }
  E operator*() { return order.top()->data; }
  friend ostream& operator<<(ostream& out, Iterator i) {
    out << i.order.top()->data;
    return out;
  };
  operator bool() { return order.size(); }
  bool preorder_pp() {
    /*
     * moves to root
     * pushes right first as it'll be accessed later
     * then left
     *
     * while ++
     * pop current , push other if not null
     */
    BinaryTree<E>* current = order.top();
    order.pop();
    if (current->right) order.push(current->right);
    if (current->left) order.push(current->left);
    // order.push(current);
    return true;
  }

  bool postorder_pp() {
    /*
     * goes to left
     * then right if avalable
     * if not go to root
     * on root
     * if checks if it's a left node
     * if it's a left climbs right's left
     * other wise goes back to parent
     */
    if (!order.size()) return false;
    BinaryTree<E>*current = order.top(), *temp;
    order.pop();
    switch (position) {
      // r/end to up rootu
      // rootu -> up root
      case ROOT:
      case LEFT:
        if (current->parent) {
          if (current->parent->left ==
              current) {  // check if it's the left parent
            temp = current->parent;
            if (current->parent->right) {  // has right
              current = current->parent->right;
              while (current->left) current = current->left;  // climb left
              if (temp->right == current)
                position = RIGHT;
              else
                position = LEFT;
              order.push(current);
            } else {
              // no right done
              order.push(current->parent);
              position = ROOT;
            }
          } else {
            if (current->parent) order.push(current->parent);
            position = ROOT;
          }
        } else {
          // dang
        }
        break;
      case RIGHT:
        if (current->parent) {
          order.push(current->parent);
          position = ROOT;
        }
        break;
      default:
        break;
    }

    return true;
  }

  bool inorder_pp() {
    /*
     * goes to left most
     * returns to top if empty below
     * goes to right -> find's new left
     * if no new left it's a right node
     * there are two ways going back to the top
     * 1. maintaining a stack (filled when calculating left and the last right
     * node)
     * 2. keep going up though a right node unless a left node is
     * found(re-visits some nodes)
     */
    if (!order.size()) return false;
    BinaryTree<E>* current;
    switch (position) {
      case LEFT:
        order.pop();
        position = ROOT;
        break;
      case ROOT:
        current = order.top();
        if (current->right) {
          order.pop();
          BinaryTree<E>* temp = current;
          current = current->right;
          while (current->left) order.push(current), current = current->left;
          if (temp->right == current) {
            position = RIGHT;
          } else {
            position = LEFT;
          }
          order.push(current);
        } else {
          order.pop();
        }
        break;
      case RIGHT:
        current = order.top();
        if (current->left) {
          order.push(current);
          while (current->left) order.push(current), current = current->left;
          position = LEFT;
        } else if (current->right) {
          order.pop();
          BinaryTree<E>* temp = current;
          current = current->right;
          while (current->left) order.push(current), current = current->left;
          if (temp->right == current) {
            position = RIGHT;
          } else {
            position = LEFT;
          }
          order.push(current);
        } else {
          order.pop();
          position = ROOT;
        }
    }
    return 1;
  }
  bool operator++(int) {
    switch (mode) {
      case INORDER:
        return inorder_pp();
      case POSTORDER:
        return postorder_pp();
        break;
      case PREORDER:
        return preorder_pp();
        break;
    }
    return false;
  }
  bool operator++() { return this->operator++(1); }
  bool operator!=(const Iterator& other) const {
    if (order.size()) {
      return true;
    } else
      root_who->iteration_locked = false;
    return false;
  }
};
int main() {
  BinaryTree<int>* b = new BinaryTree<int>(25);
  b->setValue(25);
  b->setLeft(new BinaryTree<int>(15));
  b->left->setLeft(new BinaryTree<int>(10));
  b->left->left->setLeft(new BinaryTree<int>(9));
  b->left->left->setRight(new BinaryTree<int>(11));
  b->left->setRight(new BinaryTree<int>(18));
  b->left->right->setLeft(new BinaryTree<int>(16));
  b->left->right->setRight(new BinaryTree<int>(20));
  b->setRight(new BinaryTree<int>(40));
  b->right->setLeft(new BinaryTree<int>(36));
  // b->right->right->setLeft(new BinaryTree<int>(38));   // remove for complete
  // b->right->right->setRight(new BinaryTree<int>(41));  // rmove for complete
  b->right->left->setLeft(new BinaryTree<int>(26));
  b->right->left->left->setLeft(new BinaryTree<int>(25));
  b->right->left->left->left->setLeft(new BinaryTree<int>(25));
  cout << endl << "Inorder\t\t: ";
  for (auto i = b->inorderIterator(); i; i++) {
    cout << i << " ";
  }
  cout << endl << endl;
  cout << endl << "Preorder\t: ";
  for (auto i = b->preorderIterator(); i; i++) {
    cout << i << " ";
  }
  cout << endl << endl;
  cout << endl << "Postorder\t: ";
  for (auto i = b->postorderIterator(); i; i++) {
    cout << i << " ";
  }
  cout << endl << endl;
  // checks
  cout << "Balanced\t: " << b->isBalanced() << endl;
  cout << "Full\t\t: " << b->isFull() << endl;
  cout << "BST\t\t: " << b->isBinarySearchTree() << endl;
  cout << "Complete\t: " << b->isComplete() << endl;

  // balance
  cout << endl << "Height before balancing\t: " << b->height() << endl;
  cout << "Balancing tree" << endl;
  b = b->balance_tree();
  cout << "Height after balancing \t: " << b->height() << endl;

  cout << endl << "Inorder\t\t: ";
  b->IterationMode(INORDER);
  for (auto i : *b) {
    cout << i << " ";
  }

  cout << endl << endl;

  cout << "Postorder\t: ";
  b->IterationMode(POSTORDER);

  for (auto i : *b) {
    cout << i << " ";
  }

  cout << endl << endl;

  cout << "Preorder\t: ";
  b->IterationMode(PREORDER);

  for (auto i : *b) {
    cout << i << " ";
  }

  cout << endl << endl;
  cout << endl;

  return 0;
}