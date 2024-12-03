**Assignment 6**  
We have learned about binary tree and binary search tree in lab. We will now build a templeted class for Binary tree and implement different methods to classify the tree.

# **Instructions:**

1. # **BinaryTree:** Create a class named BinaryTree to represent a node in the tree. The BinaryTree should have the following members:

   * A templated data member to store the value.  
     * A pointer to the left child.  
     * A pointer to the right child.  
     * A pointer to the parent.

Implement the following public methods for the class:

1. **Constructor:**  
   1. BinaryTree() : A one-time constructor, for constructing empty trees.  
   2. BinaryTree(E value): Constructs a tree node with no children.  
   3. BinaryTree(E value, BinaryTree\<E\> left, BinaryTree\<E\> right): Constructs a tree node with two children.  
2. **int height()** : Returns height of node in tree.  
3. **void setLeft(BinaryTree\<E\> newLeft):**  Update the left child of this node.  
4. **void setParent(BinaryTree\<E\> newParent):** Update the parent of this node.  
5.  **void setRight(BinaryTree\<E\> newRight):** Update the right child of this node.  
6.  **void setValue(E value):**  Set's value associated with this node.  
7. **Iterator\<E\> inorderIterator():**  Return an iterator to traverse the elements of subtree in-order.  
8. **Iterator\<E\> postorderIterator():** Return an iterator to traverse the elements of subtree in post-order.  
9.  **Iterator\<E\> preorderIterator():** Return an iterator to traverse nodes of subtree in-order.  
10.  **boolean isBalanced():**  Return true if the tree is height balanced(the height of the left and right subtrees of every node differs by at most one).  
11. **boolean isComplete():** Return whether tree is complete(all levels are completely filled except possibly the last level, which is filled from left to right).  
12. **isFull()**:  Returns true if tree is full(every node has either 0 or 2 children).  
13. **isBinarySearchTree():** Returns true if tree is Binary Search Tree.  
14. **BinaryTree\<E\> balance\_tree(BinaryTree\<E\> Root):** Balance an unbalanced binary search tree (rearrange the tree nodes to ensure it is balanced) and return the new root of the balanced tree.

**Testing:**

1. Provide sample binary trees to test the implementations.  
2. Create instances of the BinaryTree class, populate them with nodes, and apply the methods to determine the properties of the trees.

# **Submission:**

Each student should submit a C++ main file (.cpp) containing the implementation of the templated BinaryTree class and the testing instances. Rename the file as Roll\_assignment6.cpp.

# **Grading Criteria:**

* Correct implementation of each method in the class.  
* Proper use of templates for the class.  
* Effective demonstration of the class through testing.

**Note: Feel free to reach out if you have any questions or need clarification.**