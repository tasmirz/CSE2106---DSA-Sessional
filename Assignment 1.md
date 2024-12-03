# Assignment 1

In the first class, we learned about different operations we can perform on an array. In this assignment, we will try to reinforce our understanding of basic array operations by implementing a custom array class in C++.

# Instructions:

1. **Class Definition**  
   Create a C++ class named Array to represent an array. The class should have the following private members:

   ***int size***: An integer representing the size of the array.

   ***int \*arr***: An integer pointer to dynamically allocate memory for storing the elements of the array.

   

2. **Constructor**  
   Implement a constructor to initialize the array size and dynamically allocate memory for the array.  
     
3. **Method: Create Array**   
   Implement a method **void createArray(int size)** to initialize an array of a given size with default values (e.g., zeros).

4. **Method: Insert Element**  
   Implement a method **void insertElement(int index, int value)** to insert an element at a specified index in the array. Ensure that the array size is updated accordingly.  
     
5. **Method: Delete Element**  
   Implement a method **void deleteElement(int index)** to remove an element at a specified index from the array. Make sure to shift the remaining elements to fill the gap.

6. **Method: Search Element**  
   Implement a method **int searchElement(int value)** to search for a specified value in the array. Return the index if the element is found; otherwise, return \-1.

7. **Method: Traverse Array**  
   Implement a method **void traverseArray()** to print all elements in the array.

8. **Testing**:  
   Create an instance of the Array class. Demonstrate the use of each method by performing operations such as creating an array, inserting/deleting elements, searching for elements, and traversing the array.

9. **Additional Features (Optional)**: Add additional features to the Array class, such as updating an element at a specific index or resizing the array.

# Submission

Each student should submit a C++ source file (.cpp) containing the implemented Array class and a demonstration of its functionality. Rename your file as “Roll\_Assignment1.cpp”.

# Grading Criteria

- Correct implementation of each method.  
- Proper handling of edge cases (e.g., index out of bounds).  
- Clarity and structure of the code.  
- Effective demonstration of the array class through testing.

**Note: Feel free to reach out if you have any questions or need clarification.**  
