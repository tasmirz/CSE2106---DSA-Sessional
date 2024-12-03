# Assignment 2

In our second lab, we learned about binary search and the time complexity of algorithms. In this assignment, we will update our previous array class and include some more functionalities.

# Instructions

1. **Method: Binary Search**  
   Develop a method, **int binary\_search(int value)**, designed to determine the index of a specified value within the array. If the value is present, the method should return the corresponding index; otherwise, it should return \-1. The method should throw an error if the array is not sorted.

2. **Method: Lower Bound**  
   Create a function named **int lower\_bound(int value)** to find the lower bound of a specified value within the array. This function should return the index of the first occurrence of value or the index of the smallest element greater than the value. If the value is less than the smallest element in the array or greater than the largest element in the array, the function should return \-1. The method should throw an error if the array is not sorted.

3. **Method: Upper Bound**  
   Construct a function named **int upper\_bound(int value)** to determine the upper bound of a given value within the array. This function should return the index of the smallest element greater than the value. If the value is greater than or equal to the largest element in the array, the function should return \-1. The method should throw an error if the array is not sorted.

4. **Method: One-Sided Binary Search**  
   Read about the binary search method discussed [here](https://www.geeksforgeeks.org/meta-binary-search-one-sided-binary-search/). Implement the function as a method for your class.  
     
5. **Time Complexity Questions**  
   Solve the problems about time complexity from [here](https://www.interviewbit.com/courses/programming/time-complexity/). Send a screenshot to prove that you solved all the problems.

# Submission

Each student should submit a C++ source file (.cpp) containing the additional functionalities of the  Array class. Rename your file as “Roll\_Assignment2.cpp”.

# Grading Criteria

- Correct implementation of each method.  
- Proper handling of edge cases (e.g., index out of bounds).  
- Clarity and structure of the code.  
- Effective demonstration of the array class through testing.

**Note: Feel free to reach out if you have any questions or need clarification.**

