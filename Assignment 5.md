# Assignment 5

We learned about implementing stack and queue using linked list. In this assignment, we will implement a templated deque(double ended queue),queue and stack using a templated doubly linked list class in C++ and create a header file for the class. 

# Instructions:

1. # **Linked List Node:** Create a class named Node within the header file to represent a node in the linked list. The Node should have the following members:

   * A templated data member to store the value.  
     * A pointer to the next node.  
     * A pointer to the previous node.

2. **Deque Class**: Create a templated class named Deque  to represent a deque(double ended queue).   
   The class should have the following private members:  
* A pointer to the front of the deque.  
* A pointer to the head of the deque.


	Implement the following public methods for the Deque class:

* Deque(): Constructor to initialize the deque .  
* \~Deque(): Destructor to deallocate memory.  
* void p[ush\_front](https://cplusplus.com/reference/deque/deque/push_front/)(const T& value): Inserts a node with the given value at the front of the deque.  
* void [push\_back](https://cplusplus.com/reference/deque/deque/push_back/)(const T& value): Inserts a node with the given value at the end of the deque.  
* void [pop\_front](https://cplusplus.com/reference/deque/deque/pop_front/)(): Delete the node at the front of the deque.  
* void [pop\_](https://cplusplus.com/reference/deque/deque/pop_front/)back(): Delete the node at the end of the deque.  
* bool empty() const: Checks if the deque is empty. Returns true if found, false otherwise.  
* void () const: Displays the elements of the deque.  
* int size() const: Returns the size of the deque.

3. **Queue Class**: Create a templated class named Queue to represent a queue inheriting members and methods from the implemented Deque class.   
   The class should have the following private members:  
   * A pointer to the front of the queue.  
     * A pointer to the head of the queue.  
       

	Implement the following public methods for the Queue class:

* Queue (): Constructor to initialize the queue.  
* \~Queue (): Destructor to deallocate memory.  
* void [push](https://cplusplus.com/reference/deque/deque/push_back/)(const T& value): Inserts a node with the given value at the end of the queue.  
* void [pop](https://cplusplus.com/reference/deque/deque/pop_front/)(): Delete the oldest node.  
* bool empty() const: Checks if the queue is empty. Returns true if found, false otherwise.  
* void () const: Displays the elements of the queue.  
* int size() const: Returns the size of the queue.


4. **Stack Class**: Create a templated class named Stack to represent a stack inheriting members and methods from the implemented Deque class.   
   The class should have the following private member:  
   * A pointer to the top of the queue.  
     

	Implement the following public methods for the Stack class:

* Stack (): Constructor to initialize the stack.  
* \~Stack  (): Destructor to deallocate memory.  
* void [push](https://cplusplus.com/reference/deque/deque/push_back/)(const T& value): Inserts a node with the given value at the top of the stack.  
* void [pop](https://cplusplus.com/reference/deque/deque/pop_front/)(): Delete the node from top.  
* bool empty() const: Checks if the stack is empty. Returns true if found, false otherwise.  
* void () const: Displays the elements of the stack.  
* int size() const: Returns the size of the stack.

# Testing:

* Create an instance for each class for testing.  
  * Demonstrate the use of each method by performing operations.

# Submission:

* Each student should submit a C++ header file (.h) containing the implementation of the templated class. Rename the file as Roll\_assignment5.h.

# Grading Criteria:

* Correct implementation of each method in the classes.  
* Proper use of templates for the classes.  
* Effective demonstration of the class through testing.

**Note: Feel free to reach out if you have any questions or need clarification.**

