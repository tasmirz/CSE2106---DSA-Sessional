**Assignment 7**  
We have learned about heap and priority queue in lab. We will now build a templated class for Priority Queue using Heap and implement different methods for the class.

**Instructions:**

1. **PriorityQueue:** Create a class named PriorityQueue to represent a node in the tree. The PriorityQueue should have the following members:  
   * A templated vector to store the value.  
     * Comparator: if true then stores in ascending order else in descending order.

Implement the following public methods for the class:

1. **Constructor:** Creates a initial empty priority queue.  
2. **top():** accesses the top element.  
3. **empty():** checks whether the container adaptor is empty.  
4. **size():** returns the number of elements.  
5. **push():** inserts element and sorts the underlying container.  
6. **pop():** removes the top element.

2\. **Linked List Node:** Create a class named Node within the header file to represent a node in the linked list. The Node should have the following members:

* A templated data member to store the value.  
  * A pointer to the next node.  
    * A pointer to the previous node.

Implement Priority Queue and the mentioned methods using the Linked List.

3\. Compare Time and Space complexities of these 2 different implementations of Priority Queue.

**Testing:**

1. Provide sample **priority queues with both values associated with priority factor** to test the implementations.  
2. Create instances of the classes, and apply the methods to show its functionalities.

**Submission:**

Each student should submit a C++ main file (.cpp) containing the implementation of the templated PriorityQueue class and the testing instances. Rename the file as Roll\_assignment7.cpp.

**Grading Criteria:**

* Correct implementation of each method in the class.  
* Proper use of templates for the class.  
* Effective demonstration of the class through testing.

**Note: Feel free to reach out if you have any questions or need clarification.**

