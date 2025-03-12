
# C++ Arrays Notes

## 1. Introduction to Arrays (1st DS)
- An Array is a collection of elements of the same data type stored in contiguous memory locations.
- You can access elements using their position (index) ( 0 to size-1 )
- Array is linear
-  If you want to prevent modification of an array, use const.

### **Why Use Arrays?**
- Store multiple values under one variable name
- Efficient indexing and retrieval
- Better memory utilization compared to individual variables

---

## 2. Declaration and Initialization

### **Syntax:**
```cpp
 <datatype> arrayName[size];
```

### **Example:**
```cpp
 int arr[5]; // Declaration of an array of size 5
```

### **Initialization During Declaration:**
```cpp
 int arr[5] = {1, 2, 3, 4, 5};
 char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
```

### **Omitting Size:** : Letting the compiler determine the array size
```cpp
  int arr[] = {1, 2, 3, 4, 5}; // Size automatically determined as 5
```

---

## 3. Accessing and Modifying Array Elements
  Elements are accessed using **zero-based indexing**:
```cpp
cout << arr[0]; // Accessing the first element
arr[2] = 10;   // Modifying the third element
```

Looping through an array:
```cpp
  for(int i = 0; i < 5; i++) {
      cout << arr[i] << " ";
}
```

---

## 4. Types of Arrays

### **1D Arrays**
```cpp
int arr[3] = {10, 20, 30};
```

### **2D Arrays (Matrix Representation)**
```cpp
int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
```
Accessing elements:
```cpp
  cout << matrix[1][2]; // Outputs 6
```

### **3D Arrays**
```cpp
  int arr[2][2][3] = {{{1,2,3},{4,5,6}},{{7,8,9},{10,11,12}}};
```

---

## 5. Array Input from User
```cpp
int arr[5];
for(int i = 0; i < 5; i++) {
    cin >> arr[i];
}
```

---

## 6. Common Array Operations

### **Finding Maximum Element**
```cpp
int maxVal = arr[0];
for(int i = 1; i < size; i++) {
    if(arr[i] > maxVal) {
        maxVal = arr[i];
    }
}
```

### **Reversing an Array**
```cpp
for(int i = 0; i < size/2; i++) {
    swap(arr[i], arr[size - i - 1]);
}
```

### **Sorting an Array (Bubble Sort)**
```cpp
for(int i = 0; i < size-1; i++) {
    for(int j = 0; j < size-i-1; j++) {
        if(arr[j] > arr[j+1]) {
            swap(arr[j], arr[j+1]);
        }
    }
}
```

---

## 7. Multidimensional Array Traversal
### **2D Array Traversal**
```cpp
for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
        cout << matrix[i][j] << " ";
    }
    cout << endl;
}
```

---

## 8. Passing Arrays to Functions
 - When you pass an array to a function using int arr[] or int *arr, you are actually passing a pointer to the first element of the array.
 - The function does not create a copy of the entire array.
 - Any modifications inside the function will affect the original array.
```cpp
#include <iostream>
using namespace std;

void modifyArray(int arr[], int size) {
    arr[0] = 100;  // Modifying the first element
}
int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    modifyArray(numbers, 5);
    cout << "First element after modification: " << numbers[0] << endl; 
    return 0;
}
Output - First element after modification: 100

```
## 9.  Pass by Reference
 - When passing a single variable by reference using &, the function gets a reference to the original variable.
 - Any modifications made inside the function directly affect the original variable.
eg-  
#include <iostream>
using namespace std;
void modify(int &x) {  
    x = 100;  // Directly modifying the original variable
}
int main() {
    int num = 10;
    modify(num);
    cout << "Modified value: " << num << endl;  
    return 0;
}
Output - Modified value: 100



Calling the function:
```cpp
int arr[] = {1, 2, 3};
printArray(arr, 3);
```

---

##10. Linear Search

Linear search is a simple searching algorithm that checks each element in the array one by one.

Algorithm:
 - Start from the first element.
 - Compare each element with the target value.
 - If a match is found, return the index.
 - If the loop ends without finding the target, return -1.
 eg-
#include <iostream>
using namespace std;
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key)
            return i;  // Return index if found
    }
    return -1;  // Not found
}
int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 30;
    int result = linearSearch(arr, size, key);  
    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found" << endl;
    return 0;
}
Output - Element found at index: 2

Time Complexity:
 - Best case: O(1) (if the element is the first one).
 - Worst case: O(n) (if the element is at the end or not present).
 - Average case: O(n/2) ≈ O(n).

Use Cases:
✔ Useful for small datasets.
✔ Works with unsorted arrays.
✔ Simple and easy to implement.
---

---

## 10. Advantages and Disadvantages of Arrays
### **Advantages:**
- Fast access using indices
- Easy to implement
- Efficient for large amounts of data

### **Disadvantages:**
- Fixed size (static arrays)
- Insertion and deletion require shifting elements
- Uses contiguous memory

---

## 11. Alternative: Dynamic Arrays
```cpp
int* arr = new int[size];
// Use the array
delete[] arr; // Free memory
```

---

## Summary
✅ Arrays store multiple values in contiguous memory.
✅ Elements are accessed using indices starting from 0.
✅ Can be **1D, 2D, or multidimensional**.
✅ Used for efficient data storage and manipulation.
✅ Dynamic arrays allow flexible memory allocation.

This document provides a comprehensive guide to arrays in C++! 🚀
