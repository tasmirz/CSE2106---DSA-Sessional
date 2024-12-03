# Assignment 3

We learned about linked list creation and different insertion methods in our third lab. In this assignment, we will implement a templated linked list class in C++ and create a header file for the class.

# Instructions:

1. # **Linked List Node:** Create a struct named Node within the header file to represent a node in the linked list. The Node should have the following members:

   * A templated data member to store the value.  
     * A pointer to the next node.

2. **Linked List Class**: Create a templated class named LinkedList in the header file to represent a linked list. The class should have the following private members:  
   * A pointer to the head of the linked list.  
     * Properly implement constructors, destructors, and any other necessary functions.

3. **Public Methods**: Implement the following public methods for the LinkedList class:  
* LinkedList(): Constructor to initialize the linked list.  
* \~LinkedList(): Destructor to deallocate memory.  
* void insertFront(const T& value): Inserts a node with the given value at the front of the linked list.  
* void insertEnd(const T& value): Inserts a node with the given value at the end of the linked list.  
* void insertAtPosition(int position, const T& value): Inserts a node with the given value at the specified position in the linked list.  
* bool search(const T& value) const: Searches for a node with the specified value. Returns true if found, false otherwise.  
* void display() const: Displays the elements of the linked list.  
* int getLength() const: Returns the length of the linked list.

4. **Testing**:  
   * Create an instance of the LinkedList class for testing.  
   * Demonstrate the use of each method by performing operations such as inserting nodes at the front, at the end, and in any intermediate position, searching for nodes, and displaying the linked list.

5. **Templatization**:  
   * Ensure that the linked list class is templatized to store elements of any data type.

# Submission:

* Each student should submit a C++ header file (.h) containing the implementation of the templated linked list class. Rename the file as Roll\_assignment3.h.

# Grading Criteria:

* Correct implementation of each method in the linked list class.  
* Proper use of templates for the linked list class.  
* Proper handling of edge cases (e.g., position out of bound).  
* Clear and concise code with proper comments.  
* Effective demonstration of the linked list class through testing.

**Note: Feel free to reach out if you have any questions or need clarification.**

