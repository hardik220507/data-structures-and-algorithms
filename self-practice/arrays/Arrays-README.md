# Arrays — C Practice

This folder contains my basic practice and implementations of arrays in C.

The purpose of this practice is to understand how arrays are created, accessed, traversed, modified, and managed in memory, including Dynamic Memory Allocation (DMA).

## Programs Covered

### 1. Array Creation

The basic implementation covers:
- Taking the number of elements from the user
- Creating an array
- Taking input for each element
- Printing the array

**Time Complexity:** `O(n)` for input/traversal  
**Space Complexity:** `O(n)` for storing the array

### 2. Array Creation Using DMA

This implementation uses `malloc()` to allocate memory dynamically:

```c
int *arr = malloc(sizeof(int) * n);
```

The allocated memory is released using:

```c
free(arr);
```

**Time Complexity:** `O(n)` overall for allocation/input/traversal  
**Space Complexity:** `O(n)`

### 3. Traversal

Traversal visits every element of the array once.

```c
for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
}
```

**Time Complexity:** `O(n)`  
**Space Complexity:** `O(1)` auxiliary space

### 4. Insertion

The insertion program inserts an element at a specified position. Elements after that position are shifted one position to the right.

Example:

```text
Before: [10 20 30 40]
Insert 25 at position 2
After:  [10 20 25 30 40]
```

**Time Complexity:**
- Beginning: `O(n)`
- Middle: `O(n)`
- End: `O(1)` if sufficient capacity exists

The current implementation creates a second array, so its **additional space complexity is `O(n)`**.

### 5. Deletion

The deletion program removes an element from a specified position. Elements after that position are shifted one position to the left.

Example:

```text
Before: [10 20 30 40 50]
Delete position 2
After:  [10 20 40 50]
```

**Time Complexity:**
- Beginning: `O(n)`
- Middle: `O(n)`
- End: `O(1)`

**Space Complexity:** `O(1)` auxiliary space

## Concepts Practiced

- Array declaration and initialization
- Array indexing
- Array traversal
- Pointer arithmetic
- Passing arrays to functions
- Insertion and deletion
- Dynamic Memory Allocation
- `malloc()` and `free()`
- Time and space complexity

## Array Indexing and Pointer Arithmetic

These are equivalent:

```c
arr[i]
```

and:

```c
*(arr + i)
```

Understanding this relationship is important when learning arrays and pointers in C.

## Further Practice

The programs above are a **good starting point, but not sufficient for complete array practice**.

Before considering the array topic complete, I should also practice:

### Searching
- Linear Search
- Binary Search

### Basic Operations
- Update an element at a given index
- Find maximum and minimum elements
- Find sum and average
- Count even and odd elements
- Count positive, negative, and zero elements
- Find the frequency of an element

### Array Manipulation
- Reverse an array
- Copy an array
- Merge two arrays
- Remove duplicate elements
- Find the second largest element
- Check whether an array is sorted
- Rotate an array left/right

### Problem-Solving Practice
- Find duplicate elements
- Find a missing number
- Find pairs with a given sum
- Find the largest/second-largest element
- Find the intersection of two arrays

## Complexity Summary

| Operation | Best Case | Worst Case |
| --- | ---: | ---: |
| Access by index | `O(1)` | `O(1)` |
| Traversal | `O(n)` | `O(n)` |
| Linear Search | `O(1)` | `O(n)` |
| Binary Search* | `O(1)` | `O(log n)` |
| Insertion | `O(1)`* | `O(n)` |
| Deletion | `O(1)`* | `O(n)` |

> *Binary search requires a sorted array. Insertion/deletion at the end can be `O(1)` when sufficient capacity exists.

## Goal

The goal is not just to memorize array operations, but to understand:

1. How arrays are stored in memory
2. How indexing works
3. The relationship between arrays and pointers
4. How insertion and deletion affect elements
5. How dynamic memory allocation works
6. The time and space complexity of common operations

> **Understand the implementation → Analyze the complexity → Practice problems → Build problem-solving ability**
