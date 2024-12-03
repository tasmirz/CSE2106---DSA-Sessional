

# Assignment 4

This time we will implement a Doubly Linked List class in C++ that includes various functions for insertion, deletion, and sorting. The class should be designed to handle templated data types.

# Instructions:

* ### Doubly Linked List Node (in the header file)   Create a struct named Node within the header file to represent a node in the doubly linked list. The Node struct should have:

  * ### A templated data member to store the value.

  * ### Pointers to the previous and next nodes.

    

* ### Doubly Linked List Class (in the header file)   Create a templated class named DoublyLinkedList to represent the doubly linked list. The class should have private members:

  * ### Pointers to the head and tail of the doubly linked list.

  * Properly implement constructors, destructors, and any other necessary functions.  
    

* ### Insertion Methods:   Implement the following insertion methods:

  * ### void insertBegin(const T& value): Inserts a node with the given value at the beginning of the doubly linked list.

  * void insertEnd(const T& value): Inserts a node with the given value at the end of the doubly linked list.  
  * void insertAtPosition(int position, const T& value): Inserts a node with the given value at the specified position in the doubly linked list.  
    

* ### Deletion Methods:   Implement the following deletion methods:

  * void deleteBegin(): Deletes the node at the beginning of the doubly linked list.  
  * void deleteEnd(): Deletes the node at the end of the doubly linked list.  
  * void deleteAtPosition(int position): Deletes the node at the specified position in the doubly linked list.  
  * void deleteByValue(const T& value): Deletes the node(s) with the specified value from the doubly linked list.  
    

* ### Sorting Methods:   Implement the following sorting methods:

  * void quickSort(): Performs the QuickSort algorithm on the doubly linked list.  
  * void mergeSort(): Performs the MergeSort algorithm on the doubly linked list.  
    

* ### Testing:   Create an instance of the DoublyLinkedList class for testing. Demonstrate the use of each insertion, deletion, and sorting method through various operations. Ensure that the sorting methods produce correctly sorted linked lists.


* ### Templatization:   Ensure that the doubly linked list class is templatized to store elements of any data type.


## Submission Each student should submit two C++ files for the assignment:

* ### A header file (.hpp) named Roll\_Assignment4.hpp containing the implementation of the templated doubly linked list class.

* ### A testing file (.cpp) named Roll\_Assignment4.cpp containing the main function for testing the doubly linked list class.

* ### Ensure that the header file includes all necessary declarations, and the testing file includes appropriate test cases to demonstrate the functionality of the doubly linked list class.

* ### Follow proper coding practices and organization in both files.

* ### Use comments in the testing file to explain the purpose of each test case.

* ### Zip both files into a single archive and submit the archive.


## Grading Criteria

* Correct implementation of each method in the doubly linked list class.  
* Proper use of templates for the doubly linked list class.  
* Proper handling of edge cases in insertion and deletion methods.  
* Correct implementation of the QuickSort and MergeSort algorithms.  
* Clear and concise code with proper comments.  
* Effective demonstration of the doubly linked list class through testing.

### **Note: Students are encouraged to reach out if they have any questions or need clarification.**

