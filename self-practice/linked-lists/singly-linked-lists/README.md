# Singly Linked List in C

This repository contains C implementations of a **Singly Linked List**, covering:

1. **Linked List Creation and Display**
2. **Insertion Operations**
3. **Deletion Operations**

The programs use dynamic memory allocation with `malloc()` and maintain the linked list using a `struct Node`.

---

## 1. Linked List Structure

All three programs use the following node structure:

```c
struct Node {
    int data;
    struct Node* next;
};
```

Each node contains:

- `data` — stores the value of the node.
- `next` — stores the address of the next node.

The last node points to `NULL`.

### Example

```text
10 -> 20 -> 30 -> NULL
```

---

# 2. Implementation — Creation and Display

The first program creates a singly linked list by inserting elements at the **end** of the list.

### Main Functions

### `create()`

```c
struct Node* create(struct Node* node, int data)
```

This function:

1. Dynamically allocates memory for a new node.
2. Stores the given data.
3. Sets `next` to `NULL`.
4. If the list is empty, the new node becomes the head.
5. Otherwise, it traverses to the last node and attaches the new node there.

### `display()`

```c
void display(struct Node* node)
```

This function traverses the entire list and prints every element.

Example output:

```text
10 -> 20 -> 30 -> NULL
```

### Time Complexity

| Operation | Time Complexity |
|---|---:|
| Create first node | `O(1)` |
| Insert a node using `create()` | `O(n)` |
| Create entire list of `n` nodes | `O(n²)` |
| Display | `O(n)` |
| Access/search by position | `O(n)` |

The `create()` function takes `O(n)` for each insertion because it traverses the list to find the last node. Therefore, creating `n` nodes using this approach takes:

```text
O(1 + 2 + 3 + ... + n) = O(n²)
```

---

# 3. Insertion

The second program demonstrates three types of insertion:

- Insertion at the beginning
- Insertion at the end
- Insertion at a specific position

It first creates the initial linked list and then performs the insertion operations.

---

## `insertAtBeginning()`

```c
void insertAtBeginning(struct Node** node, int data)
```

A new node is created and linked before the current head.

Before:

```text
10 -> 20 -> 30 -> NULL
```

After inserting `5`:

```text
5 -> 10 -> 20 -> 30 -> NULL
```

A **pointer to the head pointer** (`struct Node**`) is used because the head itself needs to be modified.

### Time Complexity

```text
O(1)
```

Only a few pointer operations are required.

---

## `insertAtEnd()`

```c
void insertAtEnd(struct Node** node, int data)
```

This function creates a new node and traverses the list until it reaches the last node. The new node is then attached to the end.

Before:

```text
10 -> 20 -> 30 -> NULL
```

After inserting `40`:

```text
10 -> 20 -> 30 -> 40 -> NULL
```

### Time Complexity

```text
O(n)
```

The list must be traversed to reach the last node.

> **Note:** If a tail pointer were maintained, insertion at the end could be performed in `O(1)` time.

---

## `insertAtPosition()`

```c
void insertAtPosition(struct Node** node, int data, int pos)
```

This function inserts a new node at a specified position.

For example, inserting `25` at position `3`:

Before:

```text
10 -> 20 -> 30 -> 40 -> NULL
```

After:

```text
10 -> 20 -> 25 -> 30 -> 40 -> NULL
```

The function traverses the list until it reaches the node immediately before the desired position.

### Time Complexity

```text
O(n)
```

In the worst case, the function may need to traverse almost the entire list.

---

## Insertion Complexity Summary

| Operation | Time Complexity |
|---|---:|
| Insert at beginning | `O(1)` |
| Insert at end | `O(n)` |
| Insert at position | `O(n)` |
| Display | `O(n)` |
| Initial list creation using `create()` | `O(n²)` |

---

# 4. Deletion

The third program demonstrates three types of deletion:

- Deletion from the beginning
- Deletion from the end
- Deletion from a specific position

---

## `deleteFromBeginning()`

```c
void deleteFromBeginning(struct Node** node)
```

The head is moved to the second node.

Before:

```text
10 -> 20 -> 30 -> NULL
```

After deleting the first node:

```text
20 -> 30 -> NULL
```

### Time Complexity

```text
O(1)
```

Only the head pointer needs to be changed.

---

## `deleteFromEnd()`

```c
void deleteFromEnd(struct Node** node)
```

This function traverses the list until it reaches the **second-last node**. Its `next` pointer is then changed to `NULL`.

Before:

```text
10 -> 20 -> 30 -> NULL
```

After deleting the last node:

```text
10 -> 20 -> NULL
```

### Time Complexity

```text
O(n)
```

The list must be traversed to find the second-last node.

---

## `deleteFromPosition()`

```c
void deleteFromPosition(struct Node** node, int pos)
```

This function deletes the node at a specified position.

For example, deleting position `2`:

Before:

```text
10 -> 20 -> 30 -> 40 -> NULL
```

After:

```text
10 -> 30 -> 40 -> NULL
```

The function traverses to the node before the target node and changes its `next` pointer.

### Time Complexity

```text
O(n)
```

In the worst case, traversal may be required almost until the end of the list.

---

## Deletion Complexity Summary

| Operation | Time Complexity |
|---|---:|
| Delete from beginning | `O(1)` |
| Delete from end | `O(n)` |
| Delete from position | `O(n)` |
| Display | `O(n)` |
| Initial list creation using `create()` | `O(n²)` |

---

# 5. Overall Time Complexity

The following table summarizes the main operations implemented in the programs.

| Operation | Time Complexity |
|---|---:|
| Create a node | `O(1)` |
| Create entire list using current `create()` | `O(n²)` |
| Display list | `O(n)` |
| Insert at beginning | `O(1)` |
| Insert at end | `O(n)` |
| Insert at position | `O(n)` |
| Delete from beginning | `O(1)` |
| Delete from end | `O(n)` |
| Delete from position | `O(n)` |

### Space Complexity

For a linked list containing `n` nodes:

```text
Space Complexity = O(n)
```

Each node requires memory for:

- One integer (`data`)
- One pointer (`next`)

---

# 6. Important Notes About the Current Code

The programs demonstrate the basic concepts of linked lists, but there are a few issues that should be corrected in a production-quality implementation.

### 1. Memory should be freed

When deleting a node, the removed node should be passed to `free()`.

For example:

```c
struct Node* temp = *node;
*node = (*node)->next;
free(temp);
```

Otherwise, the allocated memory remains occupied, resulting in a **memory leak**.

---

### 2. Empty-list checks should return

Some deletion functions print `"List is empty"` but continue executing.

For example:

```c
if (*node == NULL) {
    printf("List is empty\n");
}
```

The function should return afterward:

```c
if (*node == NULL) {
    printf("List is empty\n");
    return;
}
```

Otherwise, the function may dereference a `NULL` pointer.

---

### 3. Position `1` deletion needs special handling

When deleting the first node, the head should be updated to the next node rather than simply setting it to `NULL`.

Correct logic:

```c
if (pos == 1) {
    struct Node* temp = *node;
    *node = (*node)->next;
    free(temp);
    return;
}
```

---

### 4. Position validation

`insertAtPosition()` and `deleteFromPosition()` should check whether the requested position is valid.

For example:

```text
Position must be >= 1
Position must not exceed the number of nodes + 1 for insertion
Position must not exceed the number of nodes for deletion
```

---

### 5. `malloc()` should be checked

A robust implementation should check whether memory allocation succeeded:

```c
struct Node* newNode = malloc(sizeof(struct Node));

if (newNode == NULL) {
    printf("Memory allocation failed\n");
    return;
}
```

---

# 7. Concept Summary

A **singly linked list** is a dynamic data structure in which each node contains data and a pointer to the next node.

```text
       +------+------+
       | data | next |----+
       +------+------+    |
                           v
                       +------+------+
                       | data | next |----+
                       +------+------+    |
                                           v
                                       +------+------+
                                       | data | NULL |
                                       +------+------+
```

The main advantage of a linked list is that nodes can be inserted or deleted without shifting other elements.

### Advantages

- Dynamic size
- Efficient insertion/deletion at the beginning
- No need for contiguous memory
- Easy to grow and shrink during execution

### Disadvantages

- No direct/random access
- Extra memory required for pointers
- Traversal is required to find a particular position
- Insertion/deletion at the end is `O(n)` without a tail pointer

---

# 8. Compilation and Execution

If the files are saved as:

```text
implementation.c
insertion.c
deletion.c
```

Compile them using:

```bash
gcc implementation.c -o implementation
gcc insertion.c -o insertion
gcc deletion.c -o deletion
```

Run them using:

```bash
./implementation
./insertion
./deletion
```

On Windows, the generated executables can be run as:

```bash
implementation.exe
insertion.exe
deletion.exe
```

---

## Conclusion

These programs provide a basic implementation of a **Singly Linked List in C** and demonstrate:

- Creating nodes dynamically
- Creating and displaying a linked list
- Inserting nodes at different positions
- Deleting nodes from different positions
- Understanding the time complexity of linked-list operations

The most important complexity difference to remember is:

```text
Insert at beginning  -> O(1)
Insert at end        -> O(n)
Insert at position   -> O(n)

Delete from beginning -> O(1)
Delete from end       -> O(n)
Delete from position  -> O(n)

Display               -> O(n)
```

Using an additional **tail pointer** can make insertion at the end `O(1)`.